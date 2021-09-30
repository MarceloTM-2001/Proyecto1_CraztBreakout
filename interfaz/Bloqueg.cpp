//
// Created by deylan on 23/9/21.
//

#include <iostream>
#include "Bloqueg.h"

void Bloqueg::setcoords(int x2, int y2) {

    this->x= x2;
    this->y = y2;



}

int Bloqueg::getx() {
    return this->x;
}
int Bloqueg::gety() {
    return this->y;
}

void Bloqueg::setBloque(sf::RectangleShape bloque2) {
    this->bloque = bloque2;
}

sf::RectangleShape Bloqueg::getBloque() {
    return this->bloque;
}

bool Bloqueg::getdestruido() {
    return destruido;
}

void Bloqueg::setdestruido(bool destru) {
    destruido = destru;

}
