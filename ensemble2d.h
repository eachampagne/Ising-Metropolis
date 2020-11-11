#include <iostream>
#include <vector>
#include "ensemble.h"
using namespace std;

#ifndef TWO_ENSEMBLE_H
#define TWO_ENSEMBLE_H

class Ensemble2d : public Ensemble {
    private:
        unsigned int width;
        unsigned int height;
        unsigned int getNextIndexX(unsigned int index); //get x index of neighbor in positive x direction
        unsigned int getPrevIndexX(unsigned int index); //get x index of neighbor in negative x direction
        unsigned int getNextIndexY(unsigned int index); //get y index of neighbor in positive y direction
        unsigned int getPrevIndexY(unsigned int index); //get y index of neighbor in negative y direction
    public:
        std::vector<std::vector<bool>> grid = {};
        Ensemble2d(unsigned int w, unsigned int h);

        unsigned int getWidth();
        unsigned int getHeight();

        void trace();
        void initGrid(float prob);
        void test();

        int calcEnergy();
        //Also need properties for energy, entropy, etc.
};

#endif