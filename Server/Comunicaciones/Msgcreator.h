//
// Created by marcelo on 21/9/21.
//

#ifndef UNTITLED2_MSGCREATOR_H
#define UNTITLED2_MSGCREATOR_H
#include "string"
using namespace std;

class Msgcreator {
private:
    string Msj;
public:

/**
 * Inicializa el mensaje a enviar
 */
    void stringclean();

    string sendlen(int len);

    string sendprof(int prof);

    string sendpoints(int points);

    string endgame(bool condition);

    string sendspeeds(string Speeds);

    string sendblocks(string Blocks);

    string senddestroyed(int i , int j);

    string sendprofactivation(bool active);



};


#endif //UNTITLED2_MSGCREATOR_H
