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
        //check if character is a space or if character is a number
        if (plainChar == ' ' || std::isdigit(plainChar))
        {
            cipherText += plainChar;
        }
        else
        {
            //get ascii value of char
            int charValue = int(plainChar);
            charValue = charValue + key;
            cipherChar = char(charValue);
            //add char to cipherText
            cipherText += cipherChar;
        }
    }

    return cipherText;
}

std::string Cipher::Decrypt(std::string cipherText)
{
    std::string plainText = "";

    //loop over characters in plaintext
    for (int i = 0; i < cipherText.size(); ++i)
    {
        char cipherChar = tolower(cipherText[i]);
        char plainChar;

        int key = getKey();
        //check if character is a space or if character is a number
        if (cipherChar == ' ' || std::isdigit(cipherChar))
        {
            plainText += cipherChar;
        }
        else
        {
            //get ascii value of char
            int charValue = int(cipherChar);

            charValue = charValue - key;
            plainChar = char(charValue);
            //add char to cipherText
            plainText += plainChar;
        }
    }

    return plainText;
}
