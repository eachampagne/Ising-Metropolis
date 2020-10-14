#include <iostream>
#include <vector>
using namespace std;

#ifndef ENSEMBLE_H
#define ENSEMBLE_H

class Ensemble {
    public:
        std::vector<std::vector<bool>> grid;
        void test();
        //int testProperty;

        //Also need properties for energy, entropy, etc.
};

/**
Ensemble::Ensemble() {
    cout << "Constructing a class\n";
    //this->testProperty = testProp;
}
**/

#endif