#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window), score(0){
    _sprite.setFillColor(sf::Color::Blue);
    c = new Keyboard;
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input
    // kill any boids within the kill radius (see PredBoid for how this is done)
    Boid *closestPrey = findClosestPrey(boids, count);
    float range = VMath::length(_pos - closestPrey->getPos());
        if (range < _boidSize){
            closestPrey -> kill();
            score++;

    std::vector <float> a = c->steer();
    _sprite.move(a[0],a[1]);
    margins();
    draw();
}
}
