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
    int Length;
    int Ballspeeds[100];
    int Puntaje;
    int CantBloques;
    int CantBolas;
    int Profundidad;
    bool modoprofundo;

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
     * Se activa cuando el bloque roto contiene una sorpresa del largo de la barra
     * @param Buff (es aumento o disminución de velocidad
     */
    void LengthSurprise(bool Buff);
};



#endif //UNTITLED2_SERVER_H
