#include "game.h"

Game::Game()
{
    board = new Board();
    player = new Player();
    state = INTRO;
}

Game::~Game()
{
    delete(board);
    delete(player);
}


void Game::start()
{
    printGameCommands();
    std::cout << std::endl << "Press enter to continue" << std::endl;
    std::cout << std::endl;                                                 //option 1 game menu
    std::cin.get();
    board->display(player);

    if (loadBoard())
    {
        if(initializePlayer())
        {
            play();
        }
    }
}

bool Game::loadBoard()
{
    //TODO
    return false; // feel free to revise this line, depending on your implementation.
}

bool Game::initializePlayer()
{
    //TODO
    return false; // feel free to revise this line.
}

void Game::play()
{

}


bool Game::shouldTerminate()
{
    if (state == END)
        return true;
    return false;
}