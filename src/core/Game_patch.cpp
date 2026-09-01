// 將 run() 函數替換為美化版
void Game::run() {
    isRunning = true;
    
    // 載入動畫
    cout << CYAN;
    printLoading("🔍 載入案件檔案", 1500);
    printLoading("📖 讀取證人證詞", 1200);
    printLoading("📋 整理線索資料庫", 1000);
    cout << RESET;
    
    printDivider();
    printTitle();
    printDivider();
    
    cout << endl;
    cout << WHITE << "知名作家" << BRED << "日高邦彦" << RESET << WHITE << "被發現在家中書房被殺。" << RESET << endl;
    cout << WHITE << "兇手已投案自首——是他的好友，" << BYELLOW << "野野口修" << RESET << "。" << RESET << endl;
    cout << endl;
    cout << BYELLOW << "「人是我殺的。」" << RESET << WHITE << "野野口修說。" << RESET << endl;
    cout << BRED << "「但我有我的苦衷。」" << RESET << endl;
    cout << endl;
    cout << CYAN << "你看得出來，事情沒有這麼簡單。" << RESET << endl;
    cout << GREEN << "輸入 " << BYELLOW << "help" << RESET << GREEN << " 查看指令。" << RESET << endl;
    cout << endl;

    look();

    string input;
    while (isRunning && !gameOver) {
        cout << GREEN << "> " << RESET;
        getline(cin, input);
        processCommand(input);
    }
}
