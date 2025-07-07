class Snake
{
    enum class Direction{None, Up, Donw, Left, Right};
    struct SnakeSegment
    {
        int x = 0;
        int y = 0;
        SnakeSegment* next;
        SnakeSegment(int input_x, int input_y, SnakeSegment* new_elem):x(input_x), y(input_y), next(new_elem){}
        Direction direction = Direction::None;
    };
    SnakeSegment* head;
    SnakeSegment* tail;
    int speed;
    public:
    Snake(int start_x, int start_y):head(new SnakeSegment(start_x, start_y, nullptr)){}

};