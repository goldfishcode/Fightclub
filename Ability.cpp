#include "Character.h"
#include <utility>
#include <iostream>
#include "DecisionTree.h"
#include "Ability.h"
#include <string>


Ability::Ability(std::string name, int damage)
        : name(std::move(name)), damage(damage) {}

std::string Ability::get_name() {
    return name;
}

Ability::~Ability() = default;


