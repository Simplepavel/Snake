#include "Game.h"


void Game::Go()
{
    wrd_obj.RespawnApple();
    TextBox message;
    message.add("Start game");
    message.update_str();
    while (window.isOpen())
    {
        while (window.pollEvent(eventloop))
        {
            if (eventloop.type == sf::Event::Closed)
            {
                window.close();
            }
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
        time += clock.restart();
        if (time.asSeconds() >= FrameTime)
        {
            snk_obj.move();
            if (snk_obj.collapsing())
            {
                Score = 0;
                snk_obj.restart(WEIGHT / (BLOCK_SIZE * 2), HEIGHT / (BLOCK_SIZE * 2));
                message.clear();
                message.add("Game Over! Score = 0");
                message.update_str();
            }
            if (wrd_obj.TouchApple(snk_obj))
            {
                wrd_obj.RespawnApple();
                snk_obj.grown_up();
                Score += 10;
                message.clear();
                message.add("Score = " + std::to_string(Score));
                message.update_str();
            };
            time -= sf::seconds(FrameTime);
            wrd_obj.CheckBoard(snk_obj);
        }
        window.clear();
        snk_obj.draw(window);
        wrd_obj.draw(window);
        message.draw(window);
        window.display();
    }
}
