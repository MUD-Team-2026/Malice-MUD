#include "Notebook.h"
#include <algorithm>

Notebook::Notebook() {}

Notebook::~Notebook() {}

void Notebook::addClue(Clue* clue) {
    if (clue == nullptr) return;
    for (Clue* c : clues) {
        if (c->getId() == clue->getId()) return;
    }
    clues.push_back(clue);
}

bool Notebook::hasClue(const string& id) const {
    for (Clue* clue : clues) {
        if (clue->getId() == id) return true;
    }
    return false;
}

Clue* Notebook::getClue(const string& id) const {
    for (Clue* clue : clues) {
        if (clue->getId() == id) return clue;
    }
    return nullptr;
}

vector<Clue*> Notebook::getAllClues() const {
    return clues;
}

vector<Clue*> Notebook::getKeyClues() const {
    vector<Clue*> keyClues;
    for (Clue* clue : clues) {
        if (clue->getIsKey()) {
            keyClues.push_back(clue);
        }
    }
    return keyClues;
}

bool Notebook::combine(const string& id1, const string& id2) {
    Clue* c1 = getClue(id1);
    Clue* c2 = getClue(id2);
    if (c1 == nullptr || c2 == nullptr) return false;

    if (!c1->canCombineWith(id2) && !c2->canCombineWith(id1)) {
        return false;
    }

    return true;
}

void Notebook::addInference(const string& inference) {
    inferences.push_back(inference);
}

vector<string> Notebook::getInferences() const {
    return inferences;
}

int Notebook::getClueCount() const {
    return clues.size();
}

int Notebook::getKeyClueCount() const {
    int count = 0;
    for (Clue* clue : clues) {
        if (clue->getIsKey()) count++;
    }
    return count;
}

void Notebook::clear() {
    clues.clear();
    inferences.clear();
}
