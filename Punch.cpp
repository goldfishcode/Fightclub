#include "Punch.h"
#include "Character.h"
Punch::Punch() : Ability("Punch", 10) {}

Punch::~Punch() = default;

void Punch::perform_ability(Character& target) {
    target.reduce_health(damage);
}

