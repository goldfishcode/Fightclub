#ifndef GAME_H
#define GAME_H
#include <string>
#include <vector>
#include "Character.h"
#include "Team.h"
#include "DecisionTree.h"
#include "Punch.h"
#include "Kick.h"
#include <iostream>


class Game {
public:
    Game();
   virtual ~Game() {
    for (Character *character : characters) {
        std::cout << "Deleting character: " << character->get_name() << std::endl;
        delete character;
    }
    for (Team *team : teams) {
        std::cout << "Deleting team: " << team->get_name() << std::endl;
        delete team;
     }
    for (DecisionTree *tree : decision_trees) {
            std::cout << "Deleting decision trees" << std::endl;
            delete tree;
        }
        std::cout << "Game destructor called" << std::endl;
    }
    void start();
    void create_costum_character();

private:
    void create_team_menu(Team *&team);
      void character_selection_menu(Character*& selected_character);
    static void team_battle(Team& team1, Team& team2);
    static void single_battle(Character& character1, Character& character2);
    void assign_decision_tree(Character& character);
    void reset_character_health();
    std::vector<Character*> characters;
    std::vector<Team*> teams;
    std::vector<DecisionTree*> decision_trees;
    DecisionTree* decision_tree1;
    DecisionTree* decision_tree2;
    Punch punch;
    Kick kick;
     int current_player_number = 1;
};

#endif
