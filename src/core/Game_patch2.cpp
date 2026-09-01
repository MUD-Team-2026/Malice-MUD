void Game::go(const string& direction) {
    if (direction.empty()) {
        cout << YELLOW << "請指定方向，例如：go 書房" << RESET << endl;
        return;
    }
    Room* nextRoom = currentRoom->getExit(direction);
    if (nextRoom == nullptr) {
        cout << RED << "❌ 沒有通往「" << direction << "」的出口。" << RESET << endl;
        return;
    }
    
    printGoAnimation(currentRoom->getName(), nextRoom->getName());
    currentRoom = nextRoom;
    look();
}
