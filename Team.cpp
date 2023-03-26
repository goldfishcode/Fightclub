#include "Team.h"
#include <utility>
#include <algorithm>

Team::Team(std::string name) : name(std::move(name)) {}

Team::~Team() = default;

void Team::add_member(Character* character) {
    members.push_back(character);
}

void Team::remove_member(Character* character) {
    members.erase(std::remove_if(members.begin(), members.end(), [character](Character* ptr) {
        return ptr == character;
    }), members.end());
}

bool Team::is_defeated() {
    for (Character* member : members) {
        if (!member->is_defeated()) {
            return false;
        }
    }
    return true;
}

void Team::add_win() {
    wins++;
}

void Team::add_loss() {
    losses ++;
}

std::string Team::get_name() {
    return name;
}

std::vector<Character *> Team::get_members() {
    return members;
}

