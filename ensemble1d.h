#include <iostream>
#include <vector>
#include "ensemble.h"
using namespace std;

#ifndef ONE_ENSEMBLE_H
#define ONE_ENSEMBLE_H

class Ensemble1d : public Ensemble {
    private:
        unsigned int length;
    public:
        std::vector<bool> grid = {};
        Ensemble1d(unsigned int l);

        unsigned int getLength();

        void trace();
        void initGrid(float prob);
        void test();
        //Also need properties for energy, entropy, etc.
};

#endif