# -*- coding: utf-8 -*-
"""
把 1.docx 里的正文抽出来，做中文分词后绘制词云图。

依赖：
    pip install python-docx jieba wordcloud matplotlib

用法：
    python docx_wordcloud.py                       # 默认读 1.docx，输出 wordcloud.png
    python docx_wordcloud.py 你的文件.docx 输出.png
"""

import os
import re
import sys
from collections import Counter

import matplotlib

matplotlib.use("Agg")  # 无界面环境下也能出图
import matplotlib.pyplot as plt
from matplotlib import font_manager

from wordcloud import WordCloud

# ----------------------------------------------------------------------------
# 0. 参数配置
# ----------------------------------------------------------------------------
DOCX_PATH = sys.argv[1] if len(sys.argv) > 1 else "1.docx"
OUT_PNG = sys.argv[2] if len(sys.argv) > 2 else "wordcloud.png"

# 中文字体：词云库不会自动处理中文，必须显式给字体文件
FONT_CANDIDATES = [
    r"C:\Windows\Fonts\msyh.ttc",    # 微软雅黑
    r"C:\Windows\Fonts\simhei.ttf",  # 黑体
    r"/System/Library/Fonts/PingFang.ttc",  # macOS
    r"/usr/share/fonts/truetype/wqy/wqy-zenhei.ttc",  # Linux
]


def pick_font() -> str:
    for path in FONT_CANDIDATES:
        if os.path.exists(path):
            return path
    # 退路：让 matplotlib 自己找一个可用的中文字体
    for name in ("Microsoft YaHei", "SimHei", "PingFang SC", "WenQuanYi Zen Hei"):
        try:
            return font_manager.findfont(name, fallback_to_default=False)
        except Exception:
            continue
    raise RuntimeError("找不到可用的中文字体，请修改 FONT_CANDIDATES")


# 停用词：中文虚词 + 论文套话 + 符号数字等
STOPWORDS = set("""
的 了 和 与 及 或 在 是 为 对 以 将 被 把 从 到 中 上 下 内 外 之 其 该 此 这 那 有 无 不 也 还 并
我们 本文 本 文 研究 进行 通过 基于 利用 采用 使用 提出 实现 构建 得到 表明 结果 因此 然而 并且
可以 能够 已经 成为 具有 存在 问题 情况 方面 方式 方法 手段 过程 体系 依据 路径 提高 提升 明显
一个 一种 一套 一起 其中 以及 同时 进一步 从而 旨在 针对 由于 因为 所以 属于 主要 重要 显著
涵盖 形成 相较 连接 落地 可言 之一 普遍 通常 直接 极易 导致 呈现 取得 提供 清晰 得到 其中
""".split())

# 想额外保留 / 合并的专业短语（数字与英文缩写默认会被过滤，这里单独加固）
CUSTOM_WORDS = [
    "心血管疾病", "非传染性疾病", "机器学习", "数据增强", "数据预处理", "类别不平衡",
    "随机森林", "逻辑回归", "朴素贝叶斯", "支持向量机", "决策树", "过采样", "欠采样",
    "消融实验", "风险预测", "风险筛查", "辅助决策", "参数配置", "模型选型", "漏诊率",
    "自评健康", "基础疾病", "健康调查", "临床辅助", "实验体系", "对比实验",
]


# ----------------------------------------------------------------------------
# 1. 读取 docx 文本
# ----------------------------------------------------------------------------
def read_docx_text(path: str) -> str:
    """优先用 python-docx；没有装就退回到直接解析 docx 里的 document.xml。"""
    try:
        import docx  # python-docx

        doc = docx.Document(path)
        parts = [p.text for p in doc.paragraphs]
        # 表格里的文字也别漏掉
        for table in doc.tables:
            for row in table.rows:
                for cell in row.cells:
                    parts.append(cell.text)
        return "\n".join(parts)
    except ImportError:
        import xml.etree.ElementTree as ET
        import zipfile

        ns = "{http://schemas.openxmlformats.org/wordprocessingml/2006/main}"
        with zipfile.ZipFile(path) as zf:
            xml = zf.read("word/document.xml")
        root = ET.fromstring(xml)
        lines = []
        for para in root.iter(ns + "p"):
            lines.append("".join(t.text or "" for t in para.iter(ns + "t")))
        return "\n".join(lines)


# ----------------------------------------------------------------------------
# 2. 中文分词 + 清洗
# ----------------------------------------------------------------------------
def tokenize(text: str) -> Counter:
    import jieba

    for w in CUSTOM_WORDS:
        jieba.add_word(w, freq=10000)  # 保证专业词不被切碎

    tokens = []
    for word in jieba.cut(text):
        word = word.strip()
        if not word or word in STOPWORDS:
            continue
        # 丢掉纯标点 / 纯数字 / 空白 / 单字（单字做词云信息量太低，可注释掉下面一行保留）
        if re.fullmatch(r"[\W_]+", word) or re.fullmatch(r"\d+(\.\d+)?%?", word):
            continue
        if len(word) < 2:
            continue
        tokens.append(word)

    return Counter(tokens)


# ----------------------------------------------------------------------------
# 3. 画词云
# ----------------------------------------------------------------------------
def draw(freq: Counter, font_path: str, out_png: str) -> None:
    wc = WordCloud(
        font_path=font_path,          # 关键：中文字体
        width=1600,
        height=1000,
        background_color="white",
        max_words=120,
        colormap="viridis",
        prefer_horizontal=0.9,        # 中文竖排难看，尽量横向
        min_font_size=10,
        max_font_size=180,
        collocations=False,           # 中文已分词，关掉 bigram 组合
        random_state=42,
    ).generate_from_frequencies(freq)

    fig, ax = plt.subplots(figsize=(16, 10), dpi=150)
    ax.imshow(wc, interpolation="bilinear")
    ax.axis("off")
    fig.tight_layout(pad=0)
    fig.savefig(out_png, dpi=150, bbox_inches="tight", facecolor="white")
    plt.close(fig)


def main() -> None:
    if not os.path.exists(DOCX_PATH):
        raise SystemExit(f"找不到文件：{DOCX_PATH}")

    text = read_docx_text(DOCX_PATH)
    print(f"读入正文 {len(text)} 字")

    freq = tokenize(text)
    if not freq:
        raise SystemExit("分词结果为空，请检查文本或停用词表")

    print(f"有效词 {len(freq)} 个，词频 Top20：")
    for word, count in freq.most_common(20):
        print(f"  {word:<12}{count}")

    font_path = pick_font()
    draw(freq, font_path, OUT_PNG)
    print(f"词云已保存：{os.path.abspath(OUT_PNG)}（字体：{font_path}）")


if __name__ == "__main__":
    main()