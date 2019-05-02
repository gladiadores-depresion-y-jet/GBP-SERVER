//
// Created by dcamachog1501 on 09/03/19.
//

#ifndef GBP_SERVER_JSONMANAGER_H
#define GBP_SERVER_JSONMANAGER_H
#include <algorithm>
#include <boost/property_tree/json_parser.hpp>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include "Matrix.h"

using namespace std;

using boost::property_tree::ptree;

class JSONManager {

public:
    /**
     * Constructor de la clase JSONManager.
     */
    JSONManager();
    /**
     * Metodo para convertir a formato JSON.
     * @param s String a convertir.
     * @return Resultado de tipo string.
     */
    string toJSON(string s);
    /**
     * Metodo para convertir un JSON en Ptree;
     * @param s String a convertir.
     * @return Resultado de tipo Ptree.
     */
    ptree toPtree(string s);
    /**
     * Metodo para obtener el valor de una llave en un JSON.
     * @return Valor de tipo string.
     * @param JSON JSON del cual se quiere obtener un valor.
     * @param llave Llave del valor.
     */
    string askFor(string JSON,string llave);
    /**
     * Metodo para transformar una matriz en un JSON.
     * @param m Matriz de tipo Matrix.
     * @return Matriz en formato JSON.
     */
    string matrixtoJSON(Matrix* m);
    /**
     * Metodo para convertir un JSON a una matriz.
     * @param JSON String que representa una matriz en formato JSON.
     * @return Objeto de tipo Matriz.
     */
    Matrix JSONtomatrix(string JSON);

};


#endif //GBP_SERVER_JSONMANAGER_H