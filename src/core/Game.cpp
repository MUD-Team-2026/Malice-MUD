#include "Game.h"
#include <iostream>

Game::Game() : currentRoom(nullptr), isRunning(false) {}

Game::~Game() {}

void Game::init() {
    // 创建房间
    Room* policeOffice = new Room("police", "警视厅搜查一課", "你站在警视厅的办公室里，桌上堆满了案件档案。");
    Room* study = new Room("study", "日高家书房", "书架上摆满了日高的作品。桌上有一个沾血的铜制纸镇。");
    Room* livingRoom = new Room("living", "日高家客厅", "客厅里有一台电视和一盘录像带。");
    Room* suspectHome = new Room("suspect_home", "野野口公寓", "房间里凌乱不堪，桌上堆满手写稿纸。");

    // 添加出口
    policeOffice->addExit("书房", study);
    policeOffice->addExit("公寓", suspectHome);
    study->addExit("客厅", livingRoom);
    study->addExit("警视厅", policeOffice);
    livingRoom->addExit("书房", study);
    suspectHome->addExit("警视厅", policeOffice);

    // 存到房间映射中
    rooms["police"] = policeOffice;
    rooms["study"] = study;
    rooms["living"] = livingRoom;
    rooms["suspect_home"] = suspectHome;

    // 设置玩家起始位置
    currentRoom = policeOffice;

    cout << "游戏初始化完成！" << endl;
}

void Game::run() {
    isRunning = true;
    cout << "═══════════════════════════════════════" << endl;
    cout << "        🕵️《恶意》— 加贺恭一郎的调查" << endl;
    cout << "═══════════════════════════════════════" << endl;
    cout << endl;

    look();

    string input;
    while (isRunning) {
        cout << "> ";
        getline(cin, input);
        processCommand(input);
    }
}

void Game::processCommand(const string& input) {
    Command cmd = parser.parse(input);

    switch (cmd.type) {
        case CommandType::HELP:
            cout << parser.getHelp() << endl;
            break;

        case CommandType::QUIT:
            cout << "退出游戏。" << endl;
            isRunning = false;
            break;

        case CommandType::GO:
            go(cmd.arg);
            break;

        case CommandType::LOOK:
            look();
            break;

        case CommandType::EXAMINE:
            if (cmd.arg.empty())
                cout << "请指定要检查的物品，例如：examine 纸镇" << endl;
            else
                cout << "你仔细检查了 " << cmd.arg << "。（功能开发中...）" << endl;
            break;

        case CommandType::TALK:
            if (cmd.arg.empty())
                cout << "请指定要对话的人，例如：talk 野野口" << endl;
            else
                cout << "你与 " << cmd.arg << " 对话。（功能开发中...）" << endl;
            break;

        case CommandType::THINK:
            cout << "你整理了思路...（功能开发中...）" << endl;
            break;

        case CommandType::NOTEBOOK:
            cout << "侦探笔记：（功能开发中...）" << endl;
            break;

        case CommandType::SAVE:
            cout << "游戏已保存。（功能开发中...）" << endl;
            break;

        case CommandType::LOAD:
            cout << "游戏已读取。（功能开发中...）" << endl;
            break;

        default:
            if (!input.empty()) {
                cout << "未知命令，输入 help 查看帮助。" << endl;
            }
            break;
    }
}

void Game::go(const string& direction) {
    if (direction.empty()) {
        cout << "请指定方向，例如：go 书房" << endl;
        return;
    }

    Room* nextRoom = currentRoom->getExit(direction);
    if (nextRoom == nullptr) {
        cout << "没有通往「" << direction << "」的出口。" << endl;
        return;
    }

    currentRoom = nextRoom;
    look();
}

void Game::look() {
    if (currentRoom == nullptr) {
        cout << "你不在任何地方。" << endl;
        return;
    }
    cout << currentRoom->getFullDescription() << endl;
}

Room* Game::getCurrentRoom() const {
    return currentRoom;
}