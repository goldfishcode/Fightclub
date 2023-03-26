#include "DecisionTree2.h"


DecisionTree2::DecisionTree2() {
    // Constructor implementation
}

DecisionTree2::~DecisionTree2() {
    // Destructor implementation
}

int DecisionTree2::make_decision(Character& self, Character& opponent) {
    if (self.get_health() < 50) {
        self.use_ability(0, opponent);
        return 1;
    } else {
        self.use_ability(1, opponent);
        return 0;
    }
}
