//
// Created by daniel on 24/04/19.
//


#ifndef GBP_SERVER_GLADIATOR_H
#define GBP_SERVER_GLADIATOR_H


#include <string>
#include <string.h>
#include <zconf.h>
#include <vector>



/**
 * @file Gladiator.h
 * @date 26/04/19
 * @author Daniel garcia
 * @title Clase individuo
 * @brief Clase que abstrae la informacion de un individuo
 */
using namespace std;


class Gladiator {
public:
    void setFitness(int fitness);

private:
    int id, age ,estimatedG , emotionalI, physical , upper , lower, resistance;
    string inversion , mutation;
    string myGenes , father , mother ;
    float fitness ,probability;

    vector<int> genes ;


public:
    /**
     * @brief Constructores de la clase gladiator
     */
    Gladiator();
    /**
     * @brief Constructor de la clase con parametros
     * @param ag edad
     * @param emot inteligencia emocional
     * @param phy condicion fisica
     * @param up fuerza en el tronco superior
     * @param low fuerza en el tronco inferior
     */
    Gladiator(int up , int low , int emo , int phy , int age);
    /**
     * @brief Inicializa los atributos del gladiador
     */
    void init();
    /**
     * @brief Inicializa al gladiador de manera aleatoria
     */
    void generateIndividual();
    /**
     * Convierte un vector binario en un numero decimal
     * @param v vector a convertir
     * @return numero decimal
     */
    int binTodec(vector<int> v);
    /**
     * Convierte un numero decimal en un vector binario
     * @param num numero a convertir
     * @return vector binario
     */
    vector<int> *decTobin(int num);
    /**
     * Calcula la resistencia en base a sus atributos
     * @return la resistencia calculada
     */
    bool calculateResistance();
    /**
     * Retorna el largo de la cadena de genes
     * @return
     */
    int size();
    /**
     * Setea valor a un gen especifico de la cadena
     */
    void setGenes(int index , int gene);
    /**
     * Obtiene un gen especifico de la cadena
     * @param index
     * @return
     */
    int getGene(int index);
    /**
     * Devuelve el fitness del individuo
     * @return fitness
     */
    float getFitness();
    /**
     * Imprime los genes del individuo , los genes se refiere a cada atributo del individuo
     * @return
     */
    string genesToString();
    /**
     * Añade al vector de genes los parametros indicados
     * @param upper fuerza en el tronco superior
     * @param lower fuerza en el tronco inferior
     * @param emoti inteligencia emocional
     * @param phy condicion fisica
     * @param age edad
     */
    void setAtributeTovector(int upper , int lower , int emoti , int phy , int age);
    /**
     * OBtiene el vector de genes del individuo
     * @return vector de genes
     */
    vector<int> getGENES();
    /**
     * Toma los indices del vector de genes para asignar valor a los atributos del gladiador
     */
    void setVectorToAtributes();


    //setters y getters comunes
    /**
     * Obtiene el id del gladiador
     * @return id
     */
    int getId();
    /**
     * Obtiene la edad del gladiador
     * @return age
     */
    int getAge();
    /**
     * Asigna valor a la edad del gladiador
     * @param age edad a asignar
     */
    void setAge(int age);
    /**
     * Obtiene la probabilidad de que el individuo siga vivo
     * @return probability
     */
    float getProbability();
    /**
     * Asigna valor a la probability del gladiador
     * @param probability probabilidad de sobrevivir
     */
    void setProbability(int probability);
    /**
     * Retorna el numero de generaciones que podria llegar a vivir
     * @return estimatedG
     */
    int getEstimatedG();
    /**
     * Asigna valor a la cantidad de generaciones que podria sobrevivir el gladiador
     * @param estimatedG cantidad de generaciones a sobreviir
     */
    void setEstimatedG(int estimatedG);
    /**
     * Obtiene la inteligencia emocional del gladiador
     * @return emotionalI
     */
    int getEmotionalI();
    /**
     * Asigna valor a la inteligencia emocional del gladiador
     * @param emotionalI
     */
    void setEmotionalI(int emotionalI);
    /**
     * Obtiene la condicion fisica del gladiador
     * @return phisical
     */
    int getPhysical();
    /**
     * Asigna valor a la condicion fisica del gladiador
     * @param physical condicion fisica
     */
    void setPhysical(int physical);
    /**
     * Obtiene la fuerza en el tronco superior
     * @return upper
     */
    int getUpper();
    /**
     * Asigna valor a la fuerza superior del gladiador
     * @param upper fuerza en el tronco superior
     */
    void setUpper(int upper);
    /**
     * Obtiene la fuerza en el tronco inferior
     * @return
     */
    int getLower();
    /**
     * Asigna valor a la fuerza en el tronco inferior del gladiador
     * @param lower fuerza en el tronco inferior
     */
    void setLower(int lower);
    /**
     * Obtiene la resistencia del gladiador
     * @return resistance
     */
    int getResistance();
    /**
     * Asigna valor a la resistencia del gladiador
     * @param resistance resistencia
     */
    void setResistance(int resistance);
    /**
     * Calcula la probabilidad de supervivencia del gladiador
     */
    void calculateProbability();
    /**
     * Asigna valor al vector de genes del gladiador
     * @param g
     */
    void setGENE(vector<int> g);
    /**
     * Asigna un string para saber si invirtio
     * @param invert
     */
    void setInversionString(string invert);
    /**
     * Asigna un string para saber si muto
     * @param mutate
     */
    void setMuatationString(string mutate);
    /**
     * Asigna los genes de los padres
     * @param f
     * @param m
     */
    void setFathers(string f , string m);
    /**
     * Obtiene informacion sobre si mutó
     * @return
     */
    string getMutation();
    /**
     * Obtiene informacion sobre si se produjo inversion
     * @return
     */
    string getInversion();
    /**
     * Obtiene informacion acerca de los genes de la madre
     * @return
     */
    string getMother();
    /**
     * Obtiene informacion acerca de los genes del padre
     * @return
     */
    string getFather();







};


#endif //GBP_SERVER_GLADIATOR_H
