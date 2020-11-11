#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
#include "ensemble2d.h"
using namespace std;


Ensemble2d::Ensemble2d(unsigned int w, unsigned int h) {
    width = w;
    height = h;
}

unsigned int Ensemble2d::getNextIndexY(unsigned int indexY) {
    if(indexY == height - 1) {
        return 0;
    } else {
        return indexY + 1;
    }
}

unsigned int Ensemble2d::getPrevIndexY(unsigned int indexY) {
    if(indexY == 0) {
        return height - 1;
    } else {
        return indexY - 1;
    }
}

unsigned int Ensemble2d::getNextIndexX(unsigned int indexX) {
    if(indexX == width - 1) {
        return 0;
    } else {
        return indexX + 1;
    }
}

unsigned int Ensemble2d::getPrevIndexX(unsigned int indexX) {
    if(indexX == 0) {
        return width - 1;
    } else {
        return indexX - 1;
    }
}

int Ensemble2d::calcEnergy() { 
    cout << "Note that I haven't actually found the equation for 2D energy, I think this is it but need to check.\n";
    int energy = 0; //in terms of JkT
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            (grid[i][j] == grid[getNextIndexY(i)][j]) ? (energy -= 1) : (energy += 1);
            (grid[i][j] == grid[i][getNextIndexX(j)]) ? (energy -= 1) : (energy += 1);
        }
    }
    return energy;
}

//Probability of an up spin. 0 (or less) is all down, 1 (or greater) is all up
void Ensemble2d::initGrid(float prob){
    if(prob <= 0) {
        for(int i = 0; i < height; i++) {
            grid.push_back({});
            for(int j = 0; j < width; j++) {
                grid[i].push_back(false);
            }
        }
    } else if (prob >= 1) {
        for(int i = 0; i < height; i++) {
            grid.push_back({});
            for(int j = 0; j < width; j++) {
                grid[i].push_back(true);
            }
        }
    } else {
        //Random distribution setup from https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<> dis(0.0, 1.0);
        for(int i = 0; i < height; i++) {
            grid.push_back({});
            for(int j = 0; j < width; j++) {
                float r = dis(gen); //get random number
                bool spin;
                if(r < prob) {
                    spin = true;
                } else {
                    spin = false;
                }
                grid[i].push_back(spin);
            }
        }
    }
}

void Ensemble2d::trace() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

unsigned int Ensemble2d::getWidth() {
    return width;
}
unsigned int Ensemble2d::getHeight() {
    return height;
}

void Ensemble2d::test() {
    cout << "This is a 2d ensemble and I have overridden the test function\n";
}