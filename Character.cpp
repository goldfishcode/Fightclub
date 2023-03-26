#include "Character.h"
#include <utility>
#include <iostream>
#include "DecisionTree.h"
#include "Ability.h"
#include <string>

Character::Character(std::string name, int health, bool is_player_controlled)
        : name(std::move(name)), health(health), decision_tree(nullptr),
          is_player_controlled(is_player_controlled) {}

Character::~Character() {

}

void Character::attack(Character &opponent, Ability &ability) {
    ability.perform_ability(opponent);
}

bool Character::is_defeated() const {
    return health <= 0;
}


void Character::start_round() {
    this->health = 100;
}

Ability* Character::choose_ability() {
    if (is_player_controlled) {
        std::cout << "Choose an ability: \n";
        for (size_t i = 0; i < abilities.size(); ++i) {
            std::cout << (i + 1) << ". " << abilities[i]->get_name() << "\n";
        }

        int choice;
        std::cin >> choice;

        while (choice < 1 || choice > static_cast<int>(abilities.size())) {
            std::cout << "Invalid input. Choose an ability: \n";
            for (size_t i = 0; i < abilities.size(); ++i) {
                std::cout << (i + 1) << ". " << abilities[i]->get_name() << "\n";
            }
            std::cin >> choice;
        }

        return abilities[choice - 1];
    } else {
        int computer_choice = rand() % abilities.size();
        return abilities[computer_choice];
    }
}


void Character::assign_decision_tree(DecisionTree *tree) {
    decision_tree = tree;
}

void Character::reduce_health(int i) {
    health -= i;
}

void Character::print_status() const {
    std::cout << name << " has " << health << " health left.\n";
}

std::string & Character::get_name() {
    return name;
}

void Character::display_abilities() {
    std::cout << "Abilities: \n";
    // Display the name of the ability with index
    for (size_t i = 0; i < abilities.size(); ++i) {
        std::cout << (i + 1) << ". " << abilities[i]->get_name() << "\n";
    }
}

void Character::use_ability(int i, Character &character) {
    abilities[i]->perform_ability(character);
}

int Character::get_health() const {
    return health;
}

void Character::play_turn(Character &opponent) {
    if (is_player_controlled) {
        display_abilities();
        int choice;
        std::cin >> choice;
        while (choice < 1 || choice > static_cast<int>(abilities.size())) {
            std::cout << "Invalid input. Choose an ability: \n";
            for (size_t i = 0; i < abilities.size(); ++i) {
                std::cout << (i + 1) << ". " << abilities[i]->get_name() << "\n";
            }
            std::cin >> choice;
        }
        abilities[choice - 1]->perform_ability(opponent);
    } else {
        int selection = decision_tree->make_decision(*this, opponent);
        std::cout << name << " chose " << abilities[selection]->get_name() << "\n";
    }
}

void Character::setAsPlayerControlled() {
    is_player_controlled = true;
}

void Character::setAsAIControlled() {
    is_player_controlled = false;
}
