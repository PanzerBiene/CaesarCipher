//
// Created by brandon on 8/5/22.
//

#ifndef CEASARCIPHER_CIPHER_H
#define CEASARCIPHER_CIPHER_H
#include <iostream>

class Cipher
{
public:
    Cipher(int key);
    void setKey(int key);
    int getKey();

    std::string Encrypt(std::string plainText);
    std::string Decrypt(std::string cipherText);
private:
    int key = 0;
};


#endif //CEASARCIPHER_CIPHER_H
