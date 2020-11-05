#include <iostream>
#include "ensemble1d.h"
using namespace std;

int main() {
    Ensemble1d testEnsemble(32);

    testEnsemble.test();

    cout << "Length: " << testEnsemble.getLength() << "\n";

    testEnsemble.initGrid(0.9);
    testEnsemble.trace();

    return 0;
}