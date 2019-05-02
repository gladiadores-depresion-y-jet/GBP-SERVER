//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef GBP_SERVER_MATRIX_H
#define GBP_SERVER_MATRIX_H


#include "Cell.h"
#include "../Structures/List.h"

class Matrix
{
private:
    List<Cell*>*head;
    List<Cell*>* towers;
    int lines;
    int columns;

public:
    Matrix();
    void fill(int limit);
    void print();
    Cell* get(int f,int c);
    void setNeighbours(Cell* cell);
    Cell* getNeighbour(Cell* c,string position);
    void setAsObstacle(int l,int c);
    int getHCost(Cell* askingC,Cell* end);
    int getGCost(Cell* askingC,List<Cell*>* closed,Cell* begining);
    void AstarFindPath(int lstart,int cstart,int lfinish,int cfinish);
    void BacktrackingFindPath(int lstart,int cstart,int lfinish,int cfinish);
    Node<Cell*>* lowestF(List<Cell*>* list);
    bool in(List<Cell*>* list,Cell* cell);
    bool isShorter(Cell* testCell,Cell* newParentCell);
    int movementCost(Cell* begining,Cell* end);
    void resetPath();
    void resetAll();
    bool BacktrackingSolver(Cell* b,Cell* e);
    string directionGetter(Cell* b,Cell* e);
    bool isTheSame(Cell* c,Cell *e);
    void randomObstacleSetter(Cell* b,Cell* e);
    List<Cell*>* getTowers();
    bool isInRange(Cell* c,Cell* T);
    int getDamage(Cell* c);

};


#endif //GBP_SERVER_MATRIX_H
