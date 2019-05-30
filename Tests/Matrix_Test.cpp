//
// Created by Daniel on 29/05/2019.
//

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../Logic/Matrix.h"

using  testing::Eq;

namespace {
    class ClassDeclaration : public testing::Test{
    public:
        Matrix matrix;
        ClassDeclaration(){
            matrix;
        }
    };
}

TEST_F(ClassDeclaration ,Prueba_de_Tamano)
{
    auto m= Matrix();
    m.fill(10);
    int cont=0;
    List<Cell*>* temp=m.getHead();
    int col=temp->getLength();
    while(temp!= nullptr)
    {
        cont++;
        temp=temp->getNext();
    }
    ASSERT_EQ(cont,col);
}
TEST_F(ClassDeclaration , Prueba_de_Posicion)
{
    auto m= Matrix();
    m.fill(10);
    int fil=5;
    int col=5;
    Cell* c=m.get(fil,col);

    ASSERT_EQ(fil,c->getLine());
    ASSERT_EQ(col,c->getColumn());
}
TEST_F(ClassDeclaration ,Prueba_de_Camino_backtrack)
{
    auto m= Matrix();
    m.fill(10);
    m.BacktrackingFindPath(0,0,9,9);

    Cell* temp= m.get(9,9);
    while(temp->getParent()!= nullptr)
    {
        temp=temp->getParent();
    }
    int c=temp->getColumn();
    int f=temp->getLine();
    ASSERT_EQ(c,0);
    ASSERT_EQ(f,0);
}

TEST_F(ClassDeclaration ,Prueba_de_Camino_Astar)
{
    auto m= Matrix();
    m.fill(10);
    m.AstarFindPath(0,0,9,9);

    Cell* temp= m.get(9,9);
    while(temp->getParent()!= nullptr)
    {
        temp=temp->getParent();
    }
    int c=temp->getColumn();
    int f=temp->getLine();
    ASSERT_EQ(c,0);
    ASSERT_EQ(f,0);
}
TEST_F(ClassDeclaration ,Prueba_de_Obstaculo)
{
    auto m= Matrix();
    m.fill(10);
    int f=7;
    int c=7;
    m.setAsObstacle(f,c);
    Cell* cell= m.get(f,c);
    EXPECT_TRUE(cell->isObstacle());

}
TEST_F(ClassDeclaration ,Prueba_de_Rango)
{
    auto m= Matrix();
    m.fill(10);
    int fo=6;
    int co=6;
    Cell* cello=m.get(fo,co);
    cello->setAsObstacle();
    cello->setObstascleType("explosive");

    int ft=4;
    int ct=4;
    Cell* cellT=m.get(ft,ct);
    EXPECT_TRUE(m.isInRange(cellT,cello));


}
TEST_F(ClassDeclaration ,Prueba_de_Dano)
{
    auto m= Matrix();
    m.fill(10);
    int f=5;
    int c=5;
    Cell* cell= m.get(f,c);

    m.setAsObstacle(5,4);
    Cell* cell1=m.get(5,4);
    cell1->setObstascleType("simple");
    m.getTowers()->add(cell1);

    m.setAsObstacle(8,5);
    Cell* cell2=m.get(8,5);
    cell2->setObstascleType("explosive");
    m.getTowers()->add(cell2);

    m.setAsObstacle(6,7);
    Cell* cell3=m.get(6,7);
    cell3->setObstascleType("fire");
    m.getTowers()->add(cell3);

    m.setAsObstacle(3,3);
    Cell* cell4=m.get(3,3);
    cell4->setObstascleType("explosive");
    m.getTowers()->add(cell4);

    ASSERT_EQ(m.getDamage(cell),7);

}
TEST_F(ClassDeclaration ,Prueba_Cantidad_Torres)
{
    auto m= Matrix();
    m.fill(10);
    Cell* b=m.get(0,0);
    Cell* e= m.get(9,9);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    ASSERT_EQ(m.getTowers()->getLength(),12);

}
TEST_F(ClassDeclaration ,Prueba_Cantidad_Mixer)
{
    auto m= Matrix();
    m.fill(10);
    Cell* b=m.get(0,0);
    Cell* e= m.get(9,9);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    m.randomObstacleSetter(b,e);
    m.Mixer(b,e);
    ASSERT_EQ(m.getTowers()->getLength(),12);

}


