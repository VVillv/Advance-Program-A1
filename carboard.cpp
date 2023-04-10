#include "game.h"
#include "helper.h"

using std::string;



void loadMenu()             //First thing you see
{
    std::cout << "Welcome to Car Board" << std::endl;
    std::cout << "--------------------" << std::endl;
    std::cout << "1. Play game" << std::endl;
    std::cout << "2. Show student's information" << std::endl;
    std::cout << "3. Quit" << std::endl;
    std::cout << "Please enter your choice: " << std::flush;
}

void showStudentInformation(std::string name, std::string id, std::string email)        // When user presses 2 in main menu
{
    std::cout << " " << std::endl;
    std::cout << "Full Name: " << name << std::endl;
    std::cout << "Student Number: " << id << std::endl;
    std::cout << "Email: " << email << std::endl;
}

int main()
{   //Loop for the main menu
    bool menuLoop = false;                          
    while (menuLoop == false)
    {
        loadMenu();
        std::string choice = Helper::readInput();

            if (choice == "1")              // Game option
            {
                /* std::cout << "choice is 1" <<std::endl; */
                Game game = Game();
                game.start();
            } 
            else if (choice == "2")         // Student detail option
            {
                showStudentInformation("William Truong", "s3946703", "s3945703@student.rmit.edu.au");
                std::cout <<"\n\n";
            }
            else if (choice == "3")         //Quit
            {
                std::cout << "Good bye!\n\n";
                return true;
            }
            else
            {
                std::cout<< "ERROR: Invalid Input" << std::endl;
            }
        }
    return EXIT_SUCCESS;
}

