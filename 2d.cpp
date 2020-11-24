#include <iostream>
#include "ensemble2d.h"
using namespace std;

int main() {
    float mu = 1.0;
    unsigned int max_steps = 10000;
    unsigned int equ_steps = 2000; //This better be far enough
    float J = 3.0 * Ensemble::k_boltzmann;

    for(int i = 0; i < 201; i++) {
        float temp = (float)(i) * 0.1;
        Ensemble2d testEnsemble(32, 32, temp, J, mu, false, max_steps);
        testEnsemble.initGrid(0.5);
        testEnsemble.run(true, equ_steps);
    }

    return 0;
}