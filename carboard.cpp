#include "game.h"
#include "helper.h"

using std::string;

void showStudentInformation(string name, string id, string email){
    std::cout << " " << std::endl;
    std::cout << "Full Name: " << name << std::endl;
    std::cout << "Student Number: " << id << std::endl;
    std::cout << "Email: " << email << std::endl;
}

void showGameCommands() {
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
    int choice;
    string name = "William Truong";
    string id = "s3945703";
    string email = "s3945703@student.rmit.edu.au";

    do{
        std::cout << "Welcome to Car Board" << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "1. Play game" << std::endl;
        std::cout << "2. Show student's information" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Please enter your choice: " << std::endl;
        std::cin >> choice;

        if (choice == 1){
            showGameCommands();
        }
        else if (choice == 2){
            showStudentInformation(name, id, email);
            std::cout << "" << std::endl;
        }
        else if (choice == 3){
            std::cout << "Good bye!\n\n";
            exit(0);
        }
    } while (true);
    



    return EXIT_SUCCESS;
}

