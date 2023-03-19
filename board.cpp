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

Board::Board()
{
    this->board = new vector<vector<Cell>>();
    this->initialised = false;
    //board = new vector<vector<Cell>>(DEFAULT_BOARD_DIMENSION, vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

Board::~Board()
{
    delete(board);
}

void Board::load(int boardID)
{
    std::vector < std::vector<Cell>> copyBoard;
    if (boardID == 1)
    {
        copyBoard = BOARD_1;                //get board to copy
    }
    else if (boardID == 2)
    {
        copyBoard = BOARD_2;
    }

    int height = copyBoard.size();
    for (int y = 0; y < height; y++)
    {
        int width = copyBoard[y].size();
        for (int x = 0; x < width; x++)
        {
            (*board)[y][x] = copyBoard [y][x];
        }
    }
}

bool Board::placePlayer(Position position)
{
    return false; // feel free to revise this line, depending on your implementation.
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED;
}

bool Board::isInitialised()
{
    return this->initialised;
}

void Board::printBoard(Player* player)
{
    //PrinBoard but with the player in mind
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


