#include <SFML/Graphics.hpp>
#include <vector>

std::vector<sf::Drawable*> objects;

void DrawField(sf::RenderWindow &window){
    sf::RectangleShape line1(sf::Vector2f(300, 3));
    line1.setRotation(90);
    line1.setFillColor(sf::Color::Black);
    line1.setPosition(sf::Vector2f(100,0));

    
    sf::RectangleShape line2(sf::Vector2f(300, 3));
    line2.setRotation(90);
    line2.setFillColor(sf::Color::Black);
    line2.setPosition(sf::Vector2f(200,0));


    sf::RectangleShape line3(sf::Vector2f(300, 3));
    line3.setFillColor(sf::Color::Black);
    line3.setPosition(sf::Vector2f(0,100));

    sf::RectangleShape line4(sf::Vector2f(300, 3));
    line4.setFillColor(sf::Color::Black);
    line4.setPosition(sf::Vector2f(0,200));
    

    window.draw(line1);
    window.draw(line2);
    window.draw(line3);
    window.draw(line4);

    objects.push_back(&line1);
    objects.push_back(&line2);
    objects.push_back(&line3);
    objects.push_back(&line4);
}

void DrawCross(sf::RenderWindow &window, sf::Vector2f coord){//coord - center of cell
    sf::RectangleShape line1(sf::Vector2f(113, 3));
    line1.setFillColor(sf::Color::Black);
    line1.setRotation(45);
    line1.setPosition(coord - sf::Vector2f(40,40));

    sf::RectangleShape line2(sf::Vector2f(113,3));
    line2.setFillColor(sf::Color::Black);
    line2.setRotation(-45);
    line2.setPosition(coord + sf::Vector2f(-40, 40));
    window.draw(line1);
    window.draw(line2);
}

void DrawCircle(sf::RenderWindow &window, sf::Vector2f coord){
    float rad = 40;
    sf::CircleShape circle(rad);
    circle.setFillColor(sf::Color::Yellow);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(coord - sf::Vector2f(rad, rad));
    window.draw(circle);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(300, 300), "SFML works!");
    
    bool cross = true;
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    
                }
            }
        }

        window.clear(sf::Color::Yellow);
        DrawField(window);
        DrawCross(window, sf::Vector2f(50,50));
        DrawCircle(window, sf::Vector2f(150,150));
        
        window.display();
    }

    return 0;
}