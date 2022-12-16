#pragma once
#include <SFML/Graphics.hpp>

class Line : public sf::Drawable{
public:
    Line(float length, float thickness, float rotation, sf::Vector2f coord, sf::Color color);/*{
        line = sf::RectangleShape(sf::Vector2f(length, thickness));
        line.setRotation(rotation);
        line.setFillColor(color);
        line.setPosition(coord);
    }*/
    Line(){}
private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(line);
    }

    sf::RectangleShape line;
};