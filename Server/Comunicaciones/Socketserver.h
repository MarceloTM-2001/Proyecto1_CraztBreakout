//
// Created by marcelo on 21/9/21.
//

#ifndef UNTITLED2_SOCKETSERVER_H
#define UNTITLED2_SOCKETSERVER_H
#include "sys/socket.h"
#include "sys/types.h"
#include "netdb.h"
#include "string.h"
#include "string"
#include "iostream"
#include "pthread.h"
#include "vector"
#include "unistd.h"

using namespace std;

struct DataSocket{
    int descriptor;
    sockaddr_in info;
};

class SocketServer {
public:
    SocketServer();

    void run();

    void setMsj(const char *msn);

private:
    int descriptor;//Identifica los sistemas
    sockaddr_in info;//Informaci{on del socket servidor
    vector<int> clientes;//Almacena los clientes que se conecten

    bool createsocket();
    bool enlazarkernel();
    static void*ControladorCliente(void*obj);
};


#endif //UNTITLED2_SOCKETSERVER_H
