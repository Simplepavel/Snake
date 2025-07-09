#include "world.h"

void World::CheckBoard(Snake& snk)
{
    if (snk.get_x() * my_size > weight){snk.SetPosition(0, snk.get_y());}
    if (snk.get_x() < 0){snk.SetPosition(weight / my_size, snk.get_y());}
    if (snk.get_y() * my_size > height){snk.SetPosition(snk.get_x(), 0);}
    if (snk.get_y() < 0){snk.SetPosition(snk.get_x(), height / my_size);}
}

void World::RespawnApple()
{
    int maxX = weight / my_size - 2;
    int maxY = height / my_size - 2;
    int new_x = rand() % (maxX - 8 + 1) + 8;
    int new_y = rand() % (maxY - 6 + 1) + 6;
    apple.setPosition(new_x * my_size, new_y * my_size);
}

bool World::TouchApple(Snake& snk)
{
    return apple.getPosition().x == snk.get_x() * my_size && apple.getPosition().y == snk.get_y() * my_size; 
}


void World::draw(sf::RenderWindow& window)
{
    window.draw(apple);
}