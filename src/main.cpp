#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>

std::vector<sf::Drawable*> objects;

void DrawObjects(sf::RenderWindow &window){
    for(auto obj : objects){
        window.draw((*obj));
    }
}

class Circle : public sf::Drawable{
public:
    Circle(float rad, sf::Color color, sf::Color bg, float thickness, sf::Vector2f coord){
        circle = sf::CircleShape(rad);
        circle.setFillColor(bg);
        circle.setOutlineThickness(thickness);
        circle.setOutlineColor(color);
        circle.setPosition(coord - sf::Vector2f(rad, rad));
    }
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(circle);
    }
    sf::CircleShape circle;
};

class Line : public sf::Drawable{
public:
    Line(float length, float thickness, float rotation, sf::Vector2f coord, sf::Color color){
        line = sf::RectangleShape(sf::Vector2f(length, thickness));
        line.setRotation(rotation);
        line.setFillColor(color);
        line.setPosition(coord);
    }
    Line(){}
private:

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(line);
    }

    sf::RectangleShape line;
};

class Field : public sf::Drawable{
public:
    Field(){
        line1 = Line(300, 3, 0, sf::Vector2f(0, 100), sf::Color::Black);
        line2 = Line(300, 3, 0, sf::Vector2f(0, 200), sf::Color::Black);
        line3 = Line(300, 3, 90, sf::Vector2f(100, 0), sf::Color::Black);
        line4 = Line(300, 3, 90, sf::Vector2f(200, 0), sf::Color::Black);
    }
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

class Cross : public sf::Drawable{
public:
    Cross(sf::Vector2f coord, sf::Color color, float thickness, float diagonal){
        line1 = Line(diagonal, thickness, 45, coord - sf::Vector2f(40, 40), color);
        line2 = Line(diagonal, thickness, -45, coord + sf::Vector2f(-40, 40), color);
    }

    Cross() {}
private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states)const{
        target.draw(line1);
        target.draw(line2);
    }
    Line line1, line2;
};

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "krestik0!");

    Field field;
    objects.push_back(&field);

    bool cross_turn = true;
    bool stop = false;

    std::vector<std::vector<CONTENT>> free(3, std::vector<CONTENT>(3, CONTENT::EMPTY));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                window.close();
                
            }
            if (event.type == sf::Event::KeyPressed){
                if(stop && event.key.code == sf::Keyboard::Escape){
                    objects.clear();
                    objects.push_back(&field);
                    stop = false;
                    for(int x = 0; x < 3; x++){
                        for(int y = 0; y < 3; y++){
                            free[x][y] = CONTENT::EMPTY;
                        }
                    }
                    cross_turn = true;
                }
            }
            

            if(event.type == sf::Event::MouseButtonPressed && !stop){
                if(event.mouseButton.button == sf::Mouse::Left){
                    
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    int pos_x = position.x / 100;
                    int pos_y = position.y / 100;

                    if(free[pos_x][pos_y] != CONTENT::EMPTY){
                        continue;
                    }
                    
                    if (cross_turn){
                        objects.push_back(CreateCross(sf::Vector2f(pos_x * 100 + 50, pos_y * 100 + 50), sf::Color::Black, 3, 113));
                        
                    }else{
                        objects.push_back(CreateCircle(40, sf::Color::Black, sf::Color::Yellow, 3, sf::Vector2f(pos_x * 100 + 50, pos_y * 100 + 50)));
                    }
                    
                    free[pos_x][pos_y] = (CONTENT)cross_turn;
                    cross_turn = !cross_turn;
                }
            }
        }

        window.clear(sf::Color::Yellow);
        if(WinCondition(free, CONTENT::CROSS) != NULL){
            stop = true;
            objects.push_back(WinCondition(free, CONTENT::CROSS));
        }
        if(WinCondition(free, CONTENT::CIRCLE) != NULL){
            stop = true;
            objects.push_back(WinCondition(free, CONTENT::CIRCLE));

        }

        DrawObjects(window);
        window.display();
    }

    return 0;
}