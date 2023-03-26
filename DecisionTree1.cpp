#include "DecisionTree1.h"
#include <cstdlib>

DecisionTree1::DecisionTree1() {
    // Constructor implementation
}

DecisionTree1::~DecisionTree1() {
    // Destructor implementation
}

int DecisionTree1::make_decision(Character& self, Character& opponent) {
    if (self.get_health() < 50) {
        self.use_ability(0, opponent);
        return 0;
    } else {
        self.use_ability(1, opponent);
        return 1;
    }
}
