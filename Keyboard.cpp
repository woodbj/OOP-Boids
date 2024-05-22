#include "Keyboard.h"

std::vector <float> Keyboard::steer(){
    std::vector <float> a;   a.resize(0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        a.push_back(0.2f);
        a.push_back(0.f);
        return a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        a.push_back(-0.2f);

        a.push_back(0.f);

        return a;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        a.push_back(0.f);
        a.push_back(-0.2f);

        return a;}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        a.push_back(0.f);
        a.push_back(0.2f);


        return a;
    }
}