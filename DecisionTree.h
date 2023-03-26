#ifndef DECISIONTREE_H_INCLUDED
#define DECISIONTREE_H_INCLUDED

#include "Character.h"

class DecisionTree {
public:
    DecisionTree();
    virtual ~DecisionTree();
    virtual int make_decision(Character &self, Character &opponent) = 0;
};

#endif // DECISIONTREE_H_INCLUDED
