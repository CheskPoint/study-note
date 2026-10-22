import base64
from io import BytesIO
from pathlib import Path
from threading import Lock

from PIL import Image, ImageOps
from ultralytics import YOLO

from app.db import CLASSES


MODEL_PATH = (
    Path(__file__).resolve().parents[2] / "models" / "best.pt"
)

# 后端启动时加载一次，不要每次检测都重新加载。
model = YOLO(str(MODEL_PATH))
MODEL_CLASSES = [model.names[key] for key in sorted(model.names)]
if model.task != "detect" or MODEL_CLASSES != list(CLASSES):
    raise RuntimeError("部署权重的任务或类别与系统配置不一致。")
model_lock = Lock()
INFERENCE_DEVICE = "cpu"
INFERENCE_IMAGE_SIZE = 640


def get_model_info() -> dict:
    return {
        "model_name": MODEL_PATH.name,
        "classes": MODEL_CLASSES,
        "device": INFERENCE_DEVICE,
        "image_size": INFERENCE_IMAGE_SIZE,
    }


def run_inference(content: bytes, threshold: float) -> dict:
    # 将上传的图片解码，并处理照片方向。
    with Image.open(BytesIO(content)) as uploaded:
        image = ImageOps.exif_transpose(uploaded).convert("RGB")

    # 先用 CPU 跑通流程，有 NVIDIA GPU 后再调整。
    with model_lock:
        result = model.predict(
            source=image,
            imgsz=INFERENCE_IMAGE_SIZE,
            conf=threshold,
            device=INFERENCE_DEVICE,
            verbose=False,
        )[0]

        detections = []

        for box in result.boxes:
            class_id = int(box.cls.item())
            detections.append({
                "class_id": class_id,
                "class_name": result.names[class_id],
                "confidence": float(box.conf.item()),
                "bbox": box.xyxy[0].cpu().tolist(),
            })

        # plot() 返回 BGR 图像，转换为 RGB 后生成图片。
        annotated_bgr = result.plot()

    annotated_rgb = annotated_bgr[:, :, ::-1]
    buffer = BytesIO()

    Image.fromarray(annotated_rgb).save(
        buffer,
        format="JPEG",
        quality=90,
    )

    image_base64 = base64.b64encode(
        buffer.getvalue()
    ).decode("ascii")

    return {
        "model": MODEL_PATH.name,
        "model_classes": MODEL_CLASSES,
        "count": len(detections),
        "detections": detections,
        "image_width": image.width,
        "image_height": image.height,
        "annotated_image": (
            "data:image/jpeg;base64," + image_base64
        ),
    }
