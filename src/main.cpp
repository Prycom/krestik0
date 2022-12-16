#include <SFML/Graphics.hpp>
#include <vector>
#include <algorithm>
#include <iostream>
#include "Utils.hpp"

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