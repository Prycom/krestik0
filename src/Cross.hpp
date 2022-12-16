#pragma once
#include <SFML/Graphics.hpp>
#include "Line.hpp"

class Cross : public sf::Drawable{
public:
    Cross(sf::Vector2f coord, sf::Color color, float thickness, float diagonal);

    Cross() {}
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(line1);
        target.draw(line2);
    }
    Line line1, line2;
    sf::Vector2f coord;
    sf::Color color;
    float thickness;
    float diagonal;
};
