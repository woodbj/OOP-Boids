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

using sf::Vector2f;
using sf::Vector2u;

typedef enum BoidType{
    PREY,
    PREDATOR
} BoidType;

class Boid
{
    BoidType _bt = PREY;
    Vector2f _pos;
    Vector2f _dir;
    Vector2u _windowDimensions;
    sf::CircleShape _sprite;
    sf::RenderWindow *_window;
    int _id;
    float _maxVel = 1;
    float _boidSize = 5;
    float _visualRange = 200.f;
    // Separation
    float _sr = 5;      // separation range
    float _sf = 0.0005f; // separation factor
    // Alignment
    float _ar = _visualRange; // alignment range
    float _af = 0.02f; // alignment factor
    // Cohesion
    float _cr = _visualRange;      // cohesion range
    float _cf = 0.00005f; // cohesion factor
    // Flee
    float _pr = _visualRange;
    float _pf = 1.f;

    // Margins
    float _ml = 100; // margin to turn from
    float _mr;
    float _mt;
    float _mb;
    float _tf = 0.2; // turn factor

public:
    Boid(int, sf::RenderWindow *);

    // General functions
    Vector2f getPos() { return _pos; }
    Vector2f getVel() { return _dir; }
    BoidType getBoidType() {return _bt;}
    int getId() {return _id;}

    // inherited functions
    // virtual void update(Vector2f *distances, Vector2f *velocities, BoidType *bt,  int count);
    virtual void update(Boid** boids,  int count);
    virtual void draw();

    // local functions
    void setDir(Vector2f dir) { _dir = dir; }
    void separation(Vector2f *distances, int count);
    void alignment(Vector2f *dist, Vector2f *vel, int size);
    void cohesion(Vector2f *distances, int count);
    void margins();

    ~Boid();
};


#endif