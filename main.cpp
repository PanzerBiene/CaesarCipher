#include "main.h"

int main() {
    printMenu();
    return 0;
}
void printMenu()
{
    int choice = 0;
    std::cout << "\t\t Ceasar Cipher \n";
    std::cout << "chose and option: \n1. enter text in command line \n2. enter text through file\n";

    std::cin >> choice;

    if (choice == 1)
    {
        CommandLineCipher();
    }
    else if (choice == 2)
    {
        FileCipher();
    }
    else
    {
        printMenu();
    }
}


[[noreturn]] void CommandLineCipher()
{
    /**
     * CommandLineCipher is used for encrypting/decrypting text inputted through the command line
     */


}

[[noreturn]] void FileCipher()
{
    /**
     * FileCipher is used for encrypting/decrypting files
     */
    int choice = 0;
    while(true)
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
            //get file name
            std::string fileName = InputFileName();
            //read text from file
            std::string cipherText = ReadFile(fileName);

            //decrypt text using ceasar Cipher
            std::string plainText = Decrypt(cipherText);

            std::cout << "Text encrypted enter file to save plain text";

            //get file for text to be saved to
            std::string saveFileName = InputFileName();

            //write data to file
            WriteFile(plainText, saveFileName);
        }
        else if (choice == 3)
        {
            //get file name
            std::string fileName = InputFileName();
            //read text from file
            std::string cipherText = ReadFile(fileName);

            //decrypt text using ceasar Cipher
            std::string plainText = BruteForce(cipherText);

            std::cout << "Text encrypted enter file to save plain text";

            //get file for text to be saved to
            std::string saveFileName = InputFileName();

            //write data to file
            WriteFile(plainText, saveFileName);
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
    file.close();
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
    file.close();
    return text;
}

std::string Decrypt(std::string cipherText)
{
    int key = 0;
    std::cout << "please enter Cipher key: ";
    std::cin >> key;

    //create instance of Cipher
    Cipher cipher(key);

    //decrypt the cipherText
    std::string plainText = cipher.Decrypt(cipherText);
    return plainText;
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
    std::string attempts[26];
    Cipher cipher(0);

    for (int i = 0; i < 26; ++i)
    {
        int key = i;

        cipher.setKey(key);

        std::string attempt = cipher.Decrypt(cipherText);

        std::cout << "Key: " << key << " Text: " << attempt << std::endl;
        attempts[i] = attempt;
    }

    std::cout << "enter the key of the most readable text" << std::endl;

    int chosen;
    std::cin >> chosen;

    return attempts[chosen];

}