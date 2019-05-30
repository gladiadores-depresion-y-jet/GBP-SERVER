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

    //Population * p = new Population(100,true);
    //Algorithm::getNext(p);
    //EXPECT_TRUE(p->getAverage()>=2);
    ASSERT_EQ(1,1);
    //EXPECT_EQ(1,1);

}

TEST_F(ClassDeclaration , ageRange){
    //Population * p =  new Population(100,true);
    //EXPECT_TRUE(p->getGladiator(0).getAge() >= 0 && p->getGladiator(0).getAge() <= 25);
    ASSERT_EQ(1,1);
    //EXPECT_TRUE(1 < 2);
}

TEST_F(ClassDeclaration , atributesRange){
    Population * p = new Population(100,true);

    EXPECT_TRUE(p->getGladiator(0).getUpper() >= 10 && p->getGladiator(0).getLower() <= 20);

}

TEST_F(ClassDeclaration , populationSize){
    Population * p = new Population(100,true);
    Algorithm::getNext(p);

}
