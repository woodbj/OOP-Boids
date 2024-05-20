#ifndef FLOCK_H
#define FLOCK_H
#include "Boid.h"
#include <SFML/Graphics.hpp>
#include <iostream>

typedef struct {
    int preyCount;
    int predCount;
    int playCount;
}FlockConfig;

class Flock
{
private:
    int _size;
    Boid **_boids;
    sf::RenderWindow *_window;
public:
    Flock(FlockConfig, sf::RenderWindow *);
    ~Flock();
    void update();
    void draw();
};



#endif