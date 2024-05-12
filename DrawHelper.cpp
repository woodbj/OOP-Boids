#include "DrawHelper.h"

void DrawHelper::drawLine(Vector2f from, Vector2f to, Color color, float offset)
{
    from.x += offset;
    from.y += offset;

    sf::Vertex line[] = {
        sf::Vertex(from, color),
        sf::Vertex(to, color)};

    _window->draw(line, 2, sf::Lines);
};

void DrawHelper::drawVelocity(Vector2f origin, Vector2f vel, Color color, float offset)
{
    origin.x += offset;
    origin.y += offset;

    sf::Vertex line[] = {
        sf::Vertex(origin, color),
        sf::Vertex(origin + vel, color)};

    _window->draw(line, 2, sf::Lines);
};

void DrawHelper::drawCircle(Vector2f origin, float radius, float offset)
{
    origin.x -= radius - offset;
    origin.y -= radius - offset;
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(origin);
    circle.setFillColor(sf::Color::Transparent);
    circle.setOutlineThickness(2);
    circle.setOutlineColor(sf::Color::White);

    _window->draw(circle);
}

void DrawHelper::drawSpot(Vector2f origin, Color color, float radius)
{
    origin.x -= radius;
    origin.y -= radius;
    sf::CircleShape circle;
    circle.setRadius(radius);
    circle.setPosition(origin);
    circle.setFillColor(color);

    _window->draw(circle);
}