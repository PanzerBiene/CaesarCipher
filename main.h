#ifndef CAESARCIPHER_MAIN_H
#define CAESARCIPHER_MAIN_H
#include <iostream>
#include <fstream>
#include "Cipher.h"

[[noreturn]] void FileCipher();
[[noreturn]] void CommandLineCipher();
void printMenu();

std::string InputFileName();
void WriteFile(std::string text, std::string fileName);
std::string ReadFile(std::string fileName);

std::string Decrypt(std::string cipherText);
std::string Encrypt(std::string plainText);
std::string BruteForce(std::string cipherText);

#endif //CAESARCIPHER_MAIN_H
