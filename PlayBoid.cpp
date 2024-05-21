#include "PlayBoid.h"

PlayBoid::PlayBoid(int id, sf::RenderWindow *window) : PredBoid(id, window) {
    _sprite.setFillColor(sf::Color::Blue);
}

sf::CircleShape PlayBoid::set_player(sf::CircleShape player)
{
    sf::CircleShape _player(100.f);
    _player.setFillColor(sf::Color(255, 0, 0));
    player = _player;
}

void PlayBoid::update(sf::CircleShape player, sf::RenderWindow *_window)
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        player.move(0.f, -0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        player.move(-0.2f, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        player.move(0.f, 0.2f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        player.move(0.2f, 0.f);
    }
}
