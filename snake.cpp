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
        new_x = tail->x+1;
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
    switch (head->direction)
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
        std::swap(next_segment->x, last_x);
        std::swap(next_segment->y, last_y);
        next_segment = next_segment->next;
    }
}