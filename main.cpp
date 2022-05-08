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
            std::string fileName = InputFileName();
        }
        else if (choice == 2)
        {
            std::string fileName = InputFileName();
        }
        else if (choice == 3)
        {
            std::string fileName = InputFileName();
        }
        else
        {
            std::cout << "Invalid choice, please try again";
        }
    }

}

std::string InputFileName()
{
    std::string fileName = "";

    std::cout << "Please enter file path: \n";
    std::cin >> fileName;

    return fileName;
}

void WriteFile(std::string text, std::string fileName)
{
    std::ofstream file(fileName, std::ios::app);

    //check if file opens correctly
    if (file.is_open())
    {
        file << text << std::endl;
    }
    else
    {
        std::cout << "Error opening file";
    }
}

std::string ReadFile(std::string fileName)
{
    std::string text;

    std::ifstream file;

    //open file
    file.open(fileName);

    //check if file opens correctly
    if (file.is_open())
    {
        //get each line from the file
        for (std::string line; std::getline(file, line);)
        {
            text.append(line);
        }
    }
    else
    {
        std::cout << "Error opening file";
    }
    return text;
}

std::string Decrypt(std::string cipherText)
{

}

std::string Encrypt(std::string plainText)
{

}

std::string BruteForce(std::string cipherText)
{

}