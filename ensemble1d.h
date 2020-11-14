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
        Ensemble1d(unsigned int l, float temp, float J);
        std::vector<bool> grid = {};

        int calcEnergy(); //in terms of kT
        unsigned int getLength();

        void flipSpin(unsigned int index); //This should ultimately be private, but I'm leaving it here for now for testing purposes
        void tryOneFlip();

        void trace();
        void initGrid(float prob);
        void test();

        void run();
        //Also need properties for energy, entropy, etc.
};

#endif