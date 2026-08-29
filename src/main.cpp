#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "═══════════════════════════════════════" << endl;
    cout << "        🕵️《恶意》— 加贺恭一郎的调查" << endl;
    cout << "═══════════════════════════════════════" << endl;
    cout << endl;
    cout << "你现在位于：警视厅搜查一課" << endl;
    cout << "输入 help 查看指令。" << endl;
    cout << endl;

    string input;
    while (true) {
        cout << "> ";
        getline(cin, input);

        if (input == "quit" || input == "exit") {
            cout << "退出游戏。" << endl;
            break;
        } else if (input == "help") {
            cout << "可用命令：go, look, examine, talk, help, quit" << endl;
        } else if (input.empty()) {
            // 空输入不做任何事
        } else {
            cout << "未知命令，输入 help 查看帮助。" << endl;
        }
    }

    return 0;
}