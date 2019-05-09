//
// Created by daniel on 29/04/19.
//


#ifndef GBP_SERVER_POPULATION_H
#define GBP_SERVER_POPULATION_H

#include "Gladiator.h"
/**
 * @file Population.h
 * @date 26/04/19
 * @author Daniel garcia
 * @title Clase Poblacion
 * @brief Clase que contiene una estructura con individuos
 */
class Population {
    // Se creara una poblacion con un tamaño de 90 para poder juntar siempre los nueve mejores de forma
    // 1 con todos , 2 con todos .. . sucesivamente sumando 45 , pero de cada cruce se pueden generar dos individuos
    // dando 90 otra vez

    // ahora se puede calcular cualquier poblacion pues ya no se seguirá ese formato , se debe guardar al mejor en
    // la siguiente generacion
    Gladiator * fittest;
    vector<Gladiator>  individuals;

public:

    /**
     * Constructor de la clase population
     * @param populationSize tamaño de la poblacion
     * @param initialise indicador para inicializar en random los individuos
     */
    Population(int populationSize , bool initialise);
    /**
     * Obtiene el objeto gladiador almacenado en un indice del vector
     * @param index indice en el cual se encuentra el gladiador
     * @return gladiador contenido en el indice del vector
     */
    Gladiator getGladiator(int index);
    /**
     * Retorna el Gladiador con el mejor fitness de la poblacion
     * @return gladiador con el mejor fitness
     */
    Gladiator getFittest();
    /**
     * Obtiene el tamaño de la poblacion
     * @return tamaño
     */
    int getSize();
    /**
     * Guarda un individuo en una posicion del vector
     * @param index
     * @param gladiator
     */
    void saveIndividual(int index , Gladiator gladiator);
    /**
     * Agrega un indiiduo al final del vector
     * @param gladiator a agregar
     */
    void saveInitIndi(Gladiator gladiator);
    /**
     * Eliina un gladiador del vector
     * @param num numero de indice a eliminar
     */
    void deleteGladiator(int num);
    /**
     * Obtiene el vector que almacena a los individuos
     * @return vector de tipo gladiador
     */
    vector<Gladiator> getIndividuals();
    /**
     * Calcula el porcentaje de supervivencia de cada gladiador dentro del vector
     */
    void calcALLProbability();

};

#endif //GBP_SERVER_POPULATION_H
