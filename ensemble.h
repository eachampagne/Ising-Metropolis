#include <iostream>
#include <vector>
using namespace std;

#ifndef ENSEMBLE_H
#define ENSEMBLE_H

class Ensemble {
    private:
        unsigned int width;
        unsigned int height;
    public:
        std::vector<std::vector<bool>> grid;
        Ensemble(unsigned int w, unsigned int h);

        bool newRandomSpin();

        unsigned int getWidth();
        unsigned int getHeight();

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