#include "snake.h"
#include <iostream>

sf::Vector2i RespaneApple(sf::CircleShape &apple)
{
    int maxX = HEIGHT / BLOCK_SIZE - 2;
    int maxY = WEIGHT / BLOCK_SIZE - 2;

    int new_x = rand() % maxX + 1;
    int new_y = rand() % maxY + 1;

    apple.setPosition(new_x * BLOCK_SIZE, new_y * BLOCK_SIZE);
    return sf::Vector2i(new_x, new_y); // Долго возвращение объекта, но пофиг
}

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WEIGHT), "Snake");
    Snake snk_obj(HEIGHT / (2.0 * BLOCK_SIZE), WEIGHT / (2.0 * BLOCK_SIZE), SNAKE_SPEED, BLOCK_SIZE);
    sf::Event eventloop;
    sf::Clock clock;
    sf::Time time;
    sf::CircleShape Apple;
    Apple.setRadius(BLOCK_SIZE / 2.0);
    Apple.setOrigin(BLOCK_SIZE / 2.0, BLOCK_SIZE / 2.0);
    Apple.setFillColor(sf::Color(255, 0, 0));
    sf::Vector2i win_coords = RespaneApple(Apple);
    float frametime = 1.0 / BLOCK_SIZE;
    while (window.isOpen())
    {
        while (window.pollEvent(eventloop))
        {
            if (eventloop.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && snk_obj.GetDirection() != Direction::Donw)
            {
                snk_obj.SetDirection(Direction::Up);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && snk_obj.GetDirection() != Direction::Left)
            {
                snk_obj.SetDirection(Direction::Right);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && snk_obj.GetDirection() != Direction::Up)
            {
                snk_obj.SetDirection(Direction::Donw);
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && snk_obj.GetDirection() != Direction::Right)
            {
                snk_obj.SetDirection(Direction::Left);
            }
        }
        time += clock.restart();
        if (time.asSeconds() >= frametime)
        {
            snk_obj.move();
            if (snk_obj.TouchApple(win_coords))
            {
                win_coords = RespaneApple(Apple);
                snk_obj.grown_up();
            };
            time -= sf::seconds(frametime);
            snk_obj.CheckBoard();
        }
        window.clear();
        snk_obj.draw(window);
        window.draw(Apple);
        window.display();
    }
}