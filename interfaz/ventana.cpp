//
// Created by deylan on 21/9/21.
//

#include "ventana.h"
#include <SFML/Graphics.hpp>
#include <iostream>;

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML works!");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Green);
    sf::RectangleShape barra(sf::Vector2f(200.f,40.f));

    float xball = 100;
    float yball = 100;
    float direccionx = .1f;
    float posxBarra = 250;
    float direcciony = .1f;
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
        if (xball > 480.f)
            direccionx = -.1f;
        if (0.f > xball)
            direccionx = .1f;
        if (yball+20 > 450 && xball > posxBarra && posxBarra+200 > xball)
            direcciony = -.1f;
        if (0 >yball )
            direcciony += .1f;


        barra.setPosition(posxBarra,450);
        shape.setPosition(xball,yball);
        window.draw(shape);
        window.draw(barra);

        window.display();
    }

    return 0;
}
