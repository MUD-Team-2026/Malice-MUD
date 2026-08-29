#ifndef OTHER_NPC_H
#define OTHER_NPC_H

#include "NPC.h"

class Reiko : public NPC {
public:
    Reiko();
    Reiko(const string& id, const string& name, const string& desc);
    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;
};

class Teacher : public NPC {
public:
    Teacher();
    Teacher(const string& id, const string& name, const string& desc);
    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;
};

class Fujio : public NPC {
public:
    Fujio();
    Fujio(const string& id, const string& name, const string& desc);
    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;
};

class Neighbor : public NPC {
public:
    Neighbor();
    Neighbor(const string& id, const string& name, const string& desc);
    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;
};

class Pharmacist : public NPC {
public:
    Pharmacist();
    Pharmacist(const string& id, const string& name, const string& desc);
    string getFirstDialog() override;
    string getDialog(const string& playerInput) override;
};

#endif

