#include "Game.h"
#include <iostream>
#include <vector>

Game::Game() : currentRoom(nullptr), suspect(nullptr), notebook(nullptr), judge(nullptr), isRunning(false) {}

Game::~Game() {}

void Game::init() {
    Room* policeOffice = new Room("police", "警视厅搜查一課", "你站在警视厅的办公室里，桌上堆满了案件档案。");
    Room* study = new Room("study", "日高家书房", "书架上摆满了日高的作品。桌上有一个沾血的铜制纸镇。");
    Room* livingRoom = new Room("living", "日高家客厅", "客厅里有一台电视和一盘录像带。");
    Room* suspectHome = new Room("suspect_home", "野野口公寓", "房间里凌乱不堪，桌上堆满手写稿纸。");

    policeOffice->addExit("书房", study);
    policeOffice->addExit("公寓", suspectHome);
    study->addExit("客厅", livingRoom);
    study->addExit("警视厅", policeOffice);
    livingRoom->addExit("书房", study);
    suspectHome->addExit("警视厅", policeOffice);

    rooms["police"] = policeOffice;
    rooms["study"] = study;
    rooms["living"] = livingRoom;
    rooms["suspect_home"] = suspectHome;

    suspect = new Suspect("suspect", "野野口修", "一个看起来谦卑懦弱的中年男人。");
    study->addNPC(suspect);

    // 创建推理系统
    notebook = new Notebook();
    judge = new Judge(notebook);

    // 创建5个关键线索
    Clue* c1 = new Clue("clue_handwriting", "手写稿破绽", 
                         "野野口右手中指有厚厚的写茧，但打字机键盘几乎没有磨损。\n他最近大量手写——这些手稿是连夜赶抄的！", true, "野野口公寓");
    
    Clue* c2 = new Clue("clue_shadow", "树影破绽", 
                         "录影带中八重樱的树影角度显示拍摄时间在上午10点左右，\n但野野口声称是深夜潜入。录影带是预拍的道具！", true, "日高家客厅");
    
    Clue* c3 = new Clue("clue_poison", "杀猫真相", 
                         "野野口在杀人前三周就购买了山埃，\n毒死邻居的猫就是为了嫁祸日高的人格！", true, "社区药局");
    
    Clue* c4 = new Clue("clue_school", "中学真相", 
                         "中学时代被欺负得最惨的是日高，\n野野口是跟着施暴者一起欺辱日高的帮凶！", true, "旧中学");
    
    Clue* c5 = new Clue("clue_letter", "母亲信件", 
                         "野野口母亲的信中充满对日高家的鄙夷：\n「那家人低贱，不配和我儿子做朋友。」\n「日高那孩子怎么可能比我儿子优秀？」", true, "日高旧居");

    // 设置线索组合关系
    c1->addCombineTarget("clue_shadow");
    c2->addCombineTarget("clue_handwriting");
    c3->addCombineTarget("clue_school");
    c4->addCombineTarget("clue_letter");
    c5->addCombineTarget("clue_school");

    // 将所有线索添加到笔记本
    notebook->addClue(c1);
    notebook->addClue(c2);
    notebook->addClue(c3);
    notebook->addClue(c4);
    notebook->addClue(c5);

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
            examine(cmd.arg);
            break;

        case CommandType::TALK:
            talk(cmd.arg);
            break;

        case CommandType::THINK:
            think();
            break;

        case CommandType::NOTEBOOK:
            showNotebook();
            break;

        case CommandType::COMBINE:
            combine(cmd.arg);
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

void Game::talk(const string& npcName) {
    if (npcName.empty()) {
        cout << "请指定要对话的人，例如：talk 野野口" << endl;
        return;
    }

    string target = npcName;
    while (!target.empty() && target.front() == ' ') target.erase(0, 1);
    while (!target.empty() && target.back() == ' ') target.pop_back();

    vector<NPC*> npcs = currentRoom->getNPCs();

    for (NPC* npc : npcs) {
        string npcNameStr = npc->getName();
        while (!npcNameStr.empty() && npcNameStr.front() == ' ') npcNameStr.erase(0, 1);
        while (!npcNameStr.empty() && npcNameStr.back() == ' ') npcNameStr.pop_back();

        if (npcNameStr == target) {
            cout << npc->getFirstDialog() << endl;
            return;
        }
    }
    cout << "这里没有叫「" << target << "」的人。" << endl;
}

void Game::examine(const string& itemName) {
    if (itemName.empty()) {
        cout << "请指定要检查的物品，例如：examine 纸镇" << endl;
        return;
    }

    if (itemName.find("手稿") != string::npos || itemName.find("稿纸") != string::npos) {
        Clue* clue = notebook->getClue("clue_handwriting");
        if (clue) {
            cout << clue->getDescription() << endl;
            cout << "【已记录到侦探笔记】" << endl;
        }
    } else if (itemName.find("录影带") != string::npos || itemName.find("录像带") != string::npos) {
        Clue* clue = notebook->getClue("clue_shadow");
        if (clue) {
            cout << clue->getDescription() << endl;
            cout << "【已记录到侦探笔记】" << endl;
        }
    } else if (itemName.find("药") != string::npos || itemName.find("毒") != string::npos) {
        Clue* clue = notebook->getClue("clue_poison");
        if (clue) {
            cout << clue->getDescription() << endl;
            cout << "【已记录到侦探笔记】" << endl;
        }
    } else {
        cout << "你检查了「" << itemName << "」，但没有发现特别的线索。" << endl;
    }
}

void Game::think() {
    cout << "你闭上眼，重新梳理了所有线索……" << endl;
    cout << endl;

    vector<Clue*> keyClues = notebook->getKeyClues();
    if (keyClues.empty()) {
        cout << "目前还没有收集到关键破绽。继续调查吧。" << endl;
        return;
    }

    cout << "目前已收集的关键破绽（" << keyClues.size() << " / 5）：" << endl;
    for (Clue* clue : keyClues) {
        cout << "  - " << clue->getName() << endl;
    }

    if (keyClues.size() >= 4) {
        cout << endl << "你感觉真相已经很近了……" << endl;
        cout << "也许该去和野野口修当面对质了。" << endl;
    } else {
        cout << endl << "线索还不够充分，继续调查吧。" << endl;
    }
}

void Game::showNotebook() {
    cout << "========== 侦探笔记 ==========" << endl;
    vector<Clue*> allClues = notebook->getAllClues();
    if (allClues.empty()) {
        cout << "笔记本是空的。" << endl;
        return;
    }

    cout << "已收集线索：" << allClues.size() << " 条" << endl;
    cout << "关键破绽：" << notebook->getKeyClueCount() << " / 5" << endl;
    cout << endl;

    for (Clue* clue : allClues) {
        cout << "【" << clue->getName() << "】" << endl;
        cout << "  发现地点：" << clue->getLocation() << endl;
        cout << "  详情：" << clue->getDescription() << endl;
        cout << endl;
    }

    cout << "==============================" << endl;
}

void Game::combine(const string& args) {
    if (args.empty()) {
        cout << "请指定要组合的线索，例如：combine 手写稿破绽+树影破绽" << endl;
        return;
    }

    size_t pos = args.find('+');
    if (pos == string::npos) {
        cout << "请用 + 连接两个线索，例如：combine 手写稿破绽+树影破绽" << endl;
        return;
    }

    string name1 = args.substr(0, pos);
    string name2 = args.substr(pos + 1);
    while (!name1.empty() && name1.front() == ' ') name1.erase(0, 1);
    while (!name1.empty() && name1.back() == ' ') name1.pop_back();
    while (!name2.empty() && name2.front() == ' ') name2.erase(0, 1);
    while (!name2.empty() && name2.back() == ' ') name2.pop_back();

    Clue* c1 = nullptr;
    Clue* c2 = nullptr;
    for (Clue* clue : notebook->getAllClues()) {
        if (clue->getName() == name1) c1 = clue;
        if (clue->getName() == name2) c2 = clue;
    }

    if (c1 == nullptr || c2 == nullptr) {
        cout << "没有找到指定的线索。" << endl;
        return;
    }

    if (notebook->combine(c1->getId(), c2->getId())) {
        string inference = "组合「" + name1 + "」和「" + name2 + "」：\n";
        inference += "你发现了新的推理！";
        notebook->addInference(inference);
        cout << inference << endl;

        if (notebook->getKeyClueCount() >= 4) {
            cout << endl << "⚠️ 你已收集到足够证据！" << endl;
            cout << "输入 talk 野野口 可以开始对质。" << endl;
        }
    } else {
        cout << "这两个线索似乎无法组合。" << endl;
    }
}

Room* Game::getCurrentRoom() const {
    return currentRoom;
}