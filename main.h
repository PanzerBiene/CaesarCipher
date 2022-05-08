//
// Created by brandon on 8/5/22.
//

#ifndef CEASARCIPHER_MAIN_H
#define CEASARCIPHER_MAIN_H
#include <iostream>
#include <fstream>
#include "Cipher.h"

[[noreturn]] void printMenu();

std::string InputFileName();
void WriteFile(std::string text, std::string fileName);
std::string ReadFile(std::string fileName);

std::string Decrypt(std::string cipherText);
std::string Encrypt(std::string plainText);
std::string BruteForce(std::string cipherText);

#endif //CEASARCIPHER_MAIN_H
