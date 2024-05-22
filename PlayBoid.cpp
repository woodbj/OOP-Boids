#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window), score(0){
    _sprite.setFillColor(sf::Color::Blue);
    c = new Keyboard;
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input
    // kill any boids within the kill radius (see PredBoid for how this is done)
        _vel = c->steer();
    Boid *closestPrey = findClosestPrey(boids, count);
    float range = VMath::length(_pos - closestPrey->getPos());
        if (range < _boidSize){
            closestPrey -> kill();
            score++;
    margins();
    draw();
}
}
