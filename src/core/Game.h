#ifndef GAME_H
#define GAME_H

#include "entities/Room.h"
#include "npc/Suspect.h"
#include "core/CommandParser.h"
#include "core/SaveManager.h"
#include "clues/Notebook.h"
#include "clues/Judge.h"
#include <map>
using namespace std;

class Game {
private:
    Room* currentRoom;
    map<string, Room*> rooms;
    Suspect* suspect;
    Notebook* notebook;
    Judge* judge;
    CommandParser parser;
    SaveManager saveManager;
    bool isRunning;
    int week;
    int playerMental;
    int suspectMental;
    int insight;
    int intuition;
    int examineCount;
    bool hasSubmittedReport;
    bool gameOver;
    bool hasUsedLastLie;
    bool isInBattle;

public:
    Game();
    ~Game();

    void init();
    void run();
    void processCommand(const string& input);
    void go(const string& direction);
    void look();
    void talk(const string& npcName);
    void examine(const string& itemName);
    void think();
    void showNotebook();
    void combine(const string& args);
    void question(const string& clueName);
    void meditate();
    void intimidate();
    void submitReport();
    void showMap();
    void checkWeekTransition();
    void suspectAttack();
    void triggerLastLie();
    void endingScreen(const string& endingType);
    Room* getCurrentRoom() const;

    // SaveManager 需要的 getter
    int getWeek() const { return week; }
    int getPlayerMental() const { return playerMental; }
    int getSuspectMental() const { return suspectMental; }
    int getInsight() const { return insight; }
    int getIntuition() const { return intuition; }
    int getExamineCount() const { return examineCount; }
    bool getHasSubmittedReport() const { return hasSubmittedReport; }
    bool getGameOver() const { return gameOver; }
    bool getIsInBattle() const { return isInBattle; }

    // SaveManager 需要的 setter
    void setWeek(int w) { week = w; }
    void setPlayerMental(int pm) { playerMental = pm; }
    void setSuspectMental(int sm) { suspectMental = sm; }
    void setInsight(int i) { insight = i; }
    void setIntuition(int i) { intuition = i; }
    void setExamineCount(int ec) { examineCount = ec; }
    void setHasSubmittedReport(bool b) { hasSubmittedReport = b; }
    void setGameOver(bool b) { gameOver = b; }
    void setIsInBattle(bool b) { isInBattle = b; }
};

#endif
