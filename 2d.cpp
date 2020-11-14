#include <iostream>
#include "ensemble2d.h"
using namespace std;

int main() {
    Ensemble2d testEnsemble(2, 4, 1.1, 3.0);

    testEnsemble.test();

    cout << "Width: " << testEnsemble.getWidth() << "\n";
    cout << "Height: " << testEnsemble.getHeight() << "\n";
    cout << "Temperature: " << testEnsemble.getTemp() << "\n";
    cout << "J: " << testEnsemble.getJ() << "\n";


    testEnsemble.initGrid(0.5);
    testEnsemble.trace();
    cout << "Energy = " << testEnsemble.calcEnergy() << " JkT\n";

    testEnsemble.flipSpin(0,1);
    testEnsemble.trace();
    cout << "Energy = " << testEnsemble.calcEnergy() << " JkT\n";


    return 0;
}