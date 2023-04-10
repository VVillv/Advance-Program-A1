#include "player.h"

Position::Position()
{
    x = -1;
    y = -1;
}


Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

Player::Player()
{
    this->position = Position();
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    this->position.x = (*position).x;
    this->position.y = (*position).y;
    this->direction = direction;
    this->moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    if (turnDirection == TURN_RIGHT)
    {
        if (this->direction == NORTH) 
        {
            this->direction = EAST;
        }
        else if (this->direction == SOUTH)          // Turning right
        {
            this->direction = WEST;
        }
        else if (this->direction == EAST)
        {
            this->direction = SOUTH;
        }
        else if (this->direction == WEST)
        {
            this->direction = NORTH;
        }
    }
    else 
    {
        if (this->direction == NORTH)
        {
            this->direction = WEST;
        }
        else if (this->direction == SOUTH)
        {
            this->direction = EAST;
        }                                               // Turning left
        else if (this->direction == EAST)
        {
            this->direction = NORTH;
        }
        else if (this->direction == WEST)
        {
            this->direction = SOUTH;
        }   
    }
}

Position Player::getNextForwardPosition()
{
    Position nextPosition = Position(this->position.x, this->position.y); //Create new position

    if (this->direction == NORTH)
    {
        nextPosition.y -= 1;
    }
    else if (this->direction == SOUTH)
    {
        nextPosition.y += 1;                    //get next position
    }
    else if (this->direction == EAST)
    {
        nextPosition.x += 1;
    }
    else if (this->direction == WEST)
    {
        nextPosition.x -= 1;
    }
    return nextPosition;
    
}

void Player::updatePosition(Position position)
{
    this->position.x = position.x;
    this->position.y = position.y;              // updates positions
    this->moves += 1; 
}

void Player::displayDirection()
{
    if (this->direction == NORTH)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
    }
    else if (this->direction == SOUTH)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;          // displays direction arrow
    }
    else if (this->direction == EAST)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_EAST;
    }
    else if (this->direction == WEST)
    {
        std::cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
        
}
