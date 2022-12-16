#pragma once
#include <SFML/Graphics.hpp>
#include "Line.hpp"

class Field : public sf::Drawable{
public:
    Field();/*{
        line1 = Line(300, 3, 0, sf::Vector2f(0, 100), sf::Color::Black);
        line2 = Line(300, 3, 0, sf::Vector2f(0, 200), sf::Color::Black);
        line3 = Line(300, 3, 90, sf::Vector2f(100, 0), sf::Color::Black);
        line4 = Line(300, 3, 90, sf::Vector2f(200, 0), sf::Color::Black);
    }*/
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(line1);
        target.draw(line2);
        target.draw(line3);
        target.draw(line4);
    }

    Line line1;
    Line line2;
    Line line3;
    Line line4;
};
