#include "game.h"

Game::Game()
{
    board = nullptr;
    player = nullptr;           //start of the game
    state = INTRO;
}

Game::~Game()
{
    if (board != nullptr) delete(board);
    if (player != nullptr) delete(player);
}

void Game::loadMenu()
{
    std::cout << "Welcome to Car Board" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "1. Play game" << std::endl;
    std::cout << "2. Show student's information" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "Please enter your choice: " << std::flush;
}

void Game::start()
{
    while (state == INTRO  || state == LOAD)
    {
        if(!this->loadBoard()) return;
    }

    if(!this->initializePlayer()) return;

    while(!this->shouldTerminate())
    {
        this->play();
    }
}

bool Game::loadBoard()
{
    if(this->state == INTRO)
    {
        this -> loadMenu();
        std::string choice = Helper::readInput();

        if (choice == "1")
        {
            printGameCommands();
            this->state = LOAD;
        } 
        else if (choice == "2")
        {
            showStudentInformation("William Truong", "s3946703", "s3945703@student.rmit.edu.au");
            std::cout <<"\n\n";
        }
        else if (choice == "3")
        {
            std::cout << "Good bye!\n\n";
            return false;
        }
        else
        {
            std::cout<< "ERROR: Invalid Input" << std::endl;
        }
    }
    else if (state == LOAD)
    {
        std::string input = Helper::readInput();
        std::vector<std::string> tokens;

        if (tokens[0] == "load")
        {
            board = new Board();
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
            return false;
        }
        else 
        {
            std::cout << "ERROR: Invalid Input" << std::endl;
        }
    }
    return true; // feel free to revise this line, depending on your implementation.
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

void Game::showStudentInformation(std::string name, std::string id, std::string email)
{
    std::cout << " " << std::endl;
    std::cout << "Full Name: " << name << std::endl;
    std::cout << "Student Number: " << id << std::endl;
    std::cout << "Email: " << email << std::endl;
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