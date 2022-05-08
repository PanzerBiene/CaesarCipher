#ifndef CAESARCIPHER_CIPHER_H
#define CAESARCIPHER_CIPHER_H
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


#endif //CAESARCIPHER_CIPHER_H
