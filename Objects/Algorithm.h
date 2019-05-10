//
// Created by daniel on 29/04/19.
//

#ifndef GBP_SERVER_ALGORITHM_H
#define GBP_SERVER_ALGORITHM_H


#include "Population.h"
/**
 * @file ALgorithm.h
 * @date 26/04/19
 * @author Daniel garcia
 * @title Clase Algoritmo
 * @brief Clase encargada de los cruces mutaciones e inversiones
 */
class Algorithm {
    //parametos de GA

public:

public:
    /**
     * Crea una nueva generacion de individuos
     * @param pop poblacion de individuos
     * @return nueva poblacion
     */
    static Population envolvePopulation(Population * pop);

    /**
     * Funcion que cruza dos individuos
     * @param glad1 gladiador a cruzar
     * @param glad2 gladiador a cruzar
     * @return nuevo gladiador con las caracterizticas de ambos
     */
    static Gladiator crossover(Gladiator glad1 , Gladiator glad2 , bool flag);
    /**
     * Bajo cierta tasa de probabilidad , la funcion invierte los indices del vector de genes
     * @param indiv individuo al cual invertir
     * @return
     */
    static Gladiator inversion(Gladiator indiv);
    /**
     * Bajo cierta tasa de probabilidad , la funcion suma o resta a un gen
     * @param indiv individuo al que se le realizara la mutacion
     */
    static Gladiator mutate(Gladiator indiv);
    /**
     * Funcion que ordena los individuos de una poblacion segun su fitness
     * @param pop
     */
    static void sortPopulation(Population * pop);
    /**
     * Obtiene una generacion con un mejor fitness
     * @param pop poblacion a envolver
     * @return nueva generacion con fitness nuevo
     */
    static Gladiator getNext(Population * pop);







};



#endif //GBP_SERVER_ALGORITHM_H
