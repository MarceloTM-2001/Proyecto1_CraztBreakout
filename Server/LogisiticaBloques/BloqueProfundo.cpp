//
// Created by Lenovo on 20/9/2021.
//

#include "BloqueProfundo.h"

    BloqueProfundo::BloqueProfundo(){
        this->vida=0;
        this->tipo="Profundo";
        this->puntos=0;
        defineSorpresa();
    }
    void BloqueProfundo::defineSorpresa(){
        setSorpresa("N");
    }
