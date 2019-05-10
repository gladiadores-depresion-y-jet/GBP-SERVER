#include <iostream>
#include "../Logic/Matrix.h"
#include "../Server/Server.h"
#include "../Objects/Population.h"
#include "../Objects/Fitness.h"
#include "../Objects/Algorithm.h"

using namespace std;

int main()
{
    /*cout<<" ______"<<endl;
    cout<<"|******|"<<endl;
    cout<<"|******|"<<endl;
    cout<<"|  60  |"<<endl;
    cout<<"|______|"<<endl;*/

    /*Matrix* m= new Matrix();
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

    cout<<"Dano total: "+to_string(m->getDamage(cell))<<endl;*/

   /* float solution = 6;
    Fitness::setSolution(solution);
    Population * mypop = new Population(100,true);
    int generation = 0;
    float var = mypop->getFittest().getFitness();
    while(mypop->getFittest().getFitness() < 6){
        generation++;
        //Population p = Algorithm::sortPopulation(mypop);
        Algorithm::sortPopulation(mypop);
        if(mypop->getFittest().getFitness() > var){
            var = mypop->getFittest().getFitness();
            cout<<"Generation: "<<generation <<"Fittest: "<< mypop->getFittest().getFitness()<<endl;
            cout<<"Gladiator Genes: "<<mypop->getFittest().genesToString()<<endl;
            cout<<"Probabulity: "<<mypop->getFittest().getProbability()<<" Resistance "<<mypop->getFittest().getResistance()<<endl;
        }
        *mypop = Algorithm::envolvePopulation(mypop);


    }

    cout<<" Solution found! "<<endl;
    cout<< " Generation: "<<generation;
    cout<< "Genes: "<< mypop->getFittest().genesToString()<<endl;*/

    Server* s= new Server();

    return 0;
}