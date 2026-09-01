#ifndef COLOR_H
#define COLOR_H

#include <string>
using namespace std;

// ANSI 顏色代碼
namespace Color {
    // 基本顏色
    const string RESET   = "\033[0m";
    const string RED     = "\033[31m";
    const string GREEN   = "\033[32m";
    const string YELLOW  = "\033[33m";
    const string BLUE    = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN    = "\033[36m";
    const string WHITE   = "\033[37m";
    
    // 亮色
    const string BRED    = "\033[91m";
    const string BGREEN  = "\033[92m";
    const string BYELLOW = "\033[93m";
    const string BBLE    = "\033[94m";
    const string BMAGENTA= "\033[95m";
    const string BCYAN   = "\033[96m";
    const string BWHITE  = "\033[97m";
    
    // 背景色
    const string BG_RED   = "\033[41m";
    const string BG_GREEN = "\033[42m";
    const string BG_YELLOW= "\033[43m";
    const string BG_BLUE  = "\033[44m";
    const string BG_BLACK = "\033[40m";
    
    // 樣式
    const string BOLD    = "\033[1m";
    const string DIM     = "\033[2m";
    const string ITALIC  = "\033[3m";
    const string UNDERLINE = "\033[4m";
    const string BLINK   = "\033[5m";
    const string REVERSE = "\033[7m";
}

#endif
