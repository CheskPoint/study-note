Sobel X算子（Sobel X Operator）主要用于检测图像中的垂直边缘，通过计算图像在水平方向（X方向）的灰度变化，找出灰度变化较大的位置。
## 1. Sobel X 算子的作用

Sobel X 使用一个 $(3\times3)$ 的卷积核：

$G_x=\begin{bmatrix} -1&0&1\\ -2&0&2\\ -1&0&1 \end{bmatrix}$

工作原理是：
	检测水平方向的灰度变化：比较像素左右两侧的亮度差异。
	突出垂直边缘：例如图像中物体左右两侧的轮廓。
	抑制部分噪声：利用上下相邻像素的加权计算，具有一定平滑作用。
	SobelX检测的是垂直边缘
	![](data:image/svg+xml;charset=utf-8,%3Csvg%20font-family%3D%22-apple-system-body%2C%20ui-sans-serif%2C%20-apple-system%2C%20system-ui%2C%20%26quot%3BSegoe%20UI%26quot%3B%2C%20Helvetica%2C%20%26quot%3BApple%20Color%20Emoji%26quot%3B%2C%20Arial%2C%20sans-serif%2C%20%26quot%3BSegoe%20UI%20Emoji%26quot%3B%2C%20%26quot%3BSegoe%20UI%20Symbol%26quot%3B%22%20font-weight%3D%22400%22%20data-d-component%3D%22svg%22%20fill%3D%22currentColor%22%20style%3D%22color%3Argb\(237%2C%20237%2C%20237\)%22%20viewBox%3D%220%200%20160%20110%22%20width%3D%22100%25%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Crect%20x%3D%228%22%20y%3D%225%22%20width%3D%22144%22%20height%3D%22100%22%20fill%3D%22%23222%22%2F%3E%3Crect%20x%3D%2280%22%20y%3D%225%22%20width%3D%2272%22%20height%3D%22100%22%20fill%3D%22%23e7e7e7%22%2F%3E%3Cpath%20d%3D%22M80%205%20V105%22%20stroke%3D%22%23e95757%22%20stroke-width%3D%223%22%20stroke-dasharray%3D%225%203%22%2F%3E%3Cpath%20d%3D%22M38%2055%20H120%22%20stroke%3D%22%233795ef%22%20stroke-width%3D%222%22%2F%3E%3Cpath%20d%3D%22M114%2049%20L121%2055%20L114%2061%22%20fill%3D%22none%22%20stroke%3D%22%233795ef%22%20stroke-width%3D%222%22%2F%3E%3C%2Fsvg%3E)![](data:image/svg+xml;charset=utf-8,%3Csvg%20font-family%3D%22-apple-system-body%2C%20ui-sans-serif%2C%20-apple-system%2C%20system-ui%2C%20%26quot%3BSegoe%20UI%26quot%3B%2C%20Helvetica%2C%20%26quot%3BApple%20Color%20Emoji%26quot%3B%2C%20Arial%2C%20sans-serif%2C%20%26quot%3BSegoe%20UI%20Emoji%26quot%3B%2C%20%26quot%3BSegoe%20UI%20Symbol%26quot%3B%22%20font-weight%3D%22400%22%20data-d-component%3D%22svg%22%20fill%3D%22currentColor%22%20style%3D%22color%3Argb\(237%2C%20237%2C%20237\)%22%20viewBox%3D%220%200%20160%20110%22%20width%3D%22100%25%22%20xmlns%3D%22http%3A%2F%2Fwww.w3.org%2F2000%2Fsvg%22%3E%3Crect%20x%3D%228%22%20y%3D%225%22%20width%3D%22144%22%20height%3D%22100%22%20fill%3D%22%23161616%22%2F%3E%3Crect%20x%3D%2277%22%20y%3D%225%22%20width%3D%226%22%20height%3D%22100%22%20fill%3D%22%23fafafa%22%2F%3E%3C%2Fsvg%3E)
因为X方向是从左到右，当图像左右两侧的灰度变化很大时，就意味着存在一条垂直方向的边界
算子          计算的灰度变化方向        主要检测的边缘
SobeX       水平方向                         垂直边缘
SobeY       垂直方向                         水平边缘
（右边--左边）
Sobel算子通过让灰度变化小的区域趋近于0（黑色），让灰度变化大的边缘呈现较高的数值（更亮），从而突出边缘。但它不是直接把原图周围的颜色调暗，而是根据相邻像素的灰度差，重新计算每个像素的数值。
假设原图已经转换为灰度图，像素值范围为0～255：
原始图像：左边灰度50，右边灰度200
![[Pasted image 20261029094637.png]]
可以看到：
- 原来灰度50的平坦区域 → 0
- 原来灰度200的平坦区域 → 0
- 灰度从50突变到200的边缘 → 255
Sobel X 使用卷积核：
$\begin{bmatrix} -1&0&1\\ -2&0&2\\ -1&0&1 \end{bmatrix}$
对于上面50到200的边界，计算得到：
$[ G_x=4(200-50)=600 ]$
由于600超过255，经过cv2.convertScaleAbs( )后变为255。
而灰度不变化的区域，梯度为0，所以显示为黑色。
Sobel 处理后的0～255表示的是边缘梯度强度，而不是原来的颜色深浅。
 0：没有检测到灰度变化，显示黑色。
- 1～254：有一定灰度变化，显示不同程度的灰色
- 255：梯度较强，显示白色
注意：这里的255也可能是较大梯度被截断后的结果。
所以，Sobel的本质是压低平坦区域的响应、突出灰度突变的位置，而不是简单地对原图进行调亮或调暗。

