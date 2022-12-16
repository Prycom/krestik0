#include "Line.hpp"

Line::Line(float length, float thickness, float rotation, sf::Vector2f coord, sf::Color color){
    line = sf::RectangleShape(sf::Vector2f(length, thickness));
    line.setRotation(rotation);
    line.setFillColor(color);
    line.setPosition(coord);
}