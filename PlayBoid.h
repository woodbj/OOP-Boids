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
    // add controller
public:
    PlayBoid(int id, sf::RenderWindow *window);
    virtual void update(Boid **boids, int count) override;
};

#endif