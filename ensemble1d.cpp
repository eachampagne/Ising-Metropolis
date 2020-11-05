#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
#include "ensemble1d.h"
using namespace std;


Ensemble1d::Ensemble1d(unsigned int l) {
    length = l;
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