//
// Created by dcamachog1501 on 24/04/19.
//

#include <string>
#include <iostream>
#include <random>
#include "Matrix.h"
Matrix::Matrix()
{
    this->head= nullptr;
    this->towers=new List<Cell*>;
}

void Matrix::fill(int limit)
{
    this->lines=limit;
    this->columns=limit;
    for(int i=0;i<limit;i++)
    {
        List<Cell*>* l= new List<Cell*>();
        if(this->head== nullptr)
        {
            this->head=l;
        }
        else
        {
            List<Cell*>*temp= this->head;
            while(temp->getNext()!= nullptr)
            {
                temp=(List<Cell*>*)temp->getNext();
            }
            temp->setNext(l);
        }
        int c=0;
        while(l->getLength()<limit)
        {
            Cell* cl= new Cell(i,c);
            l->add(cl);
            c++;
        }
    }

}

void Matrix::print()
{
    List<Cell*>* temp= this->head;
    while(temp!= nullptr)
    {
        Node<Cell*>* temp2=temp->getHead();
        string one= "";
        while(temp2!= nullptr)
        {
            one+=" ______";
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string two= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                if(temp2->getValue()->getObstacleType()=="simple")
                    two+="******|";
                else if(temp2->getValue()->getObstacleType()=="fire")
                    two+="######|";
                else if(temp2->getValue()->getObstacleType()=="explosive")
                    two+="@@@@@@|";
            }
            else
            {
                two+="      |";//to_string(temp2->getValue()->getG())+"   "+to_string(temp2->getValue()->getH())+" |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string three= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                if(temp2->getValue()->getObstacleType()=="simple")
                    three+="******|";
                else if(temp2->getValue()->getObstacleType()=="fire")
                    three+="######|";
                else if(temp2->getValue()->getObstacleType()=="explosive")
                    three+="@@@@@@|";
            }
            else
            {
                three+="      |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string four= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                if(temp2->getValue()->getObstacleType()=="simple")
                    four+="******|";
                else if(temp2->getValue()->getObstacleType()=="fire")
                    four+="######|";
                else if(temp2->getValue()->getObstacleType()=="explosive")
                    four+="@@@@@@|";
            }
            else if(temp2->getValue()->isPath())
            {
                if(temp2->getValue()->getParent()!= nullptr)
                    four+="   "+directionGetter(temp2->getValue(),temp2->getValue()->getParent())+"  |";
                else
                    four+="   $  |";
            }
            else
            {
                /*if(temp2->getValue()->getF()>0)
                four+="  "+to_string(temp2->getValue()->getF())+"  |";
                else*/
                four+="      |";
            }
            temp2=temp2->getNext();
        }
        temp2=temp->getHead();
        string five= "|";
        while(temp2!= nullptr)
        {
            if(temp2->getValue()->isObstacle())
            {
                if(temp2->getValue()->getObstacleType()=="simple")
                    five+="******|";
                else if(temp2->getValue()->getObstacleType()=="fire")
                    five+="######|";
                else if(temp2->getValue()->getObstacleType()=="explosive")
                    five+="@@@@@@|";
            }
            else
            {
                five += "______|";
            }
            temp2=temp2->getNext();
        }
        cout<<one<<endl;
        cout<<two<<endl;
        cout<<three<<endl;
        cout<<four<<endl;
        cout<<five<<endl;
        temp=temp->getNext();
    }
}

Cell *Matrix::get(int f, int c)
{
    if(f>9||c>9)
    {
        return nullptr;
    }
    List<Cell*>* temp=this->head;
    while(temp->getHead()->getValue()->getLine()!=f)
    {
        if(temp== nullptr)
        {
            break;
        }
        temp=temp->getNext();
    }
    Node<Cell*>*temp2=temp->getHead();
    while(temp2->getValue()->getColumn()!=c)
    {
        if(temp2== nullptr)
        {
            return nullptr;
        }
        temp2=temp2->getNext();
    }
    return temp2->getValue();
}

