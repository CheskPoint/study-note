import torch
import torchvision
import torchaudio

# 1. 版本信息
print(f"PyTorch 版本: {torch.__version__}")
print(f"torchvision 版本: {torchvision.__version__}")
print(f"torchaudio 版本: {torchaudio.__version__}")

# 2. CUDA 检测（CPU版显示False为正常）
print(f"CUDA 是否可用: {torch.cuda.is_available()}")

# 3. 基础张量运算
x = torch.tensor([[1, 2], [3, 4]])
y = torch.tensor([[5, 6], [7, 8]])
print("\n张量相加结果:")
print(x + y)

print("\n✅ PyTorch 环境测试通过！")
