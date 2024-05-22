#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window) {
    _sprite.setFillColor(sf::Color::Blue);
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input
    // kill any boids within the kill radius (see PredBoid for how this is done)
    margins();
    draw();
}
