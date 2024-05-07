#ifndef PLAYBOID_H
#define PLAYBOID_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Boid.h"
#include "VMath.h"

using sf::Vector2f;
using sf::Vector2u;

class PlayBoid : public Boid
{
private:
    BoidType _bt = PREDATOR;
    Vector2f _pos;
    Vector2f _dir;
    Vector2u _windowDimensions;
    sf::CircleShape _sprite;
    sf::RenderWindow *_window;
    int _id;
    float _maxVel = 3;
    float _boidSize = 5;

    // Margins
    float _ml = 100; // margin to turn from
    float _mr;
    float _mt;
    float _mb;
    float _tf = 0.2; // turn factor

    void constrainPosition();

public:
    PlayBoid(int, sf::RenderWindow *);

    // virtuals
    Vector2f getPos() { return _pos; }
    Vector2f getVel() { return _dir; }
    BoidType getBoidType() {return _bt;}
    void update(Vector2f *distances, Vector2f *velocities, BoidType *bt,  int count);
    void draw();

    // others
};

#endif