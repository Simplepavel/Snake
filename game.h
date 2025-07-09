#include "world.h"
#include "TextBox.h"

class Game
{
    World wrd_obj;
    Snake snk_obj;
    sf::RenderWindow window;
    sf::Event eventloop;
    sf::Time time;
    sf::Clock clock;
    float FrameTime;
    int Score;

    int WEIGHT;
    int HEIGHT;
    int BLOCK_SIZE;
    int Snake_Speed;

public:
    Game(int width, int height, int block_size, int snake_speed) : 
    WEIGHT(width), HEIGHT(height), BLOCK_SIZE(block_size), Snake_Speed(snake_speed), 
    wrd_obj(width, height, block_size), 
    snk_obj(width / (block_size * 2), height / (block_size * 2), snake_speed, block_size), 
    FrameTime(1.0 / snake_speed), Score(0)
    {
        window.create(sf::VideoMode(WEIGHT, HEIGHT), "Snake");
    }
    void Go();
};
