#include <SFML/Graphics.hpp>
#include <iostream>
#include "InputHandler.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "warcaby!");
    Initialize();

    while (window.isOpen())
    {

        sf::Event event;

        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            else if (score == 0 && event.type == sf::Event::MouseButtonPressed)
            {
                InputHan(event.mouseButton.x, event.mouseButton.y);
                //score = Update();
                //std::cout << score << std::endl;

            }

        }
        window.clear();

        Draw(window);
        window.display();

    }
    return 0;
}
