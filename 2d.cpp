#include <iostream>
#include "ensemble2d.h"
using namespace std;

int main() {
    Ensemble2d testEnsemble(2, 4);

    testEnsemble.test();

    cout << "Width: " << testEnsemble.getWidth() << "\n";
    cout << "Height: " << testEnsemble.getHeight() << "\n";

    testEnsemble.initGrid(0.5);
    testEnsemble.trace();
    cout << "Energy = " << testEnsemble.calcEnergy() << " JkT\n";

    return 0;
}