//
// Created by Lenovo on 20/9/2021.
//

#ifndef UNTITLED2_SERVER_H
#define UNTITLED2_SERVER_H
#include "LogisiticaBloques/Bloques.h"
#include "iostream"
#include "Comunicaciones/Msgcreator.h"
#include "sys/socket.h"
#include "sys/types.h"
#include "netdb.h"
#include "string.h"
#include "string"
#include "pthread.h"
#include "vector"
#include "unistd.h"


using namespace std;
/**
 * Estructura que contiene el descriptor e informaci{on necesaria de los sockets
 */
struct DataSocket{
    int descriptor;
    sockaddr_in info;
};


/**
 * Contiene toda la información relacionada al juego y la mantiene actualizadda en
 * base a los cambios ocurridos en la GUI.
 */
class server{
private:
    Msgcreator create();
    int descriptor;//Identifica los sistemas
    sockaddr_in info;//Información del socket servidor
    vector<int> clientes;//Almacena los clientes que se conecten

    bool createsocket();

    bool enlazarkernel();

    void*ControladorCliente(void*obj);


public:
    Bloques Grid;
    int Length;
    int Ballspeeds[100];
    int Puntaje;
    int CantBloques;
    int CantBolas;
    int Profundidad;
    bool modoprofundo;
    Msgcreator msgcreator;

    server();

    /**
     * se perdió una bola
     * @param index (bola que se perdió)
     */
    void LostBall(int index);

    /**
     * Se recibe un mensaje de la clase usuario y se debe interpretar
     * @param msg
     */
    void MessageReciever(string msg);


    /**
     * El usuario se gana la una bola
     */
    void GainedBall();

    /**
     * Si un bloque contiene sorpresa, hace los cambios necesarios
     * @param surprise
     */
    void Managesurprise(string surprise);


    /**
    * El usuario activó o desactivó el modo profundo
    * @param Activate
    */
    void ProfunActive(bool Activate);

    /**
     * Maneja toda la información que conlleva el golpe a una bola
     * @param i
     * @param j
     */
    void Ballhit(int i,int j);

    /**
     * Se activa cuando el bloque roto contiene una sorpresa de veocidad
     * @param Buff (es aumento o disminución de velocidad)
     */
    void SpeedSurprise(bool Buff);

    /**
     * Cambia la velocidad de una sola bola por el golpe en giro de la barra
     * @param i
     */
    void Speedhit(int i);

    /**
     * Se activa cuando el bloque roto contiene una sorpresa del largo de la barra
     * @param Buff (es aumento o disminución de velocidad)
     */
    void LengthSurprise(bool Buff);
/**
 * Transforma los bloques en una matriz
 * @return Matriz en fomato string
 */
    string Martrparser();

    string Speedparser();

    void initialinfo();
//--------------------Funciones Comunicación Sockets------------------
 void run();

 void setMsj(const char *msn);

};





#endif //UNTITLED2_SERVER_H
