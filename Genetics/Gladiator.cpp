//
// Created by david on 09/05/19.
//

#include <cstdlib>
#include <time.h>
//#include <zconf.h> //TODO: desdocumentar el include en ubuntu
#include <random>
#include "Gladiator.h"
#include "Fitness.h"
#include <math.h>
#include <sstream>

static int defaultGeneLen = 5;
static int individualID = 0;

static std::random_device rd;     // only used once to initialise (seed) engine
static std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)
static std::uniform_int_distribution<int> uni(0,25); // guaranteed unbiased


Gladiator::Gladiator() {
    genes = vector<int>();
    this->id = individualID; individualID++;
    this->resistance = 0;
    this->emotionalI = 0;
    this->physical = 0;
    this->upper = 0;
    this->lower = 0;
    this->age = 0;
    this->estimatedG = 0;
    this->probability = 0;
    this->fitness = 0;
    this->mutation = "false";
    this->inversion = "false";
    this->father =  "[0,0,0,0,0]";
    this->mother =  "[0,0,0,0,0]";

}


Gladiator::Gladiator(int ag, int emot, int phy, int up, int low) {
    this->genes = vector<int>();
    this->id = individualID; individualID++;
    this->resistance = 0;
    this->age = ag;
    this->lower = low;
    this->upper = up;
    this->emotionalI = emot;
    this->physical = phy;
    this->probability = 0;
    this->estimatedG = 0;
    this->fitness = 0;
    this->mutation = "false";
    this->inversion = "false";
    this->father =  "[0,0,0,0,0]";
    this->mother =  "[0,0,0,0,0]";

}

int Gladiator::getGene(int index){
    return genes.at(index);
}

bool Gladiator::calculateResistance() {
    int multi = 0;
    if(this->age >= 0 & this->age<=10){
        multi = 3;

    }else if(this->age >= 11 & this->age<=24){
        multi = 2;
    }else if(this->age >= 25 & this->age<=40){
        multi = 1;

    }else if(this->age >= 26 & this->age<=60){
        multi = 2;
    }else if(this->age >= 61 & this->age<=99){
        multi = 3;
    }

    resistance = (upper+lower+emotionalI+physical)/(4*multi);

    if(resistance<0){
        resistance = 0;
    }else if(resistance >99){
        resistance = 99;
    }

    return true;
}

int Gladiator::size() {
    return defaultGeneLen;
}

void Gladiator::setGenes(int index , int gene) {
    this->genes.at(index) = gene;
    fitness = 0;
}

float Gladiator::getFitness() {
    if(fitness == 0){
        this->fitness = Fitness::getFitness(*this);
    }
    return this->fitness;
}

string Gladiator::genesToString() {
    string geneString = "[";
    for(int i = 0 ; i< defaultGeneLen-1 ; i++){
        geneString += to_string(getGene(i))+",";
    }geneString+=to_string(getGene(defaultGeneLen-1))+"]";
    return geneString;
}

void Gladiator::setAtributeTovector(int upper, int lower, int emoti, int phy, int age) {

    genes.push_back(upper);
    genes.push_back(lower);
    genes.push_back(emoti);
    genes.push_back(phy);
    genes.push_back(age);
}

vector<int> Gladiator::getGENES() {
    return this->genes;
}


void Gladiator::setVectorToAtributes() {

    this->upper = this->genes.at(0);
    this->lower = this->genes.at(1);
    this->emotionalI = this->genes.at(2);
    this->physical = this->genes.at(3);
    this->age = this->genes.at(4);


}


//  Gets and Sets
int Gladiator::getId(){
    return id;
}

int Gladiator::getAge(){
    return age;
}

float Gladiator::getProbability(){
    return probability;
}

int Gladiator::getEstimatedG(){
    return estimatedG;
}

int Gladiator::getEmotionalI(){
    return emotionalI;
}

int Gladiator::getPhysical(){
    return physical;
}

int Gladiator::getUpper(){
    return upper;
}

int Gladiator::getLower(){
    return lower;
}

int Gladiator::getResistance(){
    return resistance;
}

void Gladiator::setFitness(int fitness) {
    this->fitness = fitness;
}

void Gladiator::calculateProbability() {
    this->probability = (100*this->getFitness())/6;
}

void Gladiator::setGENE(vector<int> g) {
    this->genes = g;
}

void Gladiator::setInversionString(string invert) {
    this->inversion = invert;
}

void Gladiator::setMuatationString(string mutate) {
    this->mutation = mutate;
}

void Gladiator::setFathers(string f, string m) {
    this->father = f;
    this->mother = m;

}

string Gladiator::getMutation() {
    return this->mutation;
}

string Gladiator::getInversion() {
    return this->inversion;
}

string Gladiator::getMother() {
    return this->mother;
}

string Gladiator::getFather() {
    return this->father;
}
