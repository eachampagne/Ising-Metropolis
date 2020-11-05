#include <iostream>
#include <random>
#include <vector>
using namespace std;

#ifndef ENSEMBLE_H
#define ENSEMBLE_H

class Ensemble {
    public:
        //std::vector<std::vector<bool>> grid;
        Ensemble();

        //It turned out to be easier to have the init functions deal with random number generation rather than
        //making a specific function
        //bool newRandomSpin(); 

        void test();

        //If I stored the dimensions as a vector, I could consolidate some functions between 1 and 2 d
        //But it's probably not great to have a whole bunch of functions have to dynamically determine
        //what dimension they're working on

        //At the rate I'm going, Ensemble would be better as an abstract class

        //Also need properties for energy, entropy, etc.
};

/**
Ensemble::Ensemble() {
    cout << "Constructing a class\n";
    //this->testProperty = testProp;
}
**/

#endif