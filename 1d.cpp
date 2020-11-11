#include <iostream>
#include "ensemble1d.h"
using namespace std;

int main() {
    Ensemble1d testEnsemble(32);

    testEnsemble.test();

    cout << "Length: " << testEnsemble.getLength() << "\n";

    testEnsemble.initGrid(0.0);
    testEnsemble.trace();
    cout << "Energy = " << testEnsemble.calcEnergy() << " JkT\n";

    return 0;
}