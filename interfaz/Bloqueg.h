//
// Created by deylan on 23/9/21.
//

#ifndef UNTITLED2_BLOQUEG_H
#define UNTITLED2_BLOQUEG_H


#include <SFML/Graphics/RectangleShape.hpp>

class Bloqueg {
public:
    int x =0;
    int y= 0;
    bool destruido = true;
    sf::RectangleShape bloque;

    void setcoords(int x,int y);
    int getx();
    int gety();
    bool getdestruido();
    void setdestruido(bool destru);
    void setBloque(sf::RectangleShape bloque2);
    sf::RectangleShape getBloque();


};


#endif //UNTITLED2_BLOQUEG_H
