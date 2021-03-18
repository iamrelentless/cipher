#include <iostream>
#include <vector>
#include "Caesar.h"
#include "VigenereCipher.cpp"
#include "VigenereHelper.cpp"
void printVec(std::vector<char>);


int main(int argc, char** argv){
    char userChoice;
    std::cout << "Welcome to cipher text" << endl;
    std::cout << "To try Caesar Cipher. Enter C/c" << endl;
    std::cout << "To try Vigenere Cipher. Enter V/v" << endl;
    std::cin >> userChoice;

    if(userChoice == 'V' || userChoice == 'v'){
        VigenereMenu();
    }
    if(userChoice == 'c' || userChoice == 'C'){
        caesar::run_program();
    }

    return 0;
}

