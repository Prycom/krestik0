#include "Cross.hpp"

Cross::Cross(sf::Vector2f coord, sf::Color color, float thickness, float diagonal) : coord {coord}, color {color}, thickness{thickness}, diagonal{diagonal} {
    line1 = Line(diagonal, thickness, 45, coord - sf::Vector2f(40, 40), color);
    line2 = Line(diagonal, thickness, -45, coord + sf::Vector2f(-40, 40), color);
}