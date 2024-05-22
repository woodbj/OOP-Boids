#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window), score(0){
    _sprite.setFillColor(sf::Color::Blue);
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input
    // kill any boids within the kill radius (see PredBoid for how this is done)
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        _sprite.move(0.f,-0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        _sprite.move(0.f,0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _sprite.move(0.2f,0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _sprite.move(-0.2f,0.f);
    }
    
    Boid *closestPrey = findClosestPrey(boids, count);
    float range = VMath::length(_pos - closestPrey->getPos());
        if (range < _boidSize){
            closestPrey -> kill();
            score++;
    margins();
    draw();
}
}
