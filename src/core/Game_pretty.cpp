#include "Game.h"
#include "npc/OtherNPC.h"
#include "core/Color.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace Color;

// ===== 工具函數 =====
void printSlow(const string& text, int delay_ms = 20) {
    for (char c : text) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay_ms));
    }
}

void printLoading(const string& text, int duration_ms = 1500) {
    cout << text;
    for (int i = 0; i < 20; i++) {
        cout << "." << flush;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    cout << " " << GREEN << "✓" << RESET << endl;
}

void printDivider() {
    cout << CYAN << "═══════════════════════════════════════" << RESET << endl;
}

void printTitle() {
    cout << endl;
    cout << BRED << "  ██╗  ██╗██╗  ██╗██╗  ██╗██████╗ ███████╗" << RESET << endl;
    cout << BRED << "  ╚██╗██╔╝██║  ██║██║  ██║██╔══██╗██╔════╝" << RESET << endl;
    cout << BRED << "   ╚███╔╝ ███████║███████║██████╔╝█████╗  " << RESET << endl;
    cout << BRED << "   ██╔██╗ ██╔══██║██╔══██║██╔═══╝ ██╔══╝  " << RESET << endl;
    cout << BRED << "  ██╔╝ ██╗██║  ██║██║  ██║██║     ███████╗" << RESET << endl;
    cout << BRED << "  ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝" << RESET << endl;
    cout << endl;
    cout << BYELLOW << "        🕵️  惡 意  —  加 賀 恭 一 郎 的 調 查" << RESET << endl;
    cout << endl;
}

void printGoAnimation(const string& from, const string& to) {
    cout << BYELLOW << "🚶 你從「" << from << "」前往「" << to << "」..." << RESET << endl;
    for (int i = 0; i < 3; i++) {
        cout << "   ";
        for (int j = 0; j < 10; j++) {
            cout << "·" << flush;
            this_thread::sleep_for(chrono::milliseconds(60));
        }
        cout << "\r";
    }
    cout << GREEN << "✅ 到達「" << to << "」" << RESET << endl;
    this_thread::sleep_for(chrono::milliseconds(300));
}
