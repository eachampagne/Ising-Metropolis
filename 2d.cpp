#include <iostream>
#include "ensemble2d.h"
using namespace std;

int main() {
    Ensemble2d testEnsemble(16, 32);

    testEnsemble.test();

    cout << "Width: " << testEnsemble.getWidth() << "\n";
    cout << "Height: " << testEnsemble.getHeight() << "\n";

    testEnsemble.initGrid(0.9);
    testEnsemble.trace();

    return 0;
}