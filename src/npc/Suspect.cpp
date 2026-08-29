#include "Suspect.h"
#include <iostream>

Suspect::Suspect() : NPC(), despairLevel(0), hasConfessed(false), isLying(true) {}

Suspect::Suspect(const string& id, const string& name, const string& desc)
    : NPC(id, name, desc), despairLevel(0), hasConfessed(false), isLying(true) {}

string Suspect::getFirstDialog() {
    if (isLying) {
        return "野野口修低着头，声音颤抖：\"我承认我杀了他。但我有我的理由……你去我家看看就知道了。\"";
    } else {
        return "野野口修面无表情地看着你：\"你终于发现了。\"";
    }
}

string Suspect::getDialog(const string& playerInput) {
    if (playerInput.find("动机") != string::npos || playerInput.find("理由") != string::npos) {
        if (isLying) {
            return "野野口修：\"日高他……他威胁我当他的影子写手。我忍了这么多年……\"";
        } else {
            return "野野口修沉默了很久，然后说：\"我就是看他不爽。\"";
        }
    }
    return getFirstDialog();
}

int Suspect::getDespairLevel() const {
    return despairLevel;
}

void Suspect::increaseDespair() {
    despairLevel += 10;
    if (despairLevel >= 100) {
        confess();
    }
}

void Suspect::confess() {
    hasConfessed = true;
    isLying = false;
    cout << "野野口修低下了头：\"好吧……我说实话……\"" << endl;
}

bool Suspect::getHasConfessed() const {
    return hasConfessed;
}

void Suspect::setLying(bool lying) {
    isLying = lying;
}

bool Suspect::getIsLying() const {
    return isLying;
}

string Suspect::getLieVersion() {
    return "我是日高的影子写手……他威胁我……我为了保护情人才杀了他……";
}

string Suspect::getTruthVersion() {
    return "我就是看他不爽。从中学开始，我就恨他……";
}