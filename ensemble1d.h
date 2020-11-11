#include <iostream>
#include <vector>
#include "ensemble.h"
using namespace std;

#ifndef ONE_ENSEMBLE_H
#define ONE_ENSEMBLE_H

class Ensemble1d : public Ensemble {
    private:
        unsigned int length;
        unsigned int getNextIndex(unsigned int index); //get index of neighbor in positive direction
        unsigned int getPrevIndex(unsigned int index); //get index of neighbor in negative direction
    public:
        std::vector<bool> grid = {};
        Ensemble1d(unsigned int l);

        int calcEnergy(); //in terms of kT
        unsigned int getLength();

        void trace();
        void initGrid(float prob);
        void test();
        //Also need properties for energy, entropy, etc.
};

#endif