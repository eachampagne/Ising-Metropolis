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
        Ensemble2d(unsigned int w, unsigned int h, float temp, float J, float mu, bool verb, unsigned int max);
        std::vector<std::vector<bool>> grid = {};

        unsigned int getWidth();
        unsigned int getHeight();

        void flipSpin(unsigned int x, unsigned int y); //This should ultimately be private, but I'm leaving it here for now for testing purposes
        void tryOneFlip();

        void trace();
        void initGrid(float prob);
        void test();

        int calcEnergy();
        int calcMagnetization();
        //Also need properties for energy, entropy, etc.

        void run(bool showResults, unsigned int stepsToEquil);
};

#endif