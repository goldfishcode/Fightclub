#ifndef DECISIONTREE2_H_INCLUDED
#define DECISIONTREE2_H_INCLUDED
#include "DecisionTree.h"
#include "DecisionTree2.h"

class DecisionTree2 : public DecisionTree {
public:
    DecisionTree2();
    ~DecisionTree2();
    int make_decision(Character& self, Character& opponent);
};


#endif // DECISIONTREE2_H_INCLUDED
