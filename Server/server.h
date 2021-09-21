//
// Created by Lenovo on 20/9/2021.
//

#ifndef UNTITLED2_SERVER_H
#define UNTITLED2_SERVER_H
#include "LogisiticaBloques/Bloques.h"

/**
 * Contiene toda la información relacionada al juego y la mantiene actualizadda en
 * base a los cambios ocurridos en la GUI.
 */
class server{
public:
    Bloques Grid;
    int Ballspeeds[100];
    int Puntaje;
    int CantBloques;
    int CantBolas;
    int Profundidad;

    server();

    /**
     * se perdió una bola
     * @param index (bola que se perdió)
     */
    void LostBall(int index);

    /**
     * Cuando se gana la una bola
     */
    void GainedBall();

    /**
     * Se activa cuando el bloque roto contiene una sorpresa
     * @param Buff (es aumento o disminución de velocidad
     */
    void SpeedSurprise(bool Buff);
};



#endif //UNTITLED2_SERVER_H