void Matrix::setNeighbours(Cell* cell)
{
    if (cell->getLine() == 0)
    {
        if (cell->getColumn() == 0) {
            cell->addNeighbour(getNeighbour(cell, "r"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dr"));
        } else if (cell->getColumn() == 9) {
            cell->addNeighbour(getNeighbour(cell, "l"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dl"));
        } else {
            cell->addNeighbour(getNeighbour(cell, "r"));
            cell->addNeighbour(getNeighbour(cell, "dr"));
            cell->addNeighbour(getNeighbour(cell, "d"));
            cell->addNeighbour(getNeighbour(cell, "dl"));
            cell->addNeighbour(getNeighbour(cell, "l"));
        }
    }
    else if (cell->getLine() == 9)
    {
        if (cell->getColumn() == 0) {
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ur"));
            cell->addNeighbour(getNeighbour(cell, "r"));
        } else if (cell->getColumn() == 9) {
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ul"));
            cell->addNeighbour(getNeighbour(cell, "l"));
        } else {
            cell->addNeighbour(getNeighbour(cell, "l"));
            cell->addNeighbour(getNeighbour(cell, "ul"));
            cell->addNeighbour(getNeighbour(cell, "u"));
            cell->addNeighbour(getNeighbour(cell, "ur"));
            cell->addNeighbour(getNeighbour(cell, "r"));
        }
    }
    else if (cell->getColumn() == 0)
    {
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ur"));
        cell->addNeighbour(getNeighbour(cell, "r"));
        cell->addNeighbour(getNeighbour(cell, "dr"));
        cell->addNeighbour(getNeighbour(cell, "d"));
    }
    else if (cell->getColumn() == 9)
    {
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ul"));
        cell->addNeighbour(getNeighbour(cell, "l"));
        cell->addNeighbour(getNeighbour(cell, "dl"));
        cell->addNeighbour(getNeighbour(cell, "d"));
    }
    else
    {
        cell->addNeighbour(getNeighbour(cell, "ul"));
        cell->addNeighbour(getNeighbour(cell, "u"));
        cell->addNeighbour(getNeighbour(cell, "ur"));
        cell->addNeighbour(getNeighbour(cell, "r"));
        cell->addNeighbour(getNeighbour(cell, "dr"));
        cell->addNeighbour(getNeighbour(cell, "d"));
        cell->addNeighbour(getNeighbour(cell, "dl"));
        cell->addNeighbour(getNeighbour(cell, "l"));
    }

}

Cell *Matrix::getNeighbour(Cell* c,string position)
{
    if(position=="u")
    {
        return get(c->getLine()-1,c->getColumn());
    }
    else if(position=="ul")
    {
        return get(c->getLine()-1,c->getColumn()-1);
    }
    else if(position=="ur")
    {
        return get(c->getLine()-1,c->getColumn()+1);
    }
    else if(position=="l")
    {
        return get(c->getLine(),c->getColumn()-1);
    }
    else if(position=="r")
    {
        return get(c->getLine(),c->getColumn()+1);
    }
    else if(position=="d")
    {
        return get(c->getLine()+1,c->getColumn());
    }
    else if(position=="dl")
    {
        return get(c->getLine()+1,c->getColumn()-1);
    }
    else if (position=="dr")
    {
        return get(c->getLine()+1,c->getColumn()+1);
    }
}

void Matrix::setAsObstacle(int l,int c)
{
    Cell* cell=get(l,c);
    cell->setAsObstacle();

}

void Matrix::AstarFindPath(int lstart, int cstart, int lfinish, int cfinish)
{
    Cell* start=get(lstart,cstart);
    Cell* finish= get(lfinish,cfinish);
    List<Cell*>* open= new List<Cell*>;
    List<Cell*>* closed= new List<Cell*>;

    open->add(start);

    while(true)
    {
        Node<Cell*>* temp= open->getHead();
        while(temp!= nullptr)
        {
            temp->getValue()->setG(getGCost(temp->getValue(),closed,start));
            temp->getValue()->setH(getHCost(temp->getValue(),finish));
            temp=temp->getNext();
        }
        Node<Cell*>* currentNode= lowestF(open);
        Cell* current=currentNode->getValue();
        closed->add(current);
        open->del(currentNode->getOrder());

        if(current->getLine()==finish->getLine()&&current->getColumn()==finish->getColumn())
        {
            break;
        }
        setNeighbours(current);
        temp=current->getNeighbours()->getHead();
        while(temp!= nullptr)
        {
            if(!(temp->getValue()->isObstacle()||in(closed,temp->getValue()))&&(isShorter(temp->getValue(),current)||!in(open,temp->getValue())))
            {
                setNeighbours(temp->getValue());
                temp->getValue()->setG(getGCost(temp->getValue(),closed,start));
                temp->getValue()->setH(getHCost(temp->getValue(),finish));
                temp->getValue()->setParent(current);
                if(!in(open,temp->getValue()))
                {
                    open->add(temp->getValue());
                }
            }
            temp=temp->getNext();
        }

        delete(temp);
    }
    Cell* temp=finish;
    while(temp!= nullptr)
    {
        temp->setAsPath();
        temp=temp->getParent();
    }

    delete(temp);
}
void Matrix::BacktrackingFindPath(int lstart, int cstart, int lfinish, int cfinish)
{
    Cell* begining=get(lstart,cstart);
    Cell* end=get(lfinish,cfinish);

    if(BacktrackingSolver(begining,end))
    {
        Cell* temp=end;
        while(temp!= nullptr)
        {
            temp->setAsPath();
            temp=temp->getParent();
        }
    }
    else
    {
        cout << "No es posible llegar al punto" << endl;
    }

}
int Matrix::getHCost(Cell *askingC,Cell* destiny)
{
    if(askingC->getLine()==destiny->getLine()&&askingC->getColumn()==destiny->getColumn())
    {
        return 0;
    }
    else
    {
        int cost=0;
        int line=askingC->getLine();
        int column=askingC->getColumn();
        while(true)
        {
            int difL=destiny->getLine()-line;
            int difC=destiny->getColumn()-column;
            if(line==destiny->getLine()&&column==destiny->getColumn())
            {
                return cost;
            }
            else
            {
                Cell c=Cell(line,column);
                cost+=movementCost(&c,destiny);
                if(difL!=0)
                    line+=(difL/abs(difL));
                if(difC!=0)
                    column+=(difC/abs(difC));

            }
        }
    }
}
int Matrix::getGCost(Cell *askingC, List<Cell *> *closed,Cell* begining)
{
    Cell* cNeigh= nullptr;
    Node<Cell*>* temp=askingC->getNeighbours()->getHead();
    while(temp!= nullptr)
    {
        if(in(closed,temp->getValue()))
        {
            if(cNeigh== nullptr||cNeigh->getG()>temp->getValue()->getG())
            {
                cNeigh=temp->getValue();
            }
        }
        temp=temp->getNext();
    }
    if(cNeigh!= nullptr)
    {
        if (cNeigh->getLine() > askingC->getLine()||cNeigh->getLine() < askingC->getLine()) {
            if (cNeigh->getColumn() > askingC->getColumn()||cNeigh->getColumn() < askingC->getColumn())
            {
                return (14 + cNeigh->getG());
            }
            else
            {
                return (10 + cNeigh->getG());
            }
        }
        else
        {
            return (10 + cNeigh->getG());
        }

    }
    else
    {
        return 0;
    }
}


Node<Cell*>*Matrix::lowestF(List<Cell *> *list)
{
    Node<Cell*>* temp=list->getHead();
    Node<Cell*>* c= temp;
    while(temp!= nullptr)
    {
        if(temp->getValue()->getF()<c->getValue()->getF())
        {
            c=temp;
        }
        else if(temp->getValue()->getF()==c->getValue()->getF())
        {
            if(temp->getValue()->getH()<c->getValue()->getH())
            {
                c=temp;
            }
        }
        temp=temp->getNext();
    }
    return c;
}

bool Matrix::in(List<Cell *> *list, Cell *cell)
{
    Node<Cell*>*temp=list->getHead();
    while(temp!= nullptr)
    {
        if(temp->getValue()->getLine()==cell->getLine()&&temp->getValue()->getColumn()==cell->getColumn())
        {
            return true;
        }
        temp=temp->getNext();
    }
    return false;
}

bool Matrix::isShorter(Cell *testCell, Cell *newParentCell)
{
    if(testCell->getParent()== nullptr)
    {
        return true;
    }
    return(testCell->getG()>(newParentCell->getG()+movementCost(testCell,newParentCell)));
}

int Matrix::movementCost(Cell *begining, Cell *end)
{
    if((begining->getLine()>end->getLine()&&begining->getColumn()>end->getColumn())||(begining->getLine()>end->getLine()&&begining->getColumn()<end->getColumn())||(begining->getLine()<end->getLine()&&begining->getColumn()>end->getColumn())||(begining->getLine()<end->getLine()&&begining->getColumn()<end->getColumn()))
    {
        return 14;
    }
    return 10;
}

void Matrix::resetPath()
{
    for(int i=0;i<lines;i++)
    {
        for(int t=0;t<columns;t++)
        {
            get(i,t)->unsetAsPath();
        }
    }
}

void Matrix::resetAll()
{
    resetPath();
    for(int i=0;i<lines;i++)
    {
        for(int t=0;t<columns;t++)
        {
            get(i,t)->unsetAsObstacle();
        }
    }
    towers->purge();
}

bool Matrix::BacktrackingSolver(Cell* begining,Cell* end)
{
    begining->setAsPath();
    if(begining->getLine()==end->getLine()&&begining->getColumn()==end->getColumn())
    {
        resetPath();
        return true;
    }
    setNeighbours(begining);
    List<Cell*>* neighbours=begining->getNeighbours();
    Node<Cell*>* temp= neighbours->getHead();
    while(temp!= nullptr)
    {
        if(!temp->getValue()->isPath()&&!temp->getValue()->isObstacle())
        {
            if(BacktrackingSolver(temp->getValue(),end))
            {
                temp->getValue()->setParent(begining);
                return true;
            }
        }
        temp->getValue()->unsetParent();
        temp=temp->getNext();
    }
    return false;


}

string Matrix::directionGetter(Cell *b, Cell *e)
{
    if(b->getLine()<e->getLine())
    {
        if(b->getColumn()<e->getColumn())
        {
            return "DR";
        }
        else if(b->getColumn()>e->getColumn())
        {
            return "DL";
        }
        else
        {
            return "D";
        }
    }
    else if(b->getLine()>e->getLine())
    {
        if(b->getColumn()<e->getColumn())
        {
            return "UR";
        }
        else if(b->getColumn()>e->getColumn())
        {
            return "UL";
        }
        else
        {
            return "U";
        }
    }
    else
    {
        if(b->getColumn()<e->getColumn())
        {
            return "R";
        }
        else if(b->getColumn()>e->getColumn())
        {
            return "L";
        }
    }
}

void Matrix::randomObstacleSetter(Cell* start, Cell* end)
{
    random_device rd;
    static mt19937 rng(rd());
    static uniform_int_distribution<int> uni(0,9);
    for(int i=0;i<3;i++)
    {
        while (true) {
            srand(time(0));
            int line = uni(rng);
            int column = uni(rng);
            Cell *cell = get(line, column);
            if ((!isTheSame(cell, start) && !isTheSame(cell, end)) && !cell->isObstacle())
            {
                while(true)
                {
                    static uniform_int_distribution<int> typ(0, 2);
                    static uniform_int_distribution<int> prob(1, 100);
                    int type = typ(rng);
                    int probability=prob(rng);
                    if (type == 0 && probability<=70) {
                        cell->setObstascleType("simple");
                        this->setAsObstacle(line, column);
                        if(!BacktrackingSolver(start,end))
                        {
                            cell->unsetAsObstacle();
                        }
                        else
                        {
                            towers->add(cell);
                            break;
                        }
                    } else if (type == 1 && (probability>70&&probability<=90)) {
                        cell->setObstascleType("fire");
                        this->setAsObstacle(line, column);
                        if(!BacktrackingSolver(start,end))
                        {
                            cell->unsetAsObstacle();
                        }
                        else
                        {
                            towers->add(cell);
                            break;
                        }
                    } else if (type == 2&& (probability>90&&probability<=100)) {
                        cell->setObstascleType("explosive");
                        this->setAsObstacle(line, column);
                        if(!BacktrackingSolver(start,end))
                        {
                            cell->unsetAsObstacle();
                        }
                        else
                        {
                            towers->add(cell);
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
}

bool Matrix::isTheSame(Cell *c, Cell *e)
{
    return(c->getLine()==e->getLine()&&c->getColumn()==e->getColumn());
}

List<Cell *> *Matrix::getTowers()
{
    return this->towers;
}

bool Matrix::isInRange(Cell *c,Cell* T)
{
    if(T->isObstacle())
    {
        if(T->getObstacleType()=="simple")
        {
            if(abs(T->getLine()-c->getLine())<=1)
            {
                return(abs(T->getColumn()-c->getColumn())<=1);

            }
        }
        else if(T->getObstacleType()=="fire"||T->getObstacleType()=="explosive")
        {
            if(abs(T->getLine()-c->getLine())<=2)
            {
                return(abs(T->getColumn()-c->getColumn())<=2);

            }
        }
    }
    return false;
}

int Matrix::getDamage(Cell *c)
{
    Node<Cell*>* temp=towers->getHead();
    int damage=0;
    while(temp!= nullptr)
    {
        if(isInRange(c,temp->getValue()))
        {
            if(temp->getValue()->getObstacleType()=="fire")
            {
                damage+=2;
            }
            else if(temp->getValue()->getObstacleType()=="explosive")
            {
                damage+=4;
            }
            else if(temp->getValue()->getObstacleType()=="simple")
            {
                damage+=1;
            }
        }
        temp=temp->getNext();
    }
    return damage;
}
