#ifndef ENTITY_H
#define ENTITY_H

#include <string>
using namespace std;

class Entity {
private:
    string id;
    string name;
    string description;

public:
    Entity();
    Entity(const string& id, const string& name, const string& desc);
    virtual ~Entity() = default;

    string getId() const;
    string getName() const;
    string getDescription() const;
    void setName(const string& name);
    void setDescription(const string& desc);
    virtual string toString() const;
};

#endif