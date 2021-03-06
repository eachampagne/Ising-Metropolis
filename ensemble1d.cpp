#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
#include "ensemble1d.h"
using namespace std;


Ensemble1d::Ensemble1d(unsigned int l, float temp, float J, float mu, bool verb, unsigned int max) : Ensemble(temp, J, mu, verb, max) {
    length = l;
}

void Ensemble1d::run(bool showResults, unsigned int stepsToEquil) {
    //cout << "running\n";
    if(verbose) {
        cout << number_steps << "\t" << cachedEnergy << "\t" << abs(cachedMagnet) << "\n"; //This prints out energy of initial state
    }
    while(number_steps < max_steps) {
        //cout << "flipping\n";
        tryOneFlip();
    }
    if(showResults) {
        cout << temperature << "\t" << calcEnergyMean(stepsToEquil) << "\t" << calcCV(stepsToEquil) << "\t" << abs(calcMagnetMean(stepsToEquil)) << "\t" << calcAcceptanceRate() << "\n";
    }
}

void Ensemble1d::flipSpin(unsigned int index){
    grid[index] = !grid[index];
}

void Ensemble1d::tryOneFlip() {
    //There must be some way to not have to do this every single time I run the function!
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    unsigned int index = floor(dis(gen) * length); //Yeah, I probably could just generate a random integer... but given that I don't really understand the random number generation, I'd rather use fewer different ones
    //cout << "Chosen index: " << index << "\n";

    //Don't need to find the energy of the entire system
    int localEnergy = 0; //in terms of JkT
    (grid[index] == grid[getNextIndex(index)]) ? (localEnergy -= 1) : (localEnergy += 1);
    (grid[index] == grid[getPrevIndex(index)]) ? (localEnergy -= 1) : (localEnergy += 1);

    int localEnergyFlipped = 0; //in terms of JkT
    (!grid[index] == grid[getNextIndex(index)]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);
    (!grid[index] == grid[getPrevIndex(index)]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);

    int deltaEnergy = localEnergyFlipped - localEnergy;
    int deltaMagnet = {(grid[index])? -2 : 2}; //How magnetization changes if the spin is flipped
    //cout << "Delta E: " << deltaEnergy << " J\n"; //in terms of JkT

    if((float)(deltaEnergy) * J_strength <= 0.0) { //If the deltaE = 0 (or J = 0) then e^0 = 1 so it would always flip
        flipSpin(index);
        number_steps++;
        number_acceptances++;
        cachedEnergy += deltaEnergy;
        cachedMagnet += deltaMagnet;
        //cout << "Automatic flip!\n";
    } else {
        float prob = exp(-(float)(deltaEnergy) * J_strength / k_boltzmann / temperature);  //e^deltaE/kT
        //cout << "Probability is " << prob << "\n";
        float r = dis(gen);
        if(r < prob) {
            flipSpin(index);
            number_steps++;
            number_acceptances++;
            cachedEnergy += deltaEnergy;
            cachedMagnet += deltaMagnet;
            //cout << "Flipped!\n";
        } else {
            number_steps++;
            //cout << "No flip.\n";
        }
    }
    //trace();
    energies.push_back(cachedEnergy);
    magnetizations.push_back(cachedMagnet);
    if(verbose) {
        cout << number_steps << "\t" << cachedEnergy << "\t" << abs(cachedMagnet) << "\n";
    }
}

unsigned int Ensemble1d::getNextIndex(unsigned int index) {
    if(index == length - 1) {
        return 0;
    } else {
        return index + 1;
    }
}

unsigned int Ensemble1d::getPrevIndex(unsigned int index) {
    if(index == 0) {
        return length - 1;
    } else {
        return index - 1;
    }
}

int Ensemble1d::calcEnergy() { 
    int energy = 0; //in terms of J
    for(int i = 0; i < length; i++) {
        (grid[i] == grid[getNextIndex(i)]) ? (energy -= 1) : (energy += 1);
    }
    cachedEnergy = energy;
    return energy;
}

int Ensemble1d::calcMagnetization() {
    int magnet = 0; //in terms of mu
    for(int i = 0; i < length; i++) {
        (grid[i]) ? (magnet += 1) : (magnet -= 1);
    }
    cachedMagnet = magnet;
    return magnet;
}

//Probability of an up spin. 0 (or less) is all down, 1 (or greater) is all up
void Ensemble1d::initGrid(float prob){
    if(prob <= 0) {
        for(int i = 0; i < length; i++) {
            grid.push_back(false);
        }
    } else if (prob >= 1) {
        for(int i = 0; i < length; i++) {
            grid.push_back(true);
        }
    } else {
        //Random distribution setup from https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        for(int i = 0; i < length; i++) {
            float r = dis(gen); //get random number
            bool spin;
            if(r < prob) {
                spin = true;
            } else {
                spin = false;
            }
            grid.push_back(spin);
        }
    }
    calcEnergy(); //Makes certain cachedEnergy is set
    calcMagnetization(); //Makes certain cachedMagnet is set
}

void Ensemble1d::trace() {
    for(int i = 0; i < length; i++) {
        cout << grid[i];        
    }
    cout << "\n";
}

unsigned int Ensemble1d::getLength() {
    return length;
}

void Ensemble1d::test() {
    cout << "This is a 1d ensemble and I have overridden the test function\n";
}