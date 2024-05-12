#ifndef DRAWHELPER_H
#define DRAWHELPER_H

#include <cmath>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
using sf::Vector2f;
using sf::RenderWindow;
using sf::Color;


class DrawHelper
{
private:
    RenderWindow *_window;
public:
    DrawHelper(RenderWindow* window){_window = window;}
    void drawLine(Vector2f origin, Vector2f vector, Color color, float boidSize);
    void drawVelocity(Vector2f origin, Vector2f vector, Color color, float boidSize);
    void drawCircle(Vector2f origin, float radius, float offset);
    void drawSpot(Vector2f origin, Color color, float radius);
};

#endif