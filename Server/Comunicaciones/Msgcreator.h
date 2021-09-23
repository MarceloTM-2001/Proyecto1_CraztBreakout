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

    string getmsj();

    string sendhit(int i, int j);

    string sendspeeds(int speeds[100],int cantbolas);

    string sendblocks(int *Blocks[]);

    string senddestroyed(int i , int j);



};


#endif //UNTITLED2_MSGCREATOR_H
