//
// Created by Lenovo on 20/9/2021.
//

#ifndef UNTITLED2_BLOQUES_H
#define UNTITLED2_BLOQUES_H

#include "Bloque.h"
#include "BloqueComun.h"
#include "BloqueDoble.h"
#include "BloqueTriple.h"
#include "BloqueInterno.h"
#include "BloqueProfundo.h"

/**
 * Matriz que contiene un grid de los bloques
 * Contiene operaciones necesarias para el tablero
 */
class Bloques{

private:
    int ajusteprofundos=0;
    int profundos[2]={-1,-1};
    int cantprofundos=-1;

public:
    Bloque grid[6][13];

    /**
     * Llena el grid de bloques
     * La probabilidad se ajusta de manera que solo puedan haber dos sets de bloques profundos por juego
     * Probabilidades:
     * Común=30%->40%->50% (después del ajuste de profundos)
     * Doble=30%
     * Triple=20%
     * Profundo=20%->10%->0% (después del ajuste de profundos)
     */
    void fillgrid();

    int getCantProf();
};
#endif //UNTITLED2_BLOQUES_H
