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
    Bloque *grid[6];//

public:

    Bloque** getgrid();

    /**
     * Devuelve un bloque en específico de la matriz
     * @param i (Posición fila)
     * @param j (Posición columna)
     * @return Bloque de la posición indicada
     */
    Bloque getBlock(int i,int j);

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
};
#endif //UNTITLED2_BLOQUES_H
