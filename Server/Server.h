//
// Created by dcamachog1501 on 10/04/19.
//

#ifndef GBP_SERVER_SERVER_H
#define GBP_SERVER_SERVER_H


#include <string>
#include <string.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include "../Logic/Matrix.h"
#include "../Logic/JSONManager.h"
#include "../Objects/Gladiator.h"
#include "../Objects/Population.h"
#include "../Objects/Algorithm.h"
/**
 * @version 1.0
 * @file Server.h
 *
 * author Daniel Camacho Gonzalez
 *
 */
using namespace std;

class Server {

private:
    Matrix* matriz;

    Population* popAstar;
    Population* popBack;


    char buffer[2048];
    int socketC;
    JSONManager* Jmanager;
public:
    Server();
    /**
     * Metodo para inicializar el server
     */
    void init();
    /**
     * Funcion para mandar mensajes al cliente
     * @param socketclient socket por el cual se envia el mensaje
     * @param s mensaje a enviar
     */
    void sendMessage(string s);
    /**
     * Metodo para recibir mensajes del cliente.
     * @return Mensaje recibido del cliente.
     */
    string receiveMessage();
    /**
     * Metodo para convertir un objeto gladiador en un JSON.
     * @param G Gladiador a convertir.
     * @return JSON de gladiador ya convertido.
     */
    string GladToJSON(Gladiator G);
};



#endif //GBP_SERVER_SERVER_H
