#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED

#include <string>
#include <vector>
#include "Ability.h"
#include "DecisionTree.h"

class Ability;
class DecisionTree;


class Character {
public:
    Character(std::string name, int health, bool is_player_controlled = true);
    virtual ~Character();

    void setAsPlayerControlled();
    void setAsAIControlled();
    static void attack(Character& opponent, Ability& ability);
    bool is_defeated() const;
    Ability* choose_ability();
    void assign_decision_tree(DecisionTree* tree);
    void print_status() const;
    void reduce_health(int i);
    void play_turn(Character& opponent);
    void set_health(int new_health);
    void start_round();
       int get_health() const;
    std::vector<Ability*> abilities;
    std::string & get_name();
    void display_abilities();
    void use_ability(int i, Character &character);


protected:
    bool is_player_controlled;
    std::string name;
    int health;
    DecisionTree* decision_tree;
};

#endif // CHARACTER_H_INCLUDED
