#include <utility>
#include <iostream>
#include <time.h>
#include <random>

//
// Created by daniel on 29/04/19.
//

#include "Population.h"


Population::Population(int populationSize, bool initialise) {

    individuals =  vector<Gladiator>();
    fittest = new Gladiator();
    generation = new int(1);
    this->averAge = vector<int>();

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(10,20);
    std::uniform_int_distribution<int> uni1(0,25);

    if(initialise){
        for(int i = 0 ; i<populationSize ; i++){

            int u = uni(rng);
            int l = uni(rng);
            int e = uni(rng);
            int p = uni(rng);
            int a = uni1(rng);

            Gladiator newGlad = Gladiator(u,l,e,p,a);
            newGlad.calculateResistance();
            newGlad.setAtributeTovector(u,l,e,p,a);
            this->saveInitIndi(newGlad);
        }
    }
    this->calcALLProbability();

}

Gladiator Population::getGladiator(int index) {
    return individuals.at(index);
}
Gladiator Population::getFittest() {

    Gladiator fit = individuals.at(0);
    for(int i = 1 ; i<this->getSize() ; i++){
        float fit1 = fit.getFitness();
        float fit2 = individuals.at(i).getFitness();
        if(fit.getFitness() <= this->getGladiator(i).getFitness()){
            fit = getGladiator(i);
        }
    }
    *fittest  = fit;
    return *fittest;
}

int Population::getSize() {
    return static_cast<int>(individuals.size());
}

void Population::saveIndividual(int index, Gladiator gladiator) {
    individuals.at(index) = gladiator;
}

void Population::saveInitIndi(Gladiator gladiator) {
    individuals.push_back(gladiator);
}

void Population::calcALLProbability() {
    for(int i = 0 ; i<individuals.size() ; i++){
        individuals[i].calculateProbability();
    }
}

void Population::plusGeneration() {
    *generation  = *generation+1;
}

int Population::getGeneration() {
    return *generation;
}

float Population::getAverage() {
    float cont = 0;
    int average = 0;
    for(int i = 0 ; i < this->individuals.size() ; i++){
        cont+=this->getGladiator(i).getFitness();
    }
    average = cont/this->individuals.size();
    return average;
}


