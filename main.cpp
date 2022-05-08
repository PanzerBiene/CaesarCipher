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
        std::cout << "1. Ceasar Cipher encrypt\n";
        std::cout << "2. Ceasar Cipher decrypt\n";
        std::cout << "3. Ceasar Cipher brute force\n";

        std::cin >> choice;
        if (choice == 1)
        {
            //get file name
            std::string fileName = InputFileName();
            //read text from file
            std::string plainText = ReadFile(fileName);

            //encrypt text using ceasar Cipher
            std::string cipherText = Encrypt(plainText);

            std::cout << "Text encrypted enter file to save Cipher text";

            //get file for text to be saved to
            std::string saveFileName = InputFileName();

            //write data to file
            WriteFile(cipherText, saveFileName);
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
        exit(0);
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
        exit(0);
    }
    return text;
}

std::string Decrypt(std::string cipherText)
{

}

std::string Encrypt(std::string plainText)
{
    int key = 0;
    std::cout << "please enter Cipher key: ";
    std::cin >> key;

    //create instance of Cipher
    Cipher cipher(key);

    //encrypt the plaintext
    std::string cipherText = cipher.Encrypt(plainText);
    return cipherText;
}

std::string BruteForce(std::string cipherText)
{

}