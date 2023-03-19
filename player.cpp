#include "player.h"

Position::Position()
{
    //TODO
}


Position::Position(int x, int y)
{
    //TODO
}

Player::Player()
{
    //TODO
}

void Player::initialisePlayer(Position* position, Direction direction)
{
    //TODO
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
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
    this->position.y = position.y;
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
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;
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
