#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
using namespace std;

Ensemble::Ensemble(float temp, float J, float mu, bool verb, unsigned int max) {
    equilFlag = false; //Used for while loops; becomes true when ensemble reaches equilibrium conditions
    temperature = temp;
    J_strength = J;
    mu_strength = mu;
    verbose = verb;
    max_steps = max;
    number_steps = 0;
    number_acceptances = 0;
}

const double Ensemble::k_boltzmann = 1.380649e-23; //In Joules per Kelvin

//If the simulation hasn't taken any steps, this returns -1 rather than NaN or something similarly hard to handle
float Ensemble::calcAcceptanceRate() { 
    return (number_steps == 0) ? -1.0 : (float)(number_acceptances) / (float)(number_steps);
}
float Ensemble::calcEnergyMean(unsigned int startingIndex) {
    unsigned int n = energies.size() - startingIndex; //CHECK FOR OFF-BY-ONE ERROR
    int sum = 0;
    for(unsigned int i = startingIndex; i < energies.size(); i++) {
        sum += energies[i];
    }
    return (float)(sum) / (float)(n);
}
float Ensemble::calcEnergyStdDev(unsigned int startingIndex) {
    float energyMean = calcEnergyMean(startingIndex);
    unsigned int n = energies.size() - startingIndex; //CHECK FOR OFF-BY-ONE ERROR
    float sum = 0;
    for(unsigned int i = startingIndex; i < energies.size(); i++) {
        sum += pow((float)(energies[i]) - energyMean, 2.0);
    }
    return pow((float)(sum) / (float)(n), 0.5);
}
float Ensemble::calcMagnetMean(unsigned int startingIndex) {
    unsigned int n = magnetizations.size() - startingIndex; //CHECK FOR OFF-BY-ONE ERROR
    int sum = 0;
    for(unsigned int i = startingIndex; i < energies.size(); i++) {
        sum += magnetizations[i];
    }
    return (float)(sum) / (float)(n);
}
float Ensemble::calcCV(unsigned int startingIndex) {
    float stdDev = calcEnergyStdDev(startingIndex) * J_strength;
    float CV = pow(stdDev, 2.0) / k_boltzmann / temperature;
    return CV;
}
float Ensemble::getTemp() {
    return temperature;
}
float Ensemble::getJ() {
    return J_strength;
}
float Ensemble::getMu() {
    return mu_strength;
}
/**
bool Ensemble::newRandomSpin() {
    //randomly generates either an up or down spin
    bool spin; //True is spin up, false is spin down
    //I guess technically I could use an enum for this, but why create a two-state enum?

    float r = dis(gen); //?? Yeah I haven't looked up how to do this yet
    //https://stackoverflow.com/questions/48716109/generating-a-random-number-between-0-1-c/48716227

    if(r > 0.5) {
        spin = true;
    } else {
        spin = false;
    }
    return spin;
}
**/
/**
unsigned int Ensemble::getWidth() {
    return width;
}
unsigned int Ensemble::getHeight() {
    return height;
}
**/

void Ensemble::test() {
    cout << "Can sucessfully access this class\n";
    //cout << "Dimensions are " << width << " by " << height << ".\n";
    //cout << "Test int = " << /*this->*/testProperty << endl;
}