#ifndef ABILITY_H_INCLUDED
#define ABILITY_H_INCLUDED
#include <string>

class Character;

class Ability {
public:
    Ability(std::string name, int damage);
    virtual ~Ability();

    virtual void perform_ability(Character& target) = 0;

    std::string get_name();

protected:
    std::string name;
    int damage;
};

#endif // ABILITY_H_INCLUDED
