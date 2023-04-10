#include "board.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()          //create empty board
{
    board = new vector<vector<Cell>>(DEFAULT_BOARD_DIMENSION, vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

Board::~Board()
{
    delete(board);
    board = nullptr;
    
}

void Board::load(int boardID)
{
    //replaces empty board with board 1 or 2
    if (boardID == 1) 
    {
        board->assign(BOARD_1.begin(), BOARD_1.end());
        this->initialised = true;
    }
    else if (boardID == 2)                                                           //get board to copy
    {
        board->assign(BOARD_2.begin(), BOARD_2.end());
        this->initialised = true;
    }
    else 
    {
        std::cout << "ERROR: Invalid Input, there are only two boards" << std::endl;
    }
}

bool Board::placePlayer(Position position)
{
    bool validPosition = true;                  //init value for whether the position is valid

    int width = (*board)[0].size();             //width and height of board
    int height = (*board).size();

    if ((position.x >= width) || (position.y >= height))
    {
        validPosition = false;
    }
    else if ((*board)[position.y][position.x] != EMPTY)             // 
    {
        validPosition = false;
    } 
    else if ((position.x < 0) || (position.y < 0))
    {
        validPosition = false;
    }
    else
    {
        (*board)[position.y][position.x] = PLAYER;
    }
    return validPosition;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    PlayerMove result = PLAYER_MOVED;                   //Variable for the ending placement

    int width = (*board)[0].size();
    int height = (*board).size();                       //dimensions of board

    Position nextPosition = player->getNextForwardPosition();

    if ((nextPosition.x < 0) || (nextPosition.y < 0))       //off the board
    {
        result = OUTSIDE_BOUNDS;
    }
    else if ((nextPosition.x >= width) || (nextPosition.y >= height))       //off the board
    {
        result = OUTSIDE_BOUNDS;
    }
    else if ((*board)[nextPosition.y][nextPosition.x] != EMPTY)     // on obstacle
    {
        result = CELL_BLOCKED;
    }
    else
    {
        (*board)[player->position.y][player->position.x] = EMPTY;
        (*board)[nextPosition.y][nextPosition.x] = PLAYER;
        player->updatePosition(nextPosition);
    }

    return result;
}


void Board::display(Player* player)
{
    int width = (*board)[0].size();
    int height = (*board).size();

    std::cout << LINE_OUTPUT << EMPTY_OUTPUT;
    for (int i = 0; i < width; i++)                     //output top of grid
    {
        std::cout << LINE_OUTPUT << i;
    }
    std::cout << LINE_OUTPUT << std::endl;

    for (int y = 0; y < height; y++)
    {
        std::cout << LINE_OUTPUT << y;
        for (int x = 0; x < width; x++)
        {
            int posValue = (*board)[y][x];          // empty/blocked/player

            if (posValue == EMPTY)
            {
                std::cout << LINE_OUTPUT << EMPTY_OUTPUT ;
            }
            else if (posValue == BLOCKED)
            {                                                   //convert that to string
                std::cout << LINE_OUTPUT << BLOCKED_OUTPUT;
            }
            else if (posValue == PLAYER)
            {
                std::cout << LINE_OUTPUT;
                player->displayDirection();
            }
        }
        std::cout << LINE_OUTPUT << std::endl;
    }
    std::cout << std::endl;
}

