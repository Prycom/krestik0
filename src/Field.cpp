#include "Field.hpp"

Field::Field(){
    line1 = Line(300, 3, 0, sf::Vector2f(0, 100), sf::Color::Black);
    line2 = Line(300, 3, 0, sf::Vector2f(0, 200), sf::Color::Black);
    line3 = Line(300, 3, 90, sf::Vector2f(100, 0), sf::Color::Black);
    line4 = Line(300, 3, 90, sf::Vector2f(200, 0), sf::Color::Black);
}