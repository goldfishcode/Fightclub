#ifndef DECISION_TREE_1_H
#define DECISION_TREE_1_H

#include "DecisionTree.h"
#include "Character.h"
class DecisionTree1 : public DecisionTree {
public:
    DecisionTree1();
    ~DecisionTree1() override;
    int make_decision(Character& self, Character& opponent) override;
};

#endif // DECISIONTREE1_H_INCLUDED
