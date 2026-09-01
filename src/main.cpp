#include "core/Game.h"

int main() {
    system("chcp 65001 > nul");
    Game game;
    game.init();
    game.run();
    return 0;
}