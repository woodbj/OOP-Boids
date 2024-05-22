#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window) {
    _sprite.setFillColor(sf::Color::Blue);
}

void PlayBoid::update(Boid **boids, int count)
{
    // update _vel direction based on controller input
    
    std::cout << _pos.x << ", " << _pos.y << '\n';
    margins();
    draw();
}
