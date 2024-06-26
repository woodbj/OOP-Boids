#ifndef BOID_H
#define BOID_H
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include "Boid.h"
#include "VMath.h"
#include "DrawHelper.h"

using sf::Vector2f;
using sf::Vector2u;

typedef enum BoidType
{
    PREY,
    PREDATOR,
    DEAD
} BoidType;

class Boid
{
protected:
    BoidType _bt;
    Vector2f _pos;
    Vector2f _vel;
    Vector2u _windowDimensions;
    sf::CircleShape _sprite;
    sf::RenderWindow *_window;
    DrawHelper *dh;
    int _id;
    float _maxVel = 2;
    float _boidSize = 5;
    float _visualRange = 200.f;
    float _personalSpace = 25;
    // Separation
    float _sr = _personalSpace; // separation range
    float _sf = 0.05f;          // separation factor
    // Alignment
    float _ar = _visualRange; // alignment range
    float _af = 0.02f;        // alignment factor
    // Cohesion
    float _cr = _visualRange; // cohesion range
    float _cf = 0.0001f;      // cohesion factor
    // Flee
    float _pr = _visualRange;
    float _pf = 0.001;

    // Margins
    float _ml = 50; // margin to turn from
    float _mr;
    float _mt;
    float _mb;
    float _tf = 0.2; // turn factor

public:
    // constructor and destructor
    Boid(int, sf::RenderWindow *);
    virtual ~Boid();

    // General functions
    const Vector2f getPos() { return _pos; }
    const Vector2f getVel() { return _vel; }
    const BoidType getBoidType() { return _bt; }
    const int getId() { return _id; }
    void kill() { _bt = DEAD; }
    void margins();
    void draw();

    // vitual fucntions
    virtual void update(Boid **boids, int count);
};

#endif