#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED

#include <string>
#include <vector>
#include "Character.h"

class Team {
public:
    explicit Team(std::string name);
    virtual ~Team();

    void add_member(Character* character);
    void remove_member(Character* character);
    bool is_defeated();
    void add_win();
    void add_loss();
    std::string get_name();

    std::vector<Character *> get_members();

protected:
    std::string name;
    std::vector<Character*> members;
    int wins{};
    int losses{};
};

#endif // TEAM_H_INCLUDED
