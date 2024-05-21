#ifndef PLAYBOID_H
#define PLAYBOID_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Boid.h"
#include "PredBoid.h"
#include "VMath.h"

using sf::Vector2f;
using sf::Vector2u;

class PlayBoid : public PredBoid
{
private:
    int player1;
    sf::CircleShape player;
    sf::RenderWindow *_window;

public:
    // sf::CircleShape get_player();
    sf::CircleShape set_player(sf::CircleShape player);
    PlayBoid(int id, sf::RenderWindow *window);
    void update(sf::CircleShape player, sf::RenderWindow *_window);
};

#endif