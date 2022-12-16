#pragma once
#include "Field.hpp"
#include "Circle.hpp"
#include "Line.hpp"
#include "Cross.hpp"
#include <SFML/Graphics.hpp>


std::vector<sf::Drawable*> objects;

void DrawObjects(sf::RenderWindow &window){
    for(auto obj : objects){
        window.draw((*obj));
    }
}

Cross* CreateCross(sf::Vector2f coord, sf::Color color, float thickness, float diagonal){
    return new Cross(coord, color, thickness, diagonal);
}

Circle* CreateCircle(float rad, sf::Color color, sf::Color bg, float thickness, sf::Vector2f coord){
    return new Circle(rad, color, bg, thickness, coord);
}

Line* CreateLine(float length, float thickness, float rotation, sf::Vector2f coord, sf::Color color){
    return new Line(length, thickness, rotation, coord, color);
}

enum CONTENT{
    CIRCLE,
    CROSS,
    EMPTY
};

Line* WinCondition(std::vector<std::vector<CONTENT>> &free, CONTENT type){
    for(int x = 0; x < 3; x++){
        if(free[x][0] == type && free[x][1] == type && free[x][2] == type){
            return CreateLine(300, 3, 90, sf::Vector2f(50 + 100 * x, 0), sf::Color::Black);
        }
        if(free[0][x] == type && free[1][x]== type && free[2][x] == type){
            return CreateLine(300, 3, 0, sf::Vector2f(0, 50 + 100 * x), sf::Color::Black);
        }
    }

    if(free[0][0] == type && free[1][1] == type && free[2][2] == type){
        return CreateLine(450, 3, 45, sf::Vector2f(0, 0), sf::Color::Black);
    }

    if(free[0][2] == type && free[1][1] == type && free[2][0] == type){
        return CreateLine(450, 3, -45, sf::Vector2f(0, 300), sf::Color::Black);
    }

    return NULL;

}