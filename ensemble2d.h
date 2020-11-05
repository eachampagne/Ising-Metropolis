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
    public:
        std::vector<std::vector<bool>> grid = {};
        Ensemble2d(unsigned int w, unsigned int h);

        unsigned int getWidth();
        unsigned int getHeight();

        void trace();
        void initGrid(float prob);
        void test();
        //Also need properties for energy, entropy, etc.
};

#endif