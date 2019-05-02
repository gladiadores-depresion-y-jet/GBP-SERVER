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

void Server::init()
{
    this->Jmanager= new JSONManager();
    this->matriz= new Matrix();
    this->matriz->fill(10);
    Cell* beg=this->matriz->get(0,0);
    Cell* end=this->matriz->get(9,9);
    for(int i=0;i<10;i++)
    {
        matriz->randomObstacleSetter(beg,end);
    }
    this->matriz->AstarFindPath(0,0,9,9);
    this->matriz->print();

    int opt = TRUE;
    int master_socket , addrlen , new_socket ,activity, message , sd;
    int max_sd;
    this->socketC=0;
    bool running=true;
    struct sockaddr_in address;

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
                sendMessage("acepted");
            }
            else
            {
                sendMessage("denied");
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
                string message=buffer;
                if(message=="position")
                {
                    sendMessage("send");
                    string s= receiveMessage();
                    vector<string> input;
                    boost::split(input,s, boost::is_any_of("$"));
                    int pos=stoi(input.at(1));
                    Cell* c=this->matriz->getStep(pos,input.at(0));
                    string out=Jmanager->toJSON("line@"+to_string(c->getLine())+"$column@"+to_string(c->getColumn()));
                    sendMessage(out);

                }
            }
        }
    }
}



void Server::sendMessage(string s) {

    send(this->socketC, s.c_str(), s.size() + 1, 0);
}
string Server::receiveMessage()
{
    int r = read(this->socketC, buffer, 1024);
    string g = string(buffer, 0, r);
    memset(buffer, 0, 1024); //clean the buffer
    return g;
}
