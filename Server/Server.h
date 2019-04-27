//
// Created by dcamachog1501 on 10/04/19.
//

#ifndef GBP_SERVER_SERVER_H
#define GBP_SERVER_SERVER_H


#include <string>
#include <string.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
/**
 * @version 1.0
 * @file Server.h
 * @
 *
 * author Daniel García Fallas
 *
 */
using namespace std;

class Server {


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
    void sennd(int socketclient , string s);
};



#endif //GBP_SERVER_SERVER_H
