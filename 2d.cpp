#include <iostream>
#include "ensemble.h"
using namespace std;

int main() {
    Ensemble testEnsemble(16, 32);

    testEnsemble.test();

    cout << "Width: " << testEnsemble.getWidth() << "\n";
    cout << "Height: " << testEnsemble.getHeight() << "\n";

    return 0;
}