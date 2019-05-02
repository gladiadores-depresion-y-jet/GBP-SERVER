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
    Cell* AstarHead;
    int AstarSteps;
    Cell* BacktrackingHead;
    int BacktrackSteps;

public:
    /**
     * Constructor estandar de la clase Matrix.
     */
    Matrix();
    /**
     * Metodo para llenar la matriz hasta el limite de filas y el limite de columnas
     * @param limit Limite de filas/columnas.
     */
    void fill(int limit);
    /**
     * Metodo para imprimir la matriz en consola.
     */
    void print();
    /**
     * Metodo para obtener la celda ubicada en la fila y columna indicadas.
     * @param f Fila de la celda a obtener .
     * @param c Columna de la celda a obtener.
     * @return Celda deseada.
     */
    Cell* get(int f,int c);
    /**
     * Metodo para establecer la lista de vecinos de una celda
     * @param cell Celda a la que se le quiere asignar sus vecinos.
     */
    void setNeighbours(Cell* cell);
    /**
     * Metodo para obtener el vecino de una celda en una posicion especifica.
     * @param c Celda en cuestion.
     * @param position Posicion del vecino.
     * @return Celda del vecino indicado.
     */
    Cell* getNeighbour(Cell* c,string position);
    /**
     * Metodo para establecer una celda como obstaculo;
     * @param l Fila de la celda.
     * @param c Columna de la celda.
     */
    void setAsObstacle(int l,int c);
    /**
     * Metodo para determinar el factor H de una celda dada.
     * @param askingC Celda en cuestion.
     * @param end Celda objetivo.
     * @return Factor H de la celda en cuestion.
     */
    int getHCost(Cell* askingC,Cell* end);
    /**
     * Metodo para determinar el factor G de una celda en cuestion.
     * @param askingC Celda en cuestion.
     * @param closed Lista de celdas que representan parte de la solucion.
     * @param begining Celda inicial.
     * @return Factor G de la celda en cuestion.
     */
    int getGCost(Cell* askingC,List<Cell*>* closed,Cell* begining);
    /**
     * Metodo del algoritmo A*.
     * @param lstart Fila de la celda inicial.
     * @param cstart Columna de la celda inicial.
     * @param lfinish Fila de la celda final.
     * @param cfinish Columna de la celda final.
     */
    Cell* AstarFindPath(int lstart,int cstart,int lfinish,int cfinish);
    /**
     * Metodo del algoritmo de Backtracking.
     * @param lstart Fila de la celda inicial.
     * @param cstart Columna de la celda inicial.
     * @param lfinish Fila de la celda final.
     * @param cfinish Columna de la celda final.
     */
    void BacktrackingFindPath(int lstart,int cstart,int lfinish,int cfinish);
    /**
     * Metodo para obtener el nodo que contiene la celda de menor F en una lista.
     * @param list Lista en cuestion.
     * @return Nodo que contiene la celda de menor F.
     */
    Node<Cell*>* lowestF(List<Cell*>* list);
    /**
     * Metodo para determinar si una celda dada esta dentro de una lista en cuestion.
     * @param list Lista en cuestion.
     * @param cell Celda dada
     * @return Declaracion de si la celda se encuentra en la lista.
     */
    bool in(List<Cell*>* list,Cell* cell);
    /**
     * Metodo para determinar si el factor G de una celda es menor desde su nuevo padre.
     * @param testCell Celda en cuestion.
     * @param newParentCell Nueva celda padre.
     * @return Declaracion de si el camino es menor desde el nuevo padre.
     */
    bool isShorter(Cell* testCell,Cell* newParentCell);
    /**
     * Metodo parra determinar el costo de moverse en una direccion.
     * @param begining Celda inicial.
     * @param end Celda final.
     * @return Costo de moverse en esa direccion.
     */
    int movementCost(Cell* begining,Cell* end);
    /**
     * Metodo para borrar el camino ya establecido en la matriz.
     */
    void resetPath();
    /**
     * Metodo parra borar el camino ya establecido y todos los obstaculos de la matriz.
     */
    void resetAll();
    /**
     * Metodo recursivo del algoritmo de backtracking.
     * @param b Celda inicial.
     * @param e Celda final.
     * @return Declaracion de si existe al menos un camino.
     */
    bool BacktrackingSolver(Cell* b,Cell* e);
    /**
     * Metodo pra obtener en que direccion se encuentra una celda respecto a otra.
     * @param b Celda inicial.
     * @param e Celda final.
     * @return Direccion la que se encuentra la celda final.
     */
    string directionGetter(Cell* b,Cell* e);
    /**
     * Metodo para saber si doos celda socupan el mismo lugar.
     * @param c Celda en cuestion.
     * @param e Celda en cuestion.
     * @return Declaracion de si la celda es la misma.
     */
    bool isTheSame(Cell* c,Cell *e);
    /**
     * Metodo para crear torres al azar en la matriz actual.
     * @param b Inicio del recorrido en ejecucion.
     * @param e Final del rercorrido en ejecucion.
     */
    void randomObstacleSetter(Cell* b,Cell* e);
    /**
     * Metoddo para obtener la lista de torres de la matriz.
     * @return Lista de torres de la matriz.
     */
    List<Cell*>* getTowers();
    /**
     * Metodo para saber si una celda esta en el rango de tiro de una torre.
     * @param c Celda en cuestion.
     * @param T Celda de la torre.
     * @return Declaracion de si la celda esta en el rango de tiro de la torre.
     */
    bool isInRange(Cell* c,Cell* T);
    /**
     * Metodo para obtener el dano que sufriria un galdiador en una celda determinada.
     * @param c Celda en cuestion
     * @return Dano que recibiria el gladiador.
     */
    int getDamage(Cell* c);
    Cell* getStep(int i,string type);

};


#endif //GBP_SERVER_MATRIX_H
