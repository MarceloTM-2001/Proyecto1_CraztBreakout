//
// Created by Lenovo on 20/9/2021.
//

#ifndef UNTITLED2_BLOQUE_H
#define UNTITLED2_BLOQUE_H

#include "string"
using namespace std;


/**
 * Clase Bloque define las características principales que deben de tener los bloques
 * es la clase padre de todos los bloques
 */
class Bloque{
private:
    string Sorpresa; //Tipo de sorpresa
    int destroyed();//Se destruyó el bloque

public:
    int vida;
    int puntos;
    string tipo;

    string getSorpresa();

    void setSorpresa(string Sorpresa);

    /**
     * Define si el bloque contiene o no sorpresa
     * La probabilidad de tener sorpresa es del 25%
     * La probabilidad de una sorpresa 25%
     * La probabilidad de todas las sorpresas es la misma 25%,
     * Por ende la probabilidad de que ub bloque contenga una sorpresa en específico es de 6.25%
     */
    void virtual defineSorpresa();

    /**
     * Un bloque recibió un golpe de una bola
     *
     * @return La cantidad de puntos que se deben sumar por el golpe
     * No se suman si el bloque no se destruyó
     */
    int virtual hit();
};


#endif //UNTITLED2_BLOQUE_H
