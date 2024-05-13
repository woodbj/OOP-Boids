
#ifndef PREDBOID_H
#define PREDBOID_H

#include "Boid.h"
#include "VMath.h"
#include <SFML/Graphics.hpp>
#include <cmath>

class PredBoid : public Boid 
{
private:
    BoidType _bt = PREDATOR;
    sf::Vector2f _pos;
    sf::Vector2f _vel;
    sf::Vector2f _dir;
    sf::Vector2u _windowDimensions;
    sf::CircleShape _sprite;
    sf::RenderWindow* _window;
    int _id;
    float _maxVel = 7;
    float _boidSize = 10;
    float _visualRange = 300.0f;
    private:
    float warningRange = 100.0f; // Warning range to start targeting other boids
    float approachFactor = 0.5f; // Control how aggressively the PredBoid steers towards the target
    float _captureRange = 10.0f;

    // Margins
    float _ml = 100; // margin to turn from
    float _mr;
    float _mt;
    float _mb;
    float _tf = 0.2; // turn factor

    void checkBounds();
    void normalizeVelocity();

public:
    PredBoid(int id, sf::RenderWindow* window);

    virtual void update(Boid** boids, int size) override;
    virtual void draw() override;
};

#endif // PREDBOID_H
