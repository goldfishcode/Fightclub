#ifndef KICK_H_INCLUDED
#define KICK_H_INCLUDED

#include "Ability.h"

class Kick : public Ability {
public:
    Kick();
    ~Kick() override;

    void perform_ability(Character& target) override;
};

#endif // KICK_H_INCLUDED
