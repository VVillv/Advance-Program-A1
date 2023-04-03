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
    std::cout << "bootycheeks" <<std::endl;
    std::cout << "Press enter to continue" << std::endl;
    std::cout << " " << std::endl;                              //Gives user instructions to play
    std::string input = Helper::readInput();
    board->display(player);
    std::cout << "bootycheeks" <<std::endl;

    if (loadBoard())
    {
        if (initializePlayer())
        {
            play();
        }
    }
}

bool Game::loadBoard()
{
   bool loaded = false;

    std::string command;
    std::vector<std::string> args;

    while (!(loaded) && !(command==COMMAND_QUIT) && !(std::cin.eof()))
    {
        std::cout << "At this stage of the program, only three commands are acceptable:" << std::endl;
        std::cout << "      • load <g>" << std::endl;
        std::cout << "      • quit" << std::endl;
        std::cout << " " << std::endl;   

        if (Helper::readCommand(command, args))
        {
            if ((command == COMMAND_LOAD) && (args.size() == 1))
            {
                if ((args[0] == "1") || (args[0] == "2"))
                {
                    int boardID = stoi(args[0]);
                    board->load(boardID);
                    board->display(player);
                    loaded = true;
                }
            }
        }

        if (!(loaded) && (command != COMMAND_QUIT) && !(std::cin.eof()))
        {
            Helper::printInvalidInput();
        }
    }
    return loaded;

}

bool Game::initializePlayer()
{
    bool initialized = false;                   // variable when player is initialized
    bool boardLoaded = false;

    std::string command;
    std::vector<std::string> args;

    while (!(initialized) && !(command==COMMAND_QUIT) && !(std::cin.eof()))
    {
        std::cout << "At this stage of the program, only three commands are acceptable:" << std::endl;
        std::cout << "      • load <g>" << std::endl;
        std::cout << "      • init <x>,<y>,<direction>" << std::endl;
        std::cout << "      • quit" << std::endl;
        std::cout << " " << std::endl; 

        boardLoaded = false;

        if (Helper::readCommand(command, args))
        {
            if ((command == COMMAND_LOAD) && (args.size() == 1))
            {
                if ((args[0] == "1") || (args[0] == "2"))
                {
                    int boardID = stoi(args[0]);
                    board->load(boardID);
                    boardLoaded = true;
                }
            }
            if ((command == COMMAND_INIT) && (args.size() == 3))
            {
                if ((Helper::isNumber(args[0])) && (Helper::isNumber(args[1])))
                {
                    int x = std::stoi(args[0]);
                    int y = std::stoi(args[1]);
                    Position pos = Position(x, y);
                    std::string direction = args[2];

                    if ((direction == DIRECTION_NORTH) || (direction == DIRECTION_SOUTH) || (direction == DIRECTION_EAST) || (direction == DIRECTION_WEST))
                    {
                        if (board->placePlayer(pos))
                        {
                            if (direction == DIRECTION_NORTH)
                            {
                                player->initialisePlayer(&pos, NORTH);
                            }
                            else if (direction == DIRECTION_SOUTH)
                            {
                                player->initialisePlayer(&pos, SOUTH);
                            }
                            else if (direction == DIRECTION_EAST)
                            {
                                player->initialisePlayer(&pos, EAST);
                            }
                            else if (direction == DIRECTION_WEST)
                            {
                                player->initialisePlayer(&pos, WEST);
                            }
                            initialized = true;
                        }
                        else
                        {
                            std::cout << "Invalid player placement." << std::endl;
                            std::cout << " " << std::endl; 
                        }
                    }
                }
            } 
        }
        if (!(initialized) && (command != COMMAND_QUIT) && !(boardLoaded) && !(std::cin.eof()))
        {
            Helper::printInvalidInput();
        }
        if (!(std::cin.eof()))
        {
            board->display(player);
        }
    }
    return initialized;
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
/*     std::string command;
    std::vector<std::string> args;
     */
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