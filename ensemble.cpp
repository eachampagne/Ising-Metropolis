#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
using namespace std;

Ensemble::Ensemble() {
    cout << "Accessing the base ensemble constructor\n";
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