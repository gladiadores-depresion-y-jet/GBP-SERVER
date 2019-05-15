//
// Created by daniel on 29/04/19.
//

#include <random>
#include <algorithm>
#include <iostream>
#include "Algorithm.h"


//si el numero random sale entre estos valores entonces se produce una mutacion
static auto mutationRate = vector<int>{15, 50};
//si el numero random sale entre estos valores entonces se produce una inversion
static auto inversionRate = vector<int>{67};


Population Algorithm::envolvePopulation(Population * pop) {

    Population newPopulation = Population(pop->getSize() , false);
    //ordenar

    sortPopulation(pop);
    //reproducir a los cinco mejores y sacar 10 nuevos

    //añadiendo los cruces de los mejores

    bool flag = true;
    for(int i = 0 ; i<4; i++){

        for(int j = i+1 ; j<5; j++){
            Gladiator newGladiator = inversion(mutate(crossover(pop->getGladiator(i),pop->getGladiator(j),flag)));
            //introducirlos a la poblacion
            newPopulation.saveInitIndi(newGladiator);
            flag = !flag;

        }
    }
    //añadiendo a los 5 mejores de la generacion pasada
    for(int i = 0 ; i<90 ; i++){
        newPopulation.saveInitIndi(pop->getGladiator(i));
    }
    newPopulation.calcALLProbability();

    return newPopulation;

}




Gladiator Algorithm::crossover(Gladiator glad1, Gladiator glad2, bool flag) {

    Gladiator   result =  Gladiator();

    //how to crossover
    if(flag){
        result.setAtributeTovector(glad1.getGene(0) , glad2.getGene(1), glad1.getGene(2),glad2.getGene(3),glad1.getGene(4));

    }else{
        result.setAtributeTovector(glad2.getGene(0) , glad1.getGene(1), glad2.getGene(2),glad1.getGene(3),glad2.getGene(4));
    }
    result.setFathers(glad1.genesToString() , glad2.genesToString()); // añadiendo los genes de los padres
    result.setVectorToAtributes();
    result.calculateResistance();
    return result;

}


Gladiator Algorithm::inversion(Gladiator indiv) {
    Gladiator glad = indiv;
    vector<int> newVector = glad.getGENES();

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,99);


    //int invertir =  uniInv(rng);
    int invertir = uni(rng);
    int aux;
    if(invertir == 67){
        for(int i = 0 ;i <2 ; i++){
            aux = newVector[i];
            newVector[i] = newVector[4-i];
            newVector[4-i] = aux;
        }
        glad.setInversionString("true"); // añadiendo si invirtio
        glad.setGENE(newVector);
        glad.setVectorToAtributes();
        glad.calculateResistance();


    }
    return glad;


}

Gladiator Algorithm::mutate(Gladiator indiv) {

    Gladiator glad = indiv;

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<int> uni(0,99);
    std::uniform_int_distribution<int> uni1(0,15);
    std::uniform_int_distribution<int> uni2(0,3);
    std::uniform_int_distribution<int> uni3(-2,2);


    //int random = uniMut(rng);
    int random = uni(rng);

    if(std::find(mutationRate.begin(), mutationRate.end(), random) != mutationRate.end()) {
        /* mutationRate contains random */

        int sum_rest = uni1(rng);

        int randomGen = uni2(rng);

        int ranAge = uni3(rng);

        int genAge = glad.getGene(4)+ranAge;
        if(genAge > 99){
            genAge = 99;
        }else if(genAge < 0){
            genAge = 0;
        }
        glad.setGenes(4,genAge);

        int gene = glad.getGene(randomGen)+sum_rest;
        if(gene>99){
            gene = 99;
        }else if(gene<0){
            gene = 0;
        }
        glad.setGenes(randomGen,gene);
        glad.setMuatationString("true");

    }return glad;

}

void Algorithm::sortPopulation(Population * pop) {
    //Population sortPop = pop;
    for(int i = 0 ; i< 100 ; i++){
        for(int j = i ; j< 100 ; j++){
            float g1 = pop->getGladiator(i).getFitness();
            float g2 = pop->getGladiator(j).getFitness();
            if(pop->getGladiator(i).getFitness()<pop->getGladiator(j).getFitness()){

                //swap the gladiator
                Gladiator temp = pop->getGladiator(i);
                pop->saveIndividual(i , pop->getGladiator(j));
                pop->saveIndividual(j , temp);

            }
        }//return sortPop;

    }
}

Gladiator Algorithm::getNext(Population * pop) {

    float var = pop->getFittest().getFitness();
    while(pop->getFittest().getFitness() < 6){
        //Algorithm::sortPopulation(pop);
        if(pop->getFittest().getFitness() > var){
            //var = pop->getFittest().getFitness();
            pop->plusGeneration();
            cout<<"Generation: "<<pop->getGeneration()<<"Fittest: "<< pop->getFittest().getFitness()<<endl;
            cout<<"Gladiator Genes: "<<pop->getFittest().genesToString()<<endl;
            cout<<"Probabulity: "<<pop->getFittest().getProbability()<<" Resistance "<<pop->getFittest().getResistance()<<endl;
            return pop->getFittest();
        }
        *pop = Algorithm::envolvePopulation(pop);

    }return pop->getFittest();
}
