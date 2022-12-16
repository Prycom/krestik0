#include "Circle.hpp"

Circle::Circle(float rad, sf::Color color, sf::Color bg, float thickness, sf::Vector2f coord){
    circle = sf::CircleShape(rad);
    circle.setFillColor(bg);
    circle.setOutlineThickness(thickness);
    circle.setOutlineColor(color);
    circle.setPosition(coord - sf::Vector2f(rad, rad));
}
