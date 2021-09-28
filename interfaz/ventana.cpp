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
        for(int i=0;i<6;i++){
            for(int j=0;j<13;j++){
                if (chocabloque(filas[i][j].getx()+38,
                                filas[i][j].getx(),
                                filas[i][j].gety(),
                                filas[i][j].gety()+20 ) &&
                    filas[i][j].getdestruido()  ){
                    filas[i][j].setcoords(-30,-30);
                    filas[i][j].setdestruido(false);

                }

                }
            }
            /*if (chocabloque(filas[0][0].getx()+38,
                            filas[0][0].getx(),
                            filas[0][0].gety(),
                            filas[0][0].gety()+20 ) &&
                            filas[0][0].getdestruido()  ){
                filas[0][0].setcoords(-30,-30);
                filas[0][0].setdestruido(false);

            }
            if (chocabloque(filas[0][1].getx()+38,
                            filas[0][1].getx(),
                            filas[0][1].gety(),
                            filas[0][1].gety()+20 ) &&
                            filas[0][1].getdestruido() ){
                filas[0][1].setcoords(-30,-30);
                filas[0][1].setdestruido(false);

            }
            if (chocabloque(filas[0][2].getx()+38,
                            filas[0][2].getx(),
                            filas[0][2].gety(),
                            filas[0][2].gety()+20 ) &&
                            filas[0][2].getdestruido() ){
                filas[0][2].setcoords(-30,-30);
                filas[0][2].setdestruido(false);}
            if (chocabloque(filas[0][3].getx()+38,
                            filas[0][3].getx(),
                            filas[0][3].gety(),
                            filas[0][3].gety()+20 ) &&
                            filas[0][3].getdestruido() ){
                filas[0][3].setcoords(-30,-30);
                filas[0][3].setdestruido(false);}
            if (chocabloque(filas[0][4].getx()+38,
                            filas[0][4].getx(),
                            filas[0][4].gety(),
                            filas[0][4].gety()+20 ) &&
                filas[0][3].getdestruido() ){
                filas[0][3].setcoords(-30,-30);
                filas[0][3].setdestruido(false);}
            if (chocabloque(filas[0][4].getx()+38,
                            filas[0][4].getx(),
                            filas[0][4].gety(),
                            filas[0][4].gety()+20 ) &&
                filas[0][4].getdestruido() ){
                filas[0][4].setcoords(-30,-30);
                filas[0][4].setdestruido(false);}
            if (chocabloque(filas[0][5].getx()+38,
                            filas[0][5].getx(),
                            filas[0][5].gety(),
                            filas[0][5].gety()+20 ) &&
                filas[0][5].getdestruido() ){
                filas[0][5].setcoords(-30,-30);
                filas[0][5].setdestruido(false);}
            if (chocabloque(filas[0][6].getx()+38,
                            filas[0][6].getx(),
                            filas[0][6].gety(),
                            filas[0][6].gety()+20 ) &&
                filas[0][6].getdestruido() ){
                filas[0][6].setcoords(-30,-30);
                filas[0][6].setdestruido(false);}
            if (chocabloque(filas[0][7].getx()+38,
                            filas[0][7].getx(),
                            filas[0][7].gety(),
                            filas[0][7].gety()+20 ) &&
                filas[0][7].getdestruido() ){
                filas[0][7].setcoords(-30,-30);
                filas[0][7].setdestruido(false);}
            if (chocabloque(filas[0][8].getx()+38,
                            filas[0][8].getx(),
                            filas[0][8].gety(),
                            filas[0][8].gety()+20 ) &&
                filas[0][8].getdestruido() ){
                filas[0][8].setcoords(-30,-30);
                filas[0][8].setdestruido(false);}
            if (chocabloque(filas[0][9].getx()+38,
                            filas[0][9].getx(),
                            filas[0][9].gety(),
                            filas[0][9].gety()+20 ) &&
                filas[0][9].getdestruido() ){
                filas[0][9].setcoords(-30,-30);
                filas[0][9].setdestruido(false);}
            if (chocabloque(filas[0][10].getx()+38,
                            filas[0][10].getx(),
                            filas[0][10].gety(),
                            filas[0][10].gety()+20 ) &&
                filas[0][10].getdestruido() ){
                filas[0][10].setcoords(-30,-30);
                filas[0][10].setdestruido(false);}
            if (chocabloque(filas[0][11].getx()+38,
                            filas[0][11].getx(),
                            filas[0][11].gety(),
                            filas[0][11].gety()+20 ) &&
                filas[0][11].getdestruido() ){
                filas[0][11].setcoords(-30,-30);
                filas[0][11].setdestruido(false);}
            if (chocabloque(filas[0][12].getx()+38,
                            filas[0][12].getx(),
                            filas[0][12].gety(),
                            filas[0][12].gety()+20 ) &&
                filas[0][12].getdestruido() ){
                filas[0][12].setcoords(-30,-30);
                filas[0][12].setdestruido(false);}*/






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
        //Bloqueg columna[13];

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
            window.display();
            filas[i][j]= bloque;


        }


    }

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

        for(int i=0;i<6;i++){
            for(int j=0;j<13;j++){
                sf::RectangleShape bloqueh(sf::Vector2f(38.f,20.f));
                bloqueh.setPosition(filas[i][j].getx(),filas[i][j].gety());
                bloqueh.setFillColor(sf::Color::Blue);
                filas[i][j].setBloque(bloqueh);

                window.draw(filas[i][j].getBloque());

        }
            //dibujar2 = false;
    }
}

int main()
{
    ventana juego;
    juego.juego();
}