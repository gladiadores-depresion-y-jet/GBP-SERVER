//
// Created by Daniel on 29/05/2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Genetics/Gladiator.h"
#include "../Genetics/Algorithm.h"
#include "../Genetics/Population.h"

using  testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        Gladiator obj;
        ClassDeclaration(){
            obj;
        }
    };
}

TEST_F(ClassDeclaration , populationAverage){

    Population * p = new Population(100,true);
    Algorithm::getNext(p);

    EXPECT_TRUE(p->getAverage()>=1);

}

TEST_F(ClassDeclaration , ageRange){

    Population * p =  new Population(100,true);
    EXPECT_TRUE(p->getGladiator(0).getAge() >= 0 && p->getGladiator(0).getAge() <= 25);
}

TEST_F(ClassDeclaration , atributesRange){

    Population * p = new Population(100,true);
    EXPECT_TRUE(p->getGladiator(0).getUpper() >= 10 && p->getGladiator(0).getLower() < 20);

}

TEST_F(ClassDeclaration , populationSize){

    Population * p = new Population(100,true);
    *p = Algorithm::envolvePopulation(p);
    EXPECT_EQ(p->getSize(),100);

}

TEST_F(ClassDeclaration, itsBigger){

    Population * p = new Population(100,true);
    Gladiator  g1 = Algorithm::getNext(p);
    Gladiator g2 = Algorithm::getNext(p);

    EXPECT_TRUE(g2.getFitness() > g1.getFitness());


}

TEST_F(ClassDeclaration , sortPopulation){

    Population * p = new Population(100,true);
    *p = Algorithm::envolvePopulation(p);
    Algorithm::sortPopulation(p);

    bool flag = true;

    for(int i = 0 ; i<99 ; i++){
        if(p->getGladiator(i).getFitness() <= p->getGladiator(i+1).getFitness()){
            flag = false;

        }
    }

    EXPECT_TRUE(flag);
}

TEST_F(ClassDeclaration , crossOverTest){

    Population * p = new Population(100,true);
    Algorithm::sortPopulation(p);
    Gladiator g1 = p->getGladiator(0);
    Gladiator g2 = p->getGladiator(1);
    Gladiator g3 = Algorithm::crossover(g1,g2,true);
    g1.setVectorToAtributes();
    g2.setVectorToAtributes();
    bool flag = false;
    if(g3.getGene(0) == g1.getGene(0) && g3.getGene(1) == g2.getGene(1) && g3.getGene(2) == g1.getGene(2)
    && g3.getGene(3) == g2.getGene(3) && g3.getGene(4) == g1.getGene(4)){
        flag = true;
    }
    EXPECT_TRUE(flag);

}

TEST_F(ClassDeclaration , compareFittest){

    Population * p = new Population(100,true);
    *p = Algorithm::envolvePopulation(p);
    Gladiator g1 = p->getFittest();
    Algorithm::sortPopulation(p);
    Gladiator g2 = p->getGladiator(0);

    EXPECT_FLOAT_EQ(g1.getFitness(),g2.getFitness());
    
}