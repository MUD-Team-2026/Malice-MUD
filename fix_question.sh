#!/bin/bash
cd ~/Malice-MUD

cp src/core/Game.cpp src/core/Game.cpp.bak_question

python3 << 'PYTHON'
import re

with open('src/core/Game.cpp', 'r', encoding='utf-8') as f:
    content = f.read()

# 找到 question 函數
start = content.find('void Game::question(const string& clueName)')
if start == -1:
    print("❌ 找不到 question 函數")
    exit(1)

# 在函數內部找到 damage 計算後，加入計數邏輯
# 在 suspectMental -= damage; 前面加入：
#     evidenceShown++;
#     if (evidenceShown >= 5) {
#         suspectMental = 0;
#         cout << "你出示了全部5个关键证据！" << endl;
#     }

# 簡單替換：在 suspectMental -= damage; 前面插入
old_code = "    suspectMental -= damage;"
new_code = """    evidenceShown++;
    if (evidenceShown >= 5) {
        suspectMental = 0;
        cout << endl << "═══════════════════════════════════════" << endl;
        cout << "你出示了全部5个关键证据！" << endl;
        cout << "═══════════════════════════════════════" << endl;
        cout << endl;
    }
    suspectMental -= damage;"""

content = content.replace(old_code, new_code, 1)  # 只替換第一個

with open('src/core/Game.cpp', 'w', encoding='utf-8') as f:
    f.write(content)

print("✅ 修復完成：出示全部5個證據後野野口必死")
PYTHON

echo "重新編譯：cd ~/Malice-MUD/build && make && ./MaliceMUD"
