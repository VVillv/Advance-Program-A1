#include "game.h"
#include "helper.h"

using std::string;

void showStudentInformation(std::string name, std::string id, std::string email)
{
    std::cout << " " << std::endl;
    std::cout << "Full Name: " << name << std::endl;
    std::cout << "Student Number: " << id << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void Game::printGameCommands()
{
    std::cout << " " << std::endl;
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

int main()
{   
    Game game = Game();
    do
    {
        std::cout << "Welcome to Car Board" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Play game" << std::endl;
        std::cout << "2. Show student's information" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Please enter your choice: " << std::flush;
        std::string choice = Helper::readInput();

        if (choice == "1")
        {
            game.start();
        }
        else if (choice == "2")
        {
            showStudentInformation("William Truong", "s3946703", "s3945703@student.rmit.edu.au");  
            std::cout << "\n\n";        
        }
        else if (choice == "3")
        {
            std::cout << "Good bye!\n\n";
            exit(0);
        }
    } while (true);

    return EXIT_SUCCESS;
}

/*     if(this->state == INTRO)
    {
        std::cout << "Welcome to Car Board" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Play game" << std::endl;
        std::cout << "2. Show student's information" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Please enter your choice: " << std::flush;
        std::string choice = Helper::readInput();

        if (choice == "1")
        {
            printGameCommands();
            this->state = LOAD;
        } 
        else if (choice == "2")
        {
            showStudentInformation("William Truong", "s3946703", "s3945703@student.rmit.edu.au");
            loadMenu();
        }
        else if (choice == "3")
        {
            std::cout << "Good bye!\n\n";
            this->state = END;
        }
    }
    else if (state == LOAD)
    {
        //board loads up
    }
    else if (state == GAME)
    {
        std::string input = Helper::readInput(); //update player and other game logic or something
    }
    else if (state == END)
    {
        std::cout << "You shouldn't be here" << std::endl;
    } */