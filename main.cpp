#include <iostream>
#include "main.h"
int main() {
    printMenu();
    return 0;
}

void printMenu()
{
    int choice = 0;
    while(choice < 1 || choice >3)
    {
        std::cout << "Please select and option: \n";
        std::cout << "1. Ceasar cipher encrypt\n";
        std::cout << "2. Ceasar cipher decrypt\n";
        std::cout << "3. Ceasar cipher brute force\n";

        std::cin >> choice;
        if (choice == 1)
        {

        }
        else if (choice == 2)
        {

        }
        else if (choice == 3)
        {

        }
        else
        {
            std::cout << "Invalid choice, please try again";
        }
    }

}