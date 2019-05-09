//
// Created by daniel on 29/04/19.
//

#ifndef GBP_SERVER_FITNESS_H
#define GBP_SERVER_FITNESS_H


#include <iostream>
#include <vector>
#include "Gladiator.h"

using  namespace std;
/**
 * @file Fitness.h
 * @date 26/04/19
 * @author Daniel garcia
 * @title Clase Fitness
 * @brief Clase que calcula el fitness de los individuos
 */
class Fitness {

public:
    /**
     * Setea un valor de fitness maximo a alcanzar
     * @param sol valor maximo de fitness
     */
    static void setSolution(float sol);
    /**
     * Recibe un objeto gladiador y calcula su fitness de acuerdo a sus atributos
     * @param gladiator objeto a evaluar
     * @return el valor del fitness para ese individuo
     */
    static float getFitness(Gladiator gladiator);
    static float getMaxFitness();


};



#endif //GBP_SERVER_FITNESS_H
