//
// Created by brandon on 8/5/22.
//

#include "Cipher.h"

Cipher::Cipher(int key)
{
    setKey(key);
}

void Cipher::setKey(int key)
{
    std::cout << "setkey " << key << std::endl;
    this->key = key % 26;
}

int Cipher::getKey() {
    return key;
}

std::string Cipher::Encrypt(std::string plainText) {
    std::string cipherText = "";

    //loop over characters in plaintext
    for (int i = 0; i < plainText.size(); ++i)
    {
        char plainChar = tolower(plainText[i]);
        char cipherChar;

        int key = getKey();
        std::cout << "key" << key << std::endl;
        //check if character is a space
        if (plainChar == ' ')
        {
            cipherChar = ' ';
        }
        //check if character is a number
        else if (std::isdigit(plainChar))
        {
            cipherChar = plainChar;
        }
        else
        {
            //get ascii value of char
            int charValue = int(plainChar);
            std::cout <<"before" << charValue << std::endl;
            charValue = charValue + key;
            std::cout << "after" << charValue << std::endl;
            cipherChar = char(charValue);
            //add char to cipherText
            cipherText += cipherChar;
        }
    }

    return cipherText;
}
