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
/**
 * @version 1.0
 * @file Server.h
 * @
 *
 * author Daniel Camacho Gonzalez
 *
 */
using namespace std;

class Server {

private:
    Matrix* matriz;
    char buffer[1025];
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

    string receiveMessage();
};



#endif //GBP_SERVER_SERVER_H
