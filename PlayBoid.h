#ifndef PLAYBOID_H
#define PLAYBOID_H
#include <SFML/Graphics.hpp>
 #include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
//#include "PredBoid.h"
#include "VMath.h"

using sf::Vector2f;
using sf::Vector2u;

class PlayBoid 
 {
    private:
    int player1;
    sf::CircleShape player;
    sf::RenderWindow *_window;

    public:
    
    // sf::CircleShape get_player();
    sf::CircleShape set_player(sf::CircleShape player);
    PlayBoid();
    void update(sf::CircleShape player,sf::RenderWindow * _window);
    };

#endif