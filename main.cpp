#include "Game.h"
#include "Punch.h"
#include "Kick.h"
#include "Ability.h"
#include "Character.h"
#include "Team.h"
#include "DecisionTree.h"
#include "DecisionTree1.h"
#include "DecisionTree2.h"
#include <iostream>
#include <limits>
#include <utility>
#include <algorithm>
#include <set>



Game::Game() {
    decision_tree1 = new DecisionTree1();
    decision_tree2 = new DecisionTree2();
     auto *character1 = new Character("Dragon", 100);
    character1->assign_decision_tree(decision_tree1);
    character1->abilities.push_back(&punch);
    character1->abilities.push_back(&kick);
    characters.push_back(character1);

    auto *character2 = new Character("Gnome", 100);
    character2->assign_decision_tree(decision_tree2);
    character2->abilities.push_back(&punch);
    character2->abilities.push_back(&kick);
    characters.push_back(character2);

    auto *character3 = new Character("Bloodelf", 100);
    character3->assign_decision_tree(decision_tree1);
    character3->abilities.push_back(&punch);
    character3->abilities.push_back(&kick);
    characters.push_back(character3);

    auto *character4 = new Character("Demon", 100);
    character4->assign_decision_tree(decision_tree2);
    character4->abilities.push_back(&punch);
    character4->abilities.push_back(&kick);
    characters.push_back(character4);



}


void Game::start() {
    int choice;
    while (true) {
        std::cout << "1. Single Battle\n";
        std::cout << "2. Team Battle\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Character* selected_character1;
                Character* selected_character2;
                character_selection_menu(selected_character1);
              do {
                    character_selection_menu(selected_character2);
                    if (selected_character1->get_name() == selected_character2->get_name()) {
                        std::cout << "Error: That character has already been selected by player 1.\n";
                    }
                } while (selected_character1->get_name() == selected_character2->get_name());
             std::cout << "Player 1, for " << selected_character1->get_name() << ":\n";
                std::cout << "1. Human\n";
                std::cout << "2. Computer (assign decision tree)\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 2) {
                    selected_character1->setAsAIControlled();
                }
                std::cout << "Player 2, for " << selected_character2->get_name() << ":\n";
                std::cout << "1. Human\n";
                std::cout << "2. Computer (assign decision tree)\n";
                std::cout << "Enter your choice: ";
                std::cin >> choice;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if (choice == 2) {
                    selected_character2->setAsAIControlled();
                }
                single_battle(*selected_character1, *selected_character2);
                 selected_character1->setAsPlayerControlled();
                 selected_character2->setAsPlayerControlled();
                break;
            }
            case 2: {
                std::cout << "Select team 1:\n";
                Team *team1;
                create_team_menu(team1);
                std::cout << "Select team 2:\n";
                Team *team2;
                create_team_menu(team2);
                team_battle(*team1, *team2);
                break;
            }
            case 3:
                return;
            default:
                std::cout << "Invalid choice, try again\n";
        }
    }
}


void Game::create_team_menu(Team *&team) {
    std::cout << "Creating a new team...\n";
    std::cout << "Enter the team name: ";
    std::string team_name;
    std::getline(std::cin, team_name);

    auto *new_team = new Team(team_name);
    std::vector<Character*> team_members = team->get_members();

    int character_count;
    std::cout << "Enter the number of characters in the team: ";
    std::cin >> character_count;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < character_count; i++) {
        Character *selected_character;
        bool character_already_in_team = false;
        do {
            std::cout << "Select character " << (i + 1) << " for the team:\n";
            character_selection_menu(selected_character);
            character_already_in_team = false;
            for (Character *member : team_members) {
                if (selected_character->get_name() == member->get_name()) {
                    std::cout << "Error: That character has already been selected.\n";
                    character_already_in_team = true;
                }
            }
        } while (character_already_in_team);
        new_team->add_member(selected_character);
        team_members.push_back(selected_character);
    }
    teams.push_back(new_team);
    team = new_team;
}

void Game::character_selection_menu(Character*& selected_character) {
    int index = 1;
    int choice = 0;
    int choicep = 1;
    if (choice == choicep) {
         std::cout << "Invalid choice. Choose a character: ";
    }
    for (Character* character : characters) {
        std::cout << "Character " << index << ": " << character->get_name() << std::endl;
        index++;
    }
    std::cout << " Choose a character: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    while (choice < 1 || choice > characters.size()) {
        std::cout << "Invalid choice. Choose a character: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    selected_character = characters[choice - 1];
    }


void Game::team_battle(Team& team1, Team& team2) {
    std::cout << "Starting a team battle between " << team1.get_name() << " and " << team2.get_name() << "...\n";


    int round = 0;
    while (!team1.is_defeated() && !team2.is_defeated()) {
        std::cout << "\nRound " << round << ":\n";
        std::vector<Character*> team1_members = team1.get_members();
        std::vector<Character*> team2_members = team2.get_members();

        for (int i = 0; i < team1_members.size(); i++) {
            for (int j = 0; j < team2_members.size(); j++) {

                Character* character1 = team1_members[i];
                Character* character2 = team2_members[j];

                while (!character1->is_defeated() && !character2->is_defeated()) {

                    // Print status of both characters

                      std::cout << character1->get_name() <<  " Player " << i + 1 << " from " << team1.get_name() << ", choose an Ability for your opponent:" << ":\n";
                           character1->play_turn(*character2);
                            character2->print_status();


                     if (character2->is_defeated()) {
                       std::cout << character2->get_name() <<  " (Player " << j + 1 << " from " << team2.get_name() << ")" << " is defeated!\n";
                        character1->print_status();
                        character2->print_status();
                         team2.remove_member(character2);
                         character1->start_round();


                             std::cout << " defeated Player was kicked out of Team 2 "  << std::endl;
                        break;
                    }

                     std::cout << character2->get_name() <<  " Player " << j + 1 << " from " << team2.get_name() << ", choose an Ability for your opponent:" << ":\n";
                           character2->play_turn(*character1);
                           character1->print_status();


                      if (character1->is_defeated()) {
                         std::cout << character1->get_name() <<  " (Player " << i + 1 << " from " << team1.get_name() << ")" << " is defeated!\n";
                        character1->print_status();
                        character2->print_status();
                        team1.remove_member(character1);
                        character2->start_round();
                          std::cout << " defeated Player was kicked out of Team 1 "  << std::endl;
                        break;
                    }


                }

            }
            }
        round++;
    }

        if (team1.is_defeated()) {
        std::cout << "Team " << team2.get_name() << " wins the battle!\n";
    } else {
        std::cout << "Team " << team1.get_name() << " wins the battle!\n";
    }
}


void Game::single_battle(Character& character1, Character& character2) {
    std::cout << character1.get_name() << " vs. " << character2.get_name() << std::endl;

    while (!character1.is_defeated() && !character2.is_defeated()) {
        // Print status of both characters
        std::cout << character1.get_name() << ":\n";
        character1.print_status();
        std::cout << character2.get_name() << ":\n";
        character2.print_status();

        character1.play_turn(character2);
        if (character2.is_defeated()) {
            std::cout << character2.get_name() << " is defeated!\n";
        character1.print_status();
        character2.print_status();
        character2.start_round();
        character1.start_round();
            break;
        }
        character2.play_turn(character1);
        if (character1.is_defeated()) {
            std::cout << character1.get_name() << " is defeated!\n";
        character1.print_status();
        character2.print_status();
        character2.start_round();
        character1.start_round();
            break;
        }
    }
}

int main() {
    Game game;
    game.start();
    return 0;
}

