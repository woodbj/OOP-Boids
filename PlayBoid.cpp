#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window), score(0)
{
    _sprite.setFillColor(sf::Color::Blue);
    c = new Keyboard;
    _maxVel *= 1.2f;
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input

    _vel = c->steer();
    _vel = VMath::resize(_vel, _maxVel);
    // kill any boids within the kill radius (see PredBoid for how this is done)

    Boid *closestPrey = findClosestPrey(boids, count);
    float range = VMath::length(_pos - closestPrey->getPos());
    if (range < _boidSize)
    {
        closestPrey->kill();
        score++;
    }

    margins();
    draw();
}
