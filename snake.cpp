#include "snake.h"
void Snake::grown_up()
{
    int new_x;
    int new_y;

    switch(tail->direction)
    {
        case(Direction::Up):
        new_x = tail->x;
        new_y = tail->y + 1;
        break;
        case(Direction::Donw):
        new_x = tail->x;
        new_y = tail->y - 1;
        break;
        case(Direction::Left):
        new_x = tail->x + 1;
        new_y = tail->y;
        break;
        case(Direction::Right):
        new_x = tail->x - 1;
        new_y = tail->y;
        break;
    }

    SnakeSegment* new_segment = new SnakeSegment(new_x, new_y);
    tail->next = new_segment;
    tail = new_segment;
}


void Snake::move()
{
    int last_x = head->x;
    int last_y = head->y;
    Direction last_dir = head->direction;
    switch (last_dir)
    {
    case (Direction::Up):
    --head->y;     
    break;
    case (Direction::Donw):
    ++head->y;
    break;
    case (Direction::Left):
    --head->x;
    break;
    case (Direction::Right):
    ++head->x;
    break;
    }
    SnakeSegment* next_segment = head->next;
    while (next_segment)
    {
        std::swap(next_segment->direction, last_dir);   
        std::swap(next_segment->x, last_x);
        std::swap(next_segment->y, last_y);
        next_segment = next_segment->next;
    }
}
void Snake::destroy()
{
    SnakeSegment* iterator = head;
    SnakeSegment* next_segment;
    while (iterator)
    {
        next_segment = iterator->next;
        delete iterator;
        iterator = next_segment;
    }
}
void Snake::restart(int new_x, int new_y)
{
    destroy();
    head = new SnakeSegment(new_x, new_y);
    tail = head;
}


void Snake::draw(sf::RenderWindow& window)
{
    Body.setSize(sf::Vector2f(my_size - 1, my_size - 1));
    Body.setFillColor(sf::Color(255, 0, 0));
    Body.setOrigin(Body.getSize().x / 2.0, Body.getSize().y / 2.0);
    Body.setPosition(head->x * my_size, head->y * my_size);
    window.draw(Body);
    SnakeSegment* neak_etc = head->next;
    Body.setFillColor(sf::Color(0, 255, 0));
    while (neak_etc)
    {
        Body.setPosition(neak_etc->x * my_size, neak_etc->y * my_size);
        window.draw(Body);
        neak_etc = neak_etc->next;
    }
}

void Snake::update()
{
    move();
}

void Snake::SetPosition(int new_x, int new_y)
{
    head->x = new_x;
    head->y = new_y;
}

bool Snake::collapsing()
{
    SnakeSegment* neck_ect = head->next;
    int i = 1;
    while(neck_ect)
    {
        if (head->x == neck_ect->x && head->y == neck_ect->y)
        {
            return true;
        }
        neck_ect = neck_ect->next;
    }
    return false;
}

Direction Snake::GetDirection()
{
    SnakeSegment* neak = head->next;

    if (neak)
    {
        if (head->x == neak->x)
        {
            if (head->y > neak->y){return Direction::Donw;}
            if (head->y < neak->y){return Direction::Up;}
        }
        else if (head->y == neak->y)
        {
            if (head->x > neak->x){return Direction::Right;}
            if (head->x < neak->x){return Direction::Left;}
        }
    }
    return Direction::None;
}