/*#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
*/
#include "Buttons.h"
#include "Movement.h"
#include <string>
#include <iostream>
#include <list>
#include "Checks.h"


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(704, 704), "Tilemap");
    sf::RenderWindow manual(sf::VideoMode(704, 704), "Manual");
    // define the level with an array of tile indices
    int level[] =
    {
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
        3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
    };

    // create the tilemap from the level definition
    TileMap map;

    int size_x;
    int size_y;
    int coord;
    int x;
    int current_pos=0;
    bool proper_check=false;
    // run the main loop
    while (window.isOpen())
    {
       // handle events
        sf::Event event;
        while (window.pollEvent(event))
        {

            WINDOWINFO wiInfo;
            GetWindowInfo(window.getSystemHandle(), &wiInfo);
   
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {
                    //add start.
                    for (int i = 22; i < 461; i++)
                    {
                        if (level[i] == 0 && (level[i + 22] == 3 && level[i - 22] == 3 && level[i + 1] == 3 && level[i - 1] == 3)) { level[i] = 0; std::cout << "current tab[i] =" << level[i] << std::endl; }

                    }

                    current_pos=check(level);
                    int current_number = 4;
                    std::cout << "Current pos= " << current_pos << std::endl;
                    if(current_pos>0)movement(level, current_pos, window);
                }

                if (event.key.code == sf::Keyboard::S)
                {
                    save(level);
                }

                if (event.key.code == sf::Keyboard::L)
                {
                    load(level);
                }

            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    
                    size_x = (wiInfo.rcClient.right - wiInfo.rcClient.left) / 22;
                    size_y = (wiInfo.rcClient.bottom - wiInfo.rcClient.top) / 22;
                   /* std::cout << "sizex= " << size_x << " size y= " << size_y << std::endl;
                    std::cout << "pos x= " << event.mouseButton.x/size_x << "pos y= " << event.mouseButton.y/size_y << std::endl;*/
                    coord = (event.mouseButton.y / size_y) * 22 + (event.mouseButton.x / size_x);

                    if((coord >= 0 && coord <= 22) || (coord >= 461 && coord <= 483) || (coord %22 )==0 || (coord%22)==21)
                    { level[coord] = 0; }
                    else level[coord] = level[coord] + 1;

                    if (level[coord] > 3) { level[coord] = 0; }
                    
                }

                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    
                    
                }
            }
        }
        if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 22, 22))
            return -1;
        // draw the map
        window.clear();
       
        window.draw(map);
        window.display();

        manual.display();
        
    }

    return 1;
}