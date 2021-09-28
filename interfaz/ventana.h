//
// Created by deylan on 21/9/21.
//

#ifndef UNTITLED2_VENTANA_H
#define UNTITLED2_VENTANA_H
#include <SFML/Graphics.hpp>
#include "Bloqueg.h"

class ventana {
public:
    float xball = 200;
    float yball = 300;
    float direccionx = .6f;
    float posxBarra = 250;
    float direcciony = .6f;
    Bloqueg filas[6][13];



    void juego();
    void dibujabloques();
    void dibujabloques2();
    bool chocabloque(int xd, int xi, int ya, int yb );

};


#endif //UNTITLED2_VENTANA_H