cv2.convertScaleAbs( )用于将图像数据取绝对值，并转换为8位无符号整数（0～255）
在 Sobel 算子中，主要作用是：
	取绝对值：将负梯度变为正数。
	转换数据类型：将结果转换为uint8。
	限制数值范围：超过255的值截断为255。

## 2.图像梯度
图像梯度--Scharr X：检测垂直边缘

$G_x=\begin{bmatrix} -3&0&3\\ -10&0&10\\ -3&0&3 \end{bmatrix}$

Scharr Y：检测水平边缘

$G_y=\begin{bmatrix} -3&-10&-3\\ 0&0&0\\ 3&10&3 \end{bmatrix}$

图像梯度--Laplacian
    Laplacian 算子是一种二阶导数边缘检测算子，通过计算像素灰度变化的变化程度，检测图像中的边缘。与Sobel、Scharr不同，Laplacian 同时考虑X和Y两个方向，不需要分别计算水平和垂直梯度。
  
常见的3×3Laplacian卷积核为：
$K=\begin{bmatrix} 0&1&0\\ 1&-4&1\\ 0&1&0 \end{bmatrix}$

它的计算方式是：
将一个像素上下左右的灰度值相加，再减去中心像素灰度值的4倍。
$G=上+下+左+右-4\times中心$


## 3.Canny边缘检测
通过计算图像的灰度变化，去除噪声和无效边缘，最终提取出较细且连续的物体轮廓
Canny最终输出的是二值边缘图像，只有两个灰度值：
  0：不是最终保留的边缘
 255：被判定为边缘
 ![[Pasted image 20261029231153.png]]
 双阈值检测：
threshold1 = 50
threshold2 = 150
梯度强度                 处理方式
小于50                    抑制，不保留
50～150                 弱边缘，需要进一步判断
大于150                  强边缘，保留

高斯滤波器：高斯滤波器通过对中心像素及其周围像素进行加权平均，重新计算中心像素的灰度值。
特点是：距离中心越近，权重通常越大；距离中心越远，权重越小；所有权重相加等于1
一个常见的3×3近似高斯滤波核：

$K=\frac{1}{16} \begin{bmatrix} 1&2&1\\ 2&4&2\\ 1&2&1 \end{bmatrix}$
![[Pasted image 20261029231943.png]]
中心像素的计算：

$$ G=\frac{250\times4+50\times12}{16}=100 $$
图像灰度矩阵：

$A= \begin{bmatrix} a_{11}&a_{12}&a_{13}\\ a_{21}&a_{22}&a_{23}\\ a_{31}&a_{32}&a_{33} \end{bmatrix}$

高斯滤波核：

$H= \begin{bmatrix} h_{11}&h_{12}&h_{13}\\ h_{21}&h_{22}&h_{23}\\ h_{31}&h_{32}&h_{33} \end{bmatrix}$

$sum = H\odot A= \begin{bmatrix} h_{11}a_{11}&h_{12}a_{12}&h_{13}a_{13}\\ h_{21}a_{21}&h_{22}a_{22}&h_{23}a_{23}\\ h_{31}a_{31}&h_{32}a_{32}&h_{33}a_{33} \end{bmatrix}$

梯度幅值（梯度大小）
${G=\sqrt{G_x^2+G_y^2}}$
梯度方向
${\theta=\operatorname{atan2}(G_y,G_x)}$
梯度计算：(S为Sobel算子)
$G_x=S_x*A$
$G_y=S_y*A$

非极大值抑制：非极大值抑制的作用是去除边缘附近多余的梯度响应，只保留梯度方向上的局部最大值，使检测到的边缘变细
梯度幅值：
$G=\sqrt{G_x^2+G_y^2}$
梯度方向：
$\theta=\operatorname{atan2}(G_y,G_x)$
![[Pasted image 20261102230654.png]]\[ ${ N(x,y)= \begin{cases} G(x,y),&G(x,y)\geq G_1\text{ 且 }G(x,y)\geq G_2\\ 0,&\text{其他情况} \end{cases} }$

双阈值检测
梯度值>maxVal：则处理为边界
minVal<梯度值<maxVal：连接有边界则保留，否则舍弃
梯度值<minVal：则舍弃

## 4.模式匹配
![[Pasted image 20261107234122.png]]
![[Pasted image 20261107234148.png]]

## 5.图像金字塔
![[Pasted image 20261108233311.png]]
高斯金字塔：
高斯金字塔通过高斯滤波和下采样，逐层缩小图像。
处理过程：原始图像 → 高斯滤波 → 下采样 → 得到下一层图像。
数学表达式：
${G_{k+1}=\downarrow_2(H*G_k)}$
其中：
 $G_k$：当前层图像。
 $H$：高斯滤波核。
 $*$：卷积操作。
$downarrow_2$：宽和高方向各下采样2倍

拉普拉斯金字塔：
拉普拉斯金字塔用于保存相邻高斯金字塔层之间的细节差异。
公式：
${L_k=G_k-\operatorname{pyrUp}(G_{k+1})}$
其中：
 $L_k$：第k层拉普拉斯金字塔图像。
$G_k$：当前层高斯图像。
$G_{k+1}$：下一层高斯图像。
$\operatorname{pyrUp}$：上采样到当前层尺寸。
拉普拉斯金字塔常用于图像融合、压缩与重建

![[Pasted image 20261108233709.png]]