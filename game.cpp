#include "game.h"

Game::Game()
{
    board = new Board();
    player = new Player();           //when press 1
    
}

Game::~Game()
{
    delete board;
    delete player;
}



void Game::start()
{
    printGameCommands();
    loadBoard();

}

bool Game::loadBoard()
{
    bool commandLoop = false;
    /* if (state == LOAD) */
    while(commandLoop == false)
    {
        std::string input = Helper::readInput();
        std::cout << input <<std::endl;
        std::vector<std::string> tokens;
        Helper::splitString(input, tokens, " ");
        if (tokens[0] == "load")
        {
            board = new Board();
            /* std::vector<std::string> tokens;
            Helper::splitString(input, tokens, " "); */
            this->board->load(std::stoi(tokens[1]));
            this->board->display(player);
        } 
        else if (tokens[0] == "init" && this->board->isInitialised())
        {
            std::vector<std::string> initTokens;

            Helper::splitString(tokens[1], initTokens, ",");

            int x = std::stoi(initTokens[0]);
            int y = std::stoi(initTokens[1]);

            initialPosition = Position(x,y);

            std::string direction = initTokens[2];
            if (direction == "north") 
            {
                initialDirection = NORTH;
            }
            else if (direction == "south") 
            {
                initialDirection = SOUTH;
            }
            else if (direction == "east") 
            {
                initialDirection = EAST;
            }
            else if (direction == "west") 
            {
                initialDirection = WEST;
            }
            this->state = GAME;
        }
        else if (tokens[0] == "quit")
        {
            return true;
        }
        else 
        {
            std::cout << "ERROR: Invalid Input" << std::endl;
        }
    }
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    player = new Player();
    player->initialisePlayer(&initialPosition, initialDirection);
    return true; // feel free to revise this line.
}

void Game::play()
{
    if (state == GAME)
    {
        std::string input = Helper::readInput();        //update player and other game logic;
    }
    else if (state == END)
    {
        std::cout << "Wait, how did u get here?" << std::endl;
    }
}


void Game::printGameCommands() {
    std::cout  << " " << std::endl;
    std::cout  << "You can use the following commands to play the game:" << std::endl;
    std::cout  << "load <g>" << std::endl;
    std::cout  << "     g: number of the game board to load" << std::endl;
    std::cout  << "init <x>, <y>, <direction>" << std::endl;
    std::cout  << "     x: horizontal position of the car on the board (between 0 & 9)" << std::endl;
    std::cout  << "     y: vertical position of the car on the board (between 0 & 9)" << std::endl;
    std::cout  << "     direction: direction of the car's movement (north, east, south, west)" << std::endl;
    std::cout  << "forward (or f)" << std::endl;
    std::cout  << "turn_left (or l)" << std::endl;
    std::cout  << "turn_right (or r)" << std::endl;
    std::cout  << "quit" << std::endl;
}


bool Game::shouldTerminate()
{
    if (state == END)
        return true;
    return false;
}