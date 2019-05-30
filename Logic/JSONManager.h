//
// Created by dcamachog1501 on 09/03/19.
//

#ifndef GBP_SERVER_JSONMANAGER_H
#define GBP_SERVER_JSONMANAGER_H
#include <algorithm>
//#include <boost/property_tree/json_parser.hpp>
#include <vector>
//#include <boost/algorithm/string.hpp>
#include <string>
//#include <boost/property_tree/ptree.hpp>
#include <iostream>
#include "Matrix.h"

using namespace std;

//using boost::property_tree::ptree;

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

};


#endif //GBP_SERVER_JSONMANAGER_H