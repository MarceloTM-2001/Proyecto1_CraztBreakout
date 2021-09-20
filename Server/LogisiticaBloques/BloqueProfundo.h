//
// Created by Lenovo on 20/9/2021.
//

#ifndef UNTITLED2_BLOQUEPROFUNDO_H
#define UNTITLED2_BLOQUEPROFUNDO_H
#include "Bloque.h"


/**
 * Bloque Profundo
 * 0 puntos
 * Vida infinita
 */
class BloqueProfundo:public Bloque{
public:
    BloqueProfundo();

    void defineSorpresa() override;
};



#endif //UNTITLED2_BLOQUEPROFUNDO_H
