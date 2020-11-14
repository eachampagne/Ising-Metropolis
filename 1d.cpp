#include <iostream>
#include "ensemble1d.h"
using namespace std;

int main() {
    Ensemble1d testEnsemble(32, 100.0, 3.0 * Ensemble::k_boltzmann);

    cout << "k_B = " << Ensemble::k_boltzmann << " J/K\n";

    testEnsemble.test();

    cout << "Length: " << testEnsemble.getLength() << "\n";
    cout << "Temperature: " << testEnsemble.getTemp() << "\n";
    cout << "J: " << testEnsemble.getJ() << "\n";

    testEnsemble.initGrid(0.5);
    testEnsemble.trace();
    cout << "Energy = " << testEnsemble.calcEnergy() << " J\n";

    //testEnsemble.flipSpin(3);
    //testEnsemble.trace();
    //cout << "Energy = " << testEnsemble.calcEnergy() << " J\n";

    testEnsemble.run();

    return 0;
}