#pragma once
#include <SFML/Graphics.hpp>

class Circle : public sf::Drawable{
public:
    Circle(float rad, sf::Color color, sf::Color bg, float thickness, sf::Vector2f coord);/*{
        circle = sf::CircleShape(rad);
        circle.setFillColor(bg);
        circle.setOutlineThickness(thickness);
        circle.setOutlineColor(color);
        circle.setPosition(coord - sf::Vector2f(rad, rad));
    }*/
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(circle);
    }
    sf::CircleShape circle;
};