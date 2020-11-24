#include <iostream>
#include <random>
#include <vector>
#include "ensemble.h"
#include "ensemble2d.h"
using namespace std;


Ensemble2d::Ensemble2d(unsigned int w, unsigned int h, float temp, float J, float mu, bool verb, unsigned int max) : Ensemble(temp, J, mu, verb, max) {
    width = w;
    height = h;
}

void Ensemble2d::run(bool showResults, unsigned int stepsToEquil) {
    //cout << "running\n";
    if(verbose) {
        cout << number_steps << "\t" << cachedEnergy << "\n"; //This prints out energy of initial state and makes certain cacheEnergy exists
    }
    while(number_steps < max_steps) {
        //cout << "flipping\n";
        tryOneFlip();
    }
    if(showResults) {
        cout << temperature << "\t" << calcEnergyMean(stepsToEquil) << "\t" << calcCV(stepsToEquil) << "\t" << abs(calcMagnetMean(stepsToEquil)) << "\t" << calcAcceptanceRate() << "\n";
    }
}

void Ensemble2d::flipSpin(unsigned int x, unsigned int y){
    grid[y][x] = !grid[y][x];
}

void Ensemble2d::tryOneFlip() {
    //There must be some way to not have to do this every single time I run the function!
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    unsigned int index = floor(dis(gen) * width * height); //Yeah, I probably could just generate a random integer... but given that I don't really understand the random number generation, I'd rather use fewer different ones
    //cout << "Chosen index: " << index << "\n";

    unsigned int indexX = index % width;
    unsigned int indexY = index / width;

    //Don't need to find the energy of the entire system
    int localEnergy = 0; //in terms of JkT
    (grid[indexY][indexX] == grid[indexY][getNextIndexX(indexX)]) ? (localEnergy -= 1) : (localEnergy += 1);
    (grid[indexY][indexX] == grid[getNextIndexY(indexY)][indexX]) ? (localEnergy -= 1) : (localEnergy += 1);
    (grid[indexY][indexX] == grid[indexY][getPrevIndexX(indexX)]) ? (localEnergy -= 1) : (localEnergy += 1);
    (grid[indexY][indexX] == grid[getPrevIndexY(indexY)][indexX]) ? (localEnergy -= 1) : (localEnergy += 1);
    //cout << "Local E: " << localEnergy << " J\n";

    int localEnergyFlipped = 0; //in terms of JkT
    (!grid[indexY][indexX] == grid[indexY][getNextIndexX(indexX)]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);
    (!grid[indexY][indexX] == grid[getNextIndexY(indexY)][indexX]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);
    (!grid[indexY][indexX] == grid[indexY][getPrevIndexX(indexX)]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);
    (!grid[indexY][indexX] == grid[getPrevIndexY(indexY)][indexX]) ? (localEnergyFlipped -= 1) : (localEnergyFlipped += 1);
    //cout << "Local E flipped: " << localEnergyFlipped << " J\n";

    int deltaEnergy = localEnergyFlipped - localEnergy;
    int deltaMagnet = {(grid[indexY][indexX])? -2 : 2}; //How magnetization changes if the spin is flipped
    //cout << "Delta E: " << deltaEnergy << " J\n"; //in terms of JkT

    if((float)(deltaEnergy) * J_strength <= 0.0) { //If the deltaE = 0 (or J = 0) then e^0 = 1 so it would always flip
        flipSpin(indexX, indexY);
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
            flipSpin(indexX, indexY);
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
    int energy = 0; //in terms of J
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            (grid[i][j] == grid[getNextIndexY(i)][j]) ? (energy -= 1) : (energy += 1);
            (grid[i][j] == grid[i][getNextIndexX(j)]) ? (energy -= 1) : (energy += 1);
        }
    }
    cachedEnergy = energy;
    return energy;
}

int Ensemble2d::calcMagnetization() {
    int magnet = 0; //in terms of mu
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++){
            (grid[i][j]) ? (magnet += 1) : (magnet -= 1);
        }
    }
    cachedMagnet = magnet;
    return magnet;
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
    calcEnergy(); //Makes certain cachedEnergy is set
    calcMagnetization();
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