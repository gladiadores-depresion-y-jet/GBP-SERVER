//
// Created by dcamachog1501 on 24/04/19.
//

#ifndef GBP_SERVER_CELL_H
#define GBP_SERVER_CELL_H

#include <vector>
#include <string>
#include "../Structures/List.h"

using namespace std;
class Cell
{
private:
    int column;
    int line;
    int G;
    int H;
    bool obstacle;
    string obstacleType;
    bool path;
    Cell* parent;
    List<Cell*>* neighbours;
public:
    /**
     * Constructor estandar de la clase Cell;
     */
    Cell();
    /**
     * Constructor de la clase Cell.
     * @param l Valor de la fila de la celda.
     * @param c Calor de la columna de la celda.
     */
    Cell(int l,int c);
    /**
     * Metodo para obtener el valor de la columna de la celda.
     * @return Columna de tipo entero.
     */
    int getColumn();
    /**
     * Metodo para obtener el valor de la fila de la celda.
     * @return Fila de tipo entero.
     */
    int getLine();
    /**
     * Metodo para obtener el factor F de la celda.
     * @return F de tipo entero.
     */
    int getF();
    /**
     * Metodo para obtener el factor H de la celda.
     * @return H de tipo entero.
     */
    int getH();
    /**
     * Metodo para obtener el factor G de la celda.
     * @return G de tipo entero.
     */
    int getG();
    /**
     * Metodo para establecer el valor de la fila de la celda.
     * @param l Valor que se le va a asignar a la fila de la celda.
     */
    void setLine(int l);
    /**
     * Metodo para establecer el valor de la columna de la celda.
     * @param c Valor que se le va a asignar a la columna de la celda.
     */
    void setColumn(int c);
    /**
     * Metodo para establecer el factor G de la celda.
     * @param g Valor que se le va a asignar al factor G de la celda.
     */
    void setG(int g);
    /**
     * Metodo para establecer el factor H de la celda.
     * @param h Valor que se le va a asignar al factor H de la celda.
     */
    void setH(int h);
    /**
     * Metodo para anadir un vecino a la celda.
     * @param n Celda que se va a anadir a la lista de vecinos de la celda actual.
     */
    void addNeighbour(Cell* n);
    /**
     * Metodo para establecer una celda como obstaculo.
     */
    void setAsObstacle();
    /**
     * Metodo para saber si una celda es un obstaculo.
     * @return Declaracion de si la celda es o no es un obstaculo.
     */
    bool isObstacle();
    /**
     * Metodo para determinar si una celda es parte del camino a la solucion.
     * @return Declaracion de si la celda es o no es parte del camino a la solucion.
     */
    bool isPath();
    /**
     * Metodo para establecer que una celda es parte del camino a la solucion.
     */
    void setAsPath();
    /**
     * Metodo pra obtener la lista de vecinos de la celda actual.
     * @return Lista de vecinos.
     */
    List<Cell*>* getNeighbours();
    /**
     * Metodo para obtener el padre de la celda actual
     * @return Celda padre de la celda actual.
     */
    Cell *getParent();
    /**
     * Metodo para establecer la celda padre de la celda actual.
     * @param c Celda padre.
     */
    void setParent(Cell *c);
    /**
     * Metodo para establecer que la celda ya no forma parte del camino a la solucion.
     */
    void unsetAsPath();
    /**
     * Metodo para estableceer que la celda ya no es un obstaculo.
     */
    void unsetAsObstacle();
    /**
     * Metodo para desasociar la celda actual de su celda padre.
     */
    void unsetParent();
    /**
     * Metodo para establecer el tipo de obstaculo que representa la celda actual.
     * @param t Tipo de obstaculo.
     */
    void setObstascleType(string t);
    /**
     * Metodo para obtener el tipo de obstaculo que representa la celda actual.
     * @return Tipo de obstaculo.
     */
    string getObstacleType();
};


#endif //GBP_SERVER_CELL_H
