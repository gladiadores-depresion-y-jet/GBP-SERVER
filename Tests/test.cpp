//
// Created by Daniel on 29/05/2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
//#include "ClassName.h"

using  testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        //ClassName obj;
        ClassDeclaration(){
            //obj;
        }
    };
}

TEST_F(ClassDeclaration , nameOfTheTest){
    ASSERT_EQ("","");
}
TEST_F(ClassDeclaration , nameOfTheTest2){
    ASSERT_EQ("","");
}

