#ifndef JUDGE_H
#define JUDGE_H

#include "Notebook.h"
#include <string>
using namespace std;

enum class Ending {
    BE,  // Bad Ending：草率结案
    NE,  // Normal Ending：证据不足
    TE,  // True Ending：揭开恶意
    HE   // Happy Ending：战斗胜利
};

class Judge {
private:
    Notebook* notebook;

public:
    Judge();
    Judge(Notebook* nb);

    void setNotebook(Notebook* nb);

    // 判断结局
    Ending judgeEnding();
    string getEndingDescription(Ending ending);

    // 检查关键证据
    bool hasAllKeyClues();
    int getKeyClueCount();

    // 生成结局报告
    string generateReport();
};

#endif