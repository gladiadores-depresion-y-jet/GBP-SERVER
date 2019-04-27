//
// Created by dcamachog1501 on 10/04/19.
//

#include <iostream>
#include <stdio.h>
#include <string.h>   //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>   //close
#include <arpa/inet.h>    //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <random>
#include <ctime>
#include <boost/algorithm/string.hpp>
#include <thread>
#include<thread>
#include "Server.h"

#define TRUE   1
#define PORT 54000

using namespace std;

Server::Server()

{
    init();
}

void Server::init() {

    int opt = TRUE;
    int master_socket , addrlen , new_socket ,activity, message , sd;
    int max_sd;
    int socketC=0;
    bool running=true;
    struct sockaddr_in address;

    char buffer[1025];

    fd_set readfds;

    if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                   sizeof(opt)) < 0 )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    printf("Listener on port %d \n", PORT);

    if (listen(master_socket, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    addrlen = sizeof(address);
    puts("Waiting for connections ...");

    while (running)
    {
        FD_ZERO(&readfds);

        FD_SET(master_socket, &readfds);
        max_sd = master_socket;

        sd = socketC;

        if(sd > 0)
            FD_SET( sd , &readfds);

        if(sd > max_sd)
            max_sd = sd;

        activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);

        if ((activity < 0) && (errno!=EINTR))
        {
            printf("select error");
        }

        if (FD_ISSET(master_socket, &readfds))
        {
            if ((new_socket = accept(master_socket,
                                     (struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));

            if(socketC==0){

                socketC=new_socket;
                sennd(socketC,"acepted");
            }
            else
            {
                sennd(new_socket,"denied");
            }

        }

        sd =socketC;

        if (FD_ISSET( sd , &readfds)) {
            //Check if it was for closing , and also read the
            //incoming greet
            if ((message = read(sd, buffer, 1024)) == 0) {
                //Somebody disconnected , get his details and print
                getpeername(sd, (struct sockaddr *) &address, \
                        (socklen_t *) &addrlen);
                printf("Host disconnected , ip %s , port %d \n",
                       inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                //Close the socket and mark as 0 in list for reuse
                close(sd);
            }
            else

            {
                //Aqui se ponen los casos de entrada.
            }
        }
    }
}



void Server::sennd(int socketclient, string s) {

    send(socketclient, s.c_str(), s.size() + 1, 0);
}
