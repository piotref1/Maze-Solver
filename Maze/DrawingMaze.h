#include"Buttons.h"

int drawing_during(int level[], sf::RenderWindow& window)
{
    TileMap map;
    if (!map.load("tileset.png", sf::Vector2u(32, 32), level, 22, 22))
        return -1;
    // draw the map
    window.clear();
    window.draw(map);
    window.display();
}