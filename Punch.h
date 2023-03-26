#ifndef PUNCH_H_INCLUDED
#define PUNCH_H_INCLUDED

#include "Ability.h"

class Punch : public Ability {
public:
    Punch();
    virtual~Punch() override;

    void perform_ability(Character& target) override;
};

#endif // PUNCH_H_INCLUDED
