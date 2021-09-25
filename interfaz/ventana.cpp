//
// Created by deylan on 21/9/21.
//

#include "ventana.h"
#include "Bloqueg.h"
#include "Bloqueg.cpp"
#include <SFML/Graphics.hpp>
#include <iostream>
bool dibujar = true;
bool dibujar2 =false;

sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
void ventana::juego() {

    sf::CircleShape shape(7.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape barra(sf::Vector2f(100.f,20.f));


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                posxBarra += 4.f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                posxBarra -= 4.f;

        }

        window.clear();

        yball += direcciony;
        xball += direccionx;
        if (xball > 486.f)
            direccionx = -.6f;
        if (0.f > xball)
            direccionx = .6f;
        if (yball+14 > 450 && xball > posxBarra && posxBarra+100 > xball)
            direcciony = -.6f;
        if (0 >yball )
            direcciony += .6f;
        //efecto de colision con bloques
        //if (chocabloque(38,0,125,125+20)  )
           // filas[0][0].setcoords(0,0);





        if (dibujar){
            dibujabloques();

            dibujar = false;
            dibujar2 = true;
        }
        if (dibujar2){
            dibujabloques2();

        }

        shape.setPosition(xball,yball);
        barra.setPosition(posxBarra,450);
        window.draw(shape);
        window.draw(barra);

        window.display();
    }

}

void ventana::dibujabloques() {
    float x = 0;
    float y = 150;
    for(int i=0;i<6;i++){
        Bloqueg columna[13];

        y -= 25;
        x = 0;
        for(int j=0;j<13;j++){
            sf::RectangleShape bloqueh(sf::Vector2f(38.f,20.f));
            bloqueh.setPosition(x,y);
            bloqueh.setFillColor(sf::Color::Blue);
            Bloqueg bloque;
            bloque.setBloque(bloqueh);
            bloque.setcoords(x,y);



            x += 39;
            window.draw(bloque.getBloque());
            filas[i][j]= bloque;


        }
        std::cout<<filas[0][0].getx()<<"--"<<filas[0][0].gety()<<"--";

    }
    std::cout<<filas[0][0].getx()<<"++&/&"<<filas[0][0].gety()<<"**";
}

bool ventana::chocabloque(int xd, int xi, int ya, int yb ) {
    //xball,xball+14,yball+14,yba+14


    if (xd>xball && xball >xi && yb>yball+7 && yball+7>ya){
        direccionx = direccionx *-1.f;
        return true;

    }
    else
        if (xd>xball+7 && xball+7 >xi && yb>yball && yball>ya)
        {
            direcciony = direcciony *-1.f;
            return true;

        }
        else
            if (xd>xball+7 && xball+7 >xi && yb>yball+14 && yball+14>ya){
                direcciony = direcciony *-1.f;
                return true;


            }
            else
                if (xd>xball+14 && xball+14 >xi && yb>yball+7 && yball+7>ya){
                    direccionx = direccionx *-1.f;
                    return true;

                }
                else
                    return false;


}

void ventana::dibujabloques2() {
       std::cout<<filas[0][0].getx()<<"++"<<filas[0][0].gety()<<"**";
        /*for(int i=0;i<6;i++){
            for(int j=0;j<13;j++){
                sf::RectangleShape bloqueh(sf::Vector2f(38.f,20.f));
                //std::cout<<filas[i][j].getx()<<"++"<<filas[i][j].gety()<<"**";
                bloqueh.setPosition(filas[i][j].getx(),filas[i][j].gety());
                bloqueh.setFillColor(sf::Color::Blue);
                //filas[i][j].setBloque(bloqueh);

                window.draw(bloqueh);
        }
            dibujar2 = false;
    }*/
}

int main()
{
    ventana juego;
    juego.juego();
}