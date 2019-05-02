#include <iostream>
#include "../Logic/Matrix.h"

using namespace std;

int main()
{
    /*cout<<" ______"<<endl;
    cout<<"|******|"<<endl;
    cout<<"|******|"<<endl;
    cout<<"|  60  |"<<endl;
    cout<<"|______|"<<endl;*/

    Matrix* m= new Matrix();
    m->fill(10);
    Cell* obs1=m->get(2,4);
    obs1->setObstascleType("simple");
    obs1->setAsObstacle();
    m->getTowers()->add(obs1);

    Cell* obs2=m->get(2,5);
    obs2->setObstascleType("fire");
    obs2->setAsObstacle();
    m->getTowers()->add(obs2);

    Cell* obs3=m->get(3,5);
    obs3->setObstascleType("explosive");
    obs3->setAsObstacle();
    m->getTowers()->add(obs3);

    Cell* obs4=m->get(4,3);
    obs4->setObstascleType("fire");
    obs4->setAsObstacle();
    m->getTowers()->add(obs4);

    Cell* obs5=m->get(4,5);
    obs5->setObstascleType("simple");
    obs5->setAsObstacle();
    m->getTowers()->add(obs5);

    Cell* cell=m->get(3,4);
    m->print();

    cout<<"Dano total: "+to_string(m->getDamage(cell))<<endl;

    return 0;
}