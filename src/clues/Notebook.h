#ifndef NOTEBOOK_H
#define NOTEBOOK_H

#include "Clue.h"
#include <vector>
#include <map>
using namespace std;

class Notebook {
private:
    vector<Clue*> clues;
    vector<string> inferences;

public:
    Notebook();
    ~Notebook();

    void addClue(Clue* clue);
    bool hasClue(const string& id) const;
    Clue* getClue(const string& id) const;
    vector<Clue*> getAllClues() const;
    vector<Clue*> getKeyClues() const;

    // 线索组合推理
    bool combine(const string& id1, const string& id2);
    void addInference(const string& inference);
    vector<string> getInferences() const;

    // 统计信息
    int getClueCount() const;
    int getKeyClueCount() const;
};

#endif