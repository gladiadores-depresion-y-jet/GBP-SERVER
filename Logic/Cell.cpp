//
// Created by dcamachog1501 on 24/04/19.
//

#include "Cell.h"

Cell::Cell()
{
    this->obstacle=false;
    this->obstacleType="Undefined";
    this->path=false;
    this->column=0;
    this->line=0;
    this->G=0;
    this->H=0;
    this->parent= nullptr;
    this->neighbours=new List<Cell*>;
}

Cell::Cell(int l, int c)
{
    this->obstacle=false;
    this->obstacleType="Undefined";
    this->column=c;
    this->line=l;
    this->G=0;
    this->H=0;
    this->parent= nullptr;
    this->neighbours=new List<Cell*>;
}

int Cell::getColumn()
{
    return this->column;
}

int Cell::getLine()
{
    return this->line;
}

int Cell::getF()
{
    return (this->G+this->H);
}

int Cell::getH()
{
    return this->H;
}

void Cell::setLine(int l)
{
    this->line=l;
}

void Cell::setColumn(int c)
{
    this->column=c;
}
void Cell::setG(int g)
{
    this->G=g;
}

void Cell::setH(int h)
{
    this->H=h;
}

void Cell::addNeighbour(Cell *n)
{
    this->neighbours->add(n);
}

void Cell::setAsObstacle()
{
    this->obstacle=true;
}

bool Cell::isObstacle()
{
    return this->obstacle;
}

int Cell::getG() {
    return this->G;
}
bool Cell::isPath()
{
    return path;
}

void Cell::setAsPath()
{
    this->path=true;
}

List<Cell *> *Cell::getNeighbours()
{
    return this->neighbours;
}
Cell* Cell::getParent()
{
    return this->parent;
}
void Cell::setParent(Cell* c)
{
    this->parent=c;
}
void Cell::unsetAsPath()
{
    this->path=false;
}
void Cell::unsetAsObstacle()
{
    this->obstacle=false;
    this->obstacleType="Undefined";
}

void Cell::unsetParent()
{
    this->parent= nullptr;
}

void Cell::setObstascleType(string t)
{
    this->obstacleType=t;
}

string Cell::getObstacleType() {
    return this->obstacleType;
}
