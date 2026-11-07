"""
Basic.ipynb 的可复用部分：导入、工具函数、基础图像。

用法（在 Limit.ipynb 等其它 notebook 里）：

    %run basic_setup.py

然后就可以直接用 img、img_gray、cv_show()。

注意：不要用 %run Basic.ipynb —— 那会把整个教程从头重跑一遍，
其中 cv_show() 里的 cv2.waitKey(0) 会无限等待按键，导致卡死。
"""

import os

import cv2
import matplotlib.pyplot as plt
import numpy as np

# 图片目录：优先按本文件位置推算，取不到就用当前工作目录
try:
    BASE_DIR = os.path.dirname(os.path.abspath(__file__))
except NameError:
    BASE_DIR = os.getcwd()


def find_image(name):
    """找图片：仓库根目录和 images/ 子目录都试一遍，找不到就返回根目录路径让断言报错。"""
    for d in (BASE_DIR, os.path.join(BASE_DIR, "images")):
        p = os.path.join(d, name)
        if os.path.exists(p):
            return p
    return os.path.join(BASE_DIR, name)


def cv_show(name, img, delay=0):
    """用 OpenCV 原生窗口显示图像。

    delay=0  按任意键关闭（必须在图像窗口里按键，在编辑器里按不算）
    delay>0  毫秒后自动关闭，比如 cv_show('cat', img, 1000)
    """
    cv2.imshow(name, img)
    cv2.waitKey(delay)
    cv2.destroyAllWindows()


# ---- 基础图像 ----
img = cv2.imread(find_image("cat.jpg"))                       # 彩色 BGR
img_gray = cv2.imread(find_image("cat.jpg"), cv2.IMREAD_GRAYSCALE)   # 单通道灰度

assert img is not None, f"读取失败，请检查路径: {find_image('cat.jpg')}"
assert img_gray is not None, "灰度图读取失败"

if __name__ == "__main__":
    print("img      :", img.shape, img.dtype)
    print("img_gray :", img_gray.shape, img_gray.dtype)
