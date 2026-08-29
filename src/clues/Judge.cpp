#include "Judge.h"
#include <iostream>

Judge::Judge() : notebook(nullptr) {}

Judge::Judge(Notebook* nb) : notebook(nb) {}

void Judge::setNotebook(Notebook* nb) {
    notebook = nb;
}

Ending Judge::judgeEnding() {
    if (notebook == nullptr) {
        return Ending::NE;
    }

    int keyCount = notebook->getKeyClueCount();

    // 全收集全部5个关键破绽 → TE/HE
    if (keyCount >= 5) {
        return Ending::TE;
    }

    // 收集4个 → NE（证据不足）
    if (keyCount >= 4) {
        return Ending::NE;
    }

    // 收集3个以下 → BE（草率结案）
    return Ending::BE;
}

string Judge::getEndingDescription(Ending ending) {
    switch (ending) {
        case Ending::BE:
            return "【Bad Ending - 草率结案】\n"
                   "你轻信了野野口修的谎言，草草结案。\n"
                   "日高邦彦名誉扫地，野野口修的阴谋得逞。\n"
                   "数年后，你发现了真相，但为时已晚……\n"
                   "「先入为主的恶意，比杀人更可怕。」";

        case Ending::NE:
            return "【Normal Ending - 证据不足】\n"
                   "你怀疑野野口修在说谎，但证据不够充分。\n"
                   "最终案件以「影子写手报复杀人」结案。\n"
                   "日高邦彦留下了污名，真相被永远掩埋……";

        case Ending::TE:
            return "【True Ending - 揭开恶意】\n"
                   "你收集了全部5项关键破绽，\n"
                   "野野口修的心理防线彻底崩溃！\n"
                   "他面无表情地说出了那句话：\n"
                   "「我就是看他不爽。」\n"
                   "这就是全部的动机。\n"
                   "没有情仇，没有胁迫，没有影子写手。\n"
                   "只是从中学时代开始，日复一日的……恶意。\n"
                   "日高邦彦的名誉终于得以恢复。";

        case Ending::HE:
            return "【Happy Ending - 心理攻防大师】\n"
                   "你不仅在推理上完胜，\n"
                   "更在心理战中彻底击溃了野野口修！\n"
                   "他所有谎言都被你一一戳穿，\n"
                   "最终跪地认罪，说出了全部真相。\n"
                   "「我就是看他不爽。」\n"
                   "—— 恭喜你，你完美还原了《恶意》的真相！";

        default:
            return "未知结局";
    }
}

bool Judge::hasAllKeyClues() {
    if (notebook == nullptr) return false;
    return notebook->getKeyClueCount() >= 5;
}

int Judge::getKeyClueCount() {
    if (notebook == nullptr) return 0;
    return notebook->getKeyClueCount();
}

string Judge::generateReport() {
    if (notebook == nullptr) {
        return "未开始调查。";
    }

    string report = "========== 调查结案报告 ==========\n";
    report += "已收集线索：" + to_string(notebook->getClueCount()) + " 条\n";
    report += "关键破绽：" + to_string(notebook->getKeyClueCount()) + " / 5 项\n\n";

    report += "线索列表：\n";
    for (Clue* clue : notebook->getAllClues()) {
        report += "  - " + clue->getName();
        if (clue->getIsKey()) {
            report += " [关键破绽]";
        }
        report += "\n";
    }

    report += "\n推理结论：\n";
    for (const string& inf : notebook->getInferences()) {
        report += "  - " + inf + "\n";
    }

    Ending ending = judgeEnding();
    report += "\n" + getEndingDescription(ending);

    return report;
}