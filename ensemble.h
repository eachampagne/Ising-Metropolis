#include <iostream>
#include <random>
#include <vector>
using namespace std;

#ifndef ENSEMBLE_H
#define ENSEMBLE_H

class Ensemble {
    protected:
        bool equilFlag; //Used for while loops; becomes true when ensemble reaches equilibrium conditions
        float temperature; //In K
        float J_strength;
        unsigned int number_steps;
        unsigned int number_acceptances;
    public:
        static const double k_boltzmann; //In Joules per Kelvin

        Ensemble(float temp, float J);

        float calcAcceptanceRate(); //If the simulation hasn't taken any steps, this returns -1 rather than NaN or something similarly hard to handle

        float getTemp();
        float getJ();
        
        void test();
};

//make a public static var for boltzmann's const

//It turned out to be easier to have the init functions deal with random number generation rather than
//making a specific function
//bool newRandomSpin(); 

//If I stored the dimensions as a vector, I could consolidate some functions between 1 and 2 d
//But it's probably not great to have a whole bunch of functions have to dynamically determine
//what dimension they're working on

//At the rate I'm going, Ensemble would be better as an abstract class

//Also need properties for energy, entropy, etc.

/**
Ensemble::Ensemble() {
    cout << "Constructing a class\n";
    //this->testProperty = testProp;
}
**/

#endif