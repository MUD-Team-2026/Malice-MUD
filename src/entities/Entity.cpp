#include "Entity.h"

Entity::Entity() : id(""), name(""), description("") {}

Entity::Entity(const string& id, const string& name, const string& desc)
    : id(id), name(name), description(desc) {}

string Entity::getId() const { return id; }
string Entity::getName() const { return name; }
string Entity::getDescription() const { return description; }

void Entity::setName(const string& name) { this->name = name; }
void Entity::setDescription(const string& desc) { this->description = desc; }

string Entity::toString() const {
    return name + ": " + description;
}