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
    board = nullptr;
    player = nullptr;
}



void Game::start()
{
    printGameCommands();
    std::cout << "Press enter to continue" << std::endl;
    std::cout << " " << std::endl;                              //Gives user instructions to play
    std::string input = Helper::readInput();
    board->display(player);


    if (loadBoard())
    {
        if (initializePlayer())             // Main game
        {
            play();
        }
    }
}


bool Game::loadBoard()
{
   bool loaded = false;                //Outline list of commands to user


    std::string command;            // Variable for user input
    std::string args;


    while (!(loaded) && !(command==COMMAND_QUIT) && !(std::cin.eof()))          // Loop until either quit, eof or the board is loaded
    {
        std::cout << "At this stage of the program, only three commands are acceptable:" << std::endl;
        std::cout << "      • load <g>" << std::endl;
        std::cout << "      • quit" << std::endl;
        std::cout << " " << std::endl;  

        

        if (Helper::readCommand(command, args))
        {
            if ((command == COMMAND_LOAD) && (args.size() == 1))
            {
                
                if ((args == "1") || (args == "2"))
                {
                    int boardID = stoi(args);                  // Load and display the board
                    board->load(boardID);
                    board->display(player);
                    loaded = true;
                }
            }
        }


        if (!(loaded) && (command != COMMAND_QUIT) && !(std::cin.eof()))        // Check if hte board was loaded, if not print invalid input
        {
            Helper::printInvalidInput();
        }
    }
    return loaded;


}


bool Game::initializePlayer()
{
    bool initialized = false;                               // variable when player is initialized
    bool boardLoaded = false;

    std::string command;                                    // Variable for user input
    std::string args;

    while (!(initialized) && !(command==COMMAND_QUIT) && !(std::cin.eof()))             //Loop until either quit, eof or player is initialized
    {
        std::cout << "At this stage of the program, only three commands are acceptable:" << std::endl;
        std::cout << "      • load <g>" << std::endl;
        std::cout << "      • init <x>,<y>,<direction>" << std::endl;
        std::cout << "      • quit" << std::endl;
        std::cout << " " << std::endl; 

        boardLoaded = false;                              // Variable to check if the board is loaded in this command

        if (Helper::readCommand(command, args))          // Check user input
        {
            if (command == COMMAND_LOAD)                // Check command is load
            {
                if ((args == "1") || (args == "2"))
                {
                    int boardID = stoi(args);           //Load and display the board
                    board->load(boardID);
                    boardLoaded = true;
                }
            }
            if (command == COMMAND_INIT)                // Check the command is init
            {
                std::vector<std::string> argtokens;
                Helper::splitString(args, argtokens, ",");

                if ((Helper::isNumber(argtokens[0])) && (Helper::isNumber(argtokens[1])))           //Checks 1st and 2nd argtokens are integers
                {
                    int x = std::stoi(argtokens[0]);
                    int y = std::stoi(argtokens[1]);
                    Position pos = Position(x, y);
                    std::string direction = argtokens[2];

                    if ((direction == DIRECTION_NORTH) || (direction == DIRECTION_SOUTH) || (direction == DIRECTION_EAST) || (direction == DIRECTION_WEST))             //Check that the direction is North, South, East, West
                    {
                        if (board->placePlayer(pos))                            //Place the player on the board
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
        if (!(initialized) && (command != COMMAND_QUIT) && !(boardLoaded) && !(std::cin.eof()))         //Check if board was loaded, if not print invalid input
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
    std::string command;            //Variables for user input
    std::string args;

    while (!(command == COMMAND_QUIT))          // Loop until quit or EOF
    {
        std::cout << "At this stage of the program, only four commands area acceptable:" <<std::endl;
        std::cout << "      • forward" << std::endl;
        std::cout << "      • turn_left (or l)" << std::endl;
        std::cout << "      • turn_right (or r)" << std::endl;
        std::cout << "      • quit" << std::endl;

        if (Helper::readCommand(command,args))      //Check input
        {
            if ((command == COMMAND_FORWARD) || (command == COMMAND_FORWARD_SHORTCUT))      // Move Forward
            {
                PlayerMove result = board->movePlayerForward(player);
                if (result == PLAYER_MOVED)
                {
                    std::cout << "Player has moved" << std::endl;
                }
                else if (result == CELL_BLOCKED)
                {
                    std::cout << "Unable to move (CELL IS BLOCKED)" << std::endl;
                }
                else if (result == OUTSIDE_BOUNDS)
                {
                    std::cout << "Unable to move (OUTSIDE OF BOUNDS)." << std::endl;
                }
                std::cout << " " << std::endl; 
            }
            else if ((command == COMMAND_TURN_RIGHT) || (command == COMMAND_TURN_RIGHT_SHORTCUT))       //Turn Right
            {
                player->turnDirection(TURN_RIGHT);
            }
            else if ((command == COMMAND_TURN_LEFT) || (command == COMMAND_TURN_LEFT_SHORTCUT))     //Turn Left
            {
                player->turnDirection(TURN_LEFT);
            }
            else if ((command != COMMAND_QUIT))
            {
                Helper::printInvalidInput();
            }
        } 
        else if (!(std::cin.eof()))
        {
            board->display(player);
        }
        board->display(player);
    }
}



void Game::printGameCommands() {                // Game instructions
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