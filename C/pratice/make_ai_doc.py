# -*- coding: utf-8 -*-
# 运行：python make_ai_doc.py
# 生成：AI工具使用说明模板.doc

html = """<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>2026年全国大学生数学建模竞赛 AI工具使用说明模板</title>
<style>
body { font-family: "宋体", SimSun, serif; font-size: 12pt; line-height: 1.7; margin: 40px; }
h1 { font-size: 18pt; text-align: center; font-family: "黑体", SimHei; }
h2 { font-size: 15pt; font-family: "黑体", SimHei; margin-top: 24px; }
h3 { font-size: 13pt; font-family: "黑体", SimHei; margin-top: 18px; }
table { border-collapse: collapse; width: 100%; margin: 10px 0; }
th, td { border: 1px solid #000; padding: 6px; font-size: 11pt; vertical-align: top; }
th { background: #f0f0f0; text-align: center; }
blockquote { margin-left: 24px; color: #333; border-left: 3px solid #999; padding-left: 12px; }
.note { color: #444; font-size: 11pt; }
.sign { margin-top: 30px; }
</style>
</head>
<body>

<h1>2026年全国大学生数学建模竞赛<br>AI工具使用说明模板</h1>

<h2>一、AI工具使用声明（置于论文参考文献之前）</h2>
<p>根据2026年全国大学生数学建模竞赛相关要求，参赛队须在论文参考文献之前设置“AI工具使用声明”，二者择一：</p>

<h3>情形一：未使用AI工具</h3>
<blockquote>本参赛队在竞赛过程中未使用任何AI工具。</blockquote>

<h3>情形二：使用AI工具</h3>
<blockquote>
本参赛队在竞赛过程中使用了AI工具，主要用于__________（填写简要用途，如语言润色、代码调试、数据清洗等），详细使用情况见支撑材料。
</blockquote>

<h2>二、AI工具使用详情说明（支撑材料，PDF格式）</h2>
<p><b>文件命名要求：</b>AI工具使用详情.pdf</p>
<p>使用AI工具的参赛作品须在支撑材料中提交本说明，内容应包含以下四个部分。</p>

<h3>第一部分：AI工具清单</h3>
<table>
<tr>
<th>序号</th><th>工具名称</th><th>版本/型号</th><th>开发机构</th><th>主要用途</th>
</tr>
<tr>
<td>1</td><td>（如：ChatGPT）</td><td>（如：GPT-4o）</td><td>（如：OpenAI）</td><td>（如：代码调试）</td>
</tr>
<tr><td>2</td><td></td><td></td><td></td><td></td></tr>
<tr><td>3</td><td></td><td></td><td></td><td></td></tr>
</table>
<p class="note">填写说明：须写明精确版本号，不得笼统填写“最新版”。</p>

<h3>第二部分：分环节使用记录</h3>
<table>
<tr>
<th>竞赛环节</th><th>是否使用AI</th><th>AI具体工作内容</th><th>使用目的</th>
</tr>
<tr><td>赛题理解与问题分析</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>模型假设与建立</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>模型求解与代码编写</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>结果分析与检验</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>论文撰写与修改</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>图表制作与数据可视化</td><td>□是 □否</td><td></td><td></td></tr>
<tr><td>其他辅助工作</td><td>□是 □否</td><td></td><td></td></tr>
</table>
<p class="note">填写说明：需明确写出AI在每个环节的具体工作，不得笼统填写“辅助建模”。</p>

<h3>第三部分：典型交互记录</h3>
<p>选取2-3次关键交互，完整记录提示词与AI回复及处理方式。</p>

<p><b>交互记录1</b></p>
<p>使用环节：__________</p>
<p>使用工具及版本：__________</p>
<p>提示词（Prompt）：</p>
<blockquote>（完整记录输入AI的提示词）</blockquote>
<p>AI输出摘要：</p>
<blockquote>（简要记录AI回复的核心内容）</blockquote>
<p>参赛队处理方式：□直接采纳 □修改后采纳 □仅作参考未采纳</p>
<p>人工修改与核验说明：</p>
<blockquote>（说明对AI输出的具体修改内容及核验方法）</blockquote>

<p><b>交互记录2</b></p>
<p>使用环节：__________</p>
<p>使用工具及版本：__________</p>
<p>提示词（Prompt）：</p>
<blockquote>（完整记录输入AI的提示词）</blockquote>
<p>AI输出摘要：</p>
<blockquote>（简要记录AI回复的核心内容）</blockquote>
<p>参赛队处理方式：□直接采纳 □修改后采纳 □仅作参考未采纳</p>
<p>人工修改与核验说明：</p>
<blockquote>（说明对AI输出的具体修改内容及核验方法）</blockquote>

<p><b>交互记录3</b></p>
<p>使用环节：__________</p>
<p>使用工具及版本：__________</p>
<p>提示词（Prompt）：</p>
<blockquote>（完整记录输入AI的提示词）</blockquote>
<p>AI输出摘要：</p>
<blockquote>（简要记录AI回复的核心内容）</blockquote>
<p>参赛队处理方式：□直接采纳 □修改后采纳 □仅作参考未采纳</p>
<p>人工修改与核验说明：</p>
<blockquote>（说明对AI输出的具体修改内容及核验方法）</blockquote>

<h3>第四部分：AI输出采纳与人工核验情况</h3>
<table>
<tr>
<th>序号</th><th>AI输出内容类型</th><th>采纳情况</th><th>人工修改内容</th><th>核验方式</th>
</tr>
<tr><td>1</td><td>建模思路</td><td>□全部采纳 □部分采纳 □未采纳</td><td></td><td></td></tr>
<tr><td>2</td><td>数学公式/推导</td><td>□全部采纳 □部分采纳 □未采纳</td><td></td><td></td></tr>
<tr><td>3</td><td>代码</td><td>□全部采纳 □部分采纳 □未采纳</td><td></td><td></td></tr>
<tr><td>4</td><td>文字表述</td><td>□全部采纳 □部分采纳 □未采纳</td><td></td><td></td></tr>
<tr><td>5</td><td>数据分析</td><td>□全部采纳 □部分采纳 □未采纳</td><td></td><td></td></tr>
</table>
<p class="note">填写说明：语言润色类的AI输出可豁免此项说明；非语言润色类输出须逐项填写采纳与核验情况。</p>

<h2>三、核心建模主导性确认声明</h2>
<p>本参赛队郑重声明：</p>
<p>1. 本参赛作品的核心建模思路、数学推导、参数设定与结果分析均由参赛队成员独立完成，AI工具仅起辅助作用；</p>
<p>2. 所有AI参与完成的内容均已逐项进行人工审查与核实，未直接提交未经核实的AI生成内容；</p>
<p>3. 本说明如实记录了竞赛期间AI工具的使用情况，不存在隐瞒或虚假声明；</p>
<p>4. 参赛队对提交作品的全部内容承担学术责任。</p>

<div class="sign">
<p>参赛队编号：____________________</p>
<p>参赛队员签名：____________________</p>
<p>日期：________年________月________日</p>
</div>

<h2>四、注意事项</h2>
<p>1. 声明位置：“AI工具使用声明”须置于论文参考文献之前，且声明内容应与支撑材料中的详情说明保持一致。</p>
<p>2. 文件格式：支撑材料中的详情说明须为PDF格式，文件名为“AI工具使用详情.pdf”。</p>
<p>3. 人工审查义务：参赛队须对AI输出的全部内容进行逐项人工审查与核实，不得将未经审查的AI生成内容直接作为核心建模与分析成果提交。</p>
<p>4. 违规后果：不符合上述规定的参赛作品，将视为违反竞赛规则；故意隐瞒AI使用情况或作出虚假声明的，取消评奖资格。</p>
<p>5. 核心主导性：AI工具不得替代参赛队完成审题、判断与最终结论，核心建模与分析必须由参赛队主导。</p>
<p>6. 未使用AI的情形：未使用AI工具的参赛队仅需在论文参考文献前填写对应声明即可，无需提交本详情说明。</p>

<p class="note">本模板依据2026年全国大学生数学建模竞赛相关要求编制，具体条款以官方最新通知为准。</p>

</body>
</html>
"""

with open("AI工具使用说明模板.doc", "w", encoding="utf-8") as f:
    f.write(html)

print("已生成：AI工具使用说明模板.doc")