#include "Kick.h"
#include "Character.h"

Kick::Kick() : Ability("Kick", 15) {}

Kick::~Kick() {}

void Kick::perform_ability(Character& target) {
    target.reduce_health(damage);
}
