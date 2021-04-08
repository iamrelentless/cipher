#include "Caesar.h"

#include <cctype>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <ostream>


void caesar::run_program(){
    int choice {}, shift {};
    std::string message, p1, p2;

    std::cout << "Enter message followed by (1)Encode or (2)Decode, and shift/key value "; 
    std::getline(std::cin, message);
    std::cin >> choice >> shift;
 
    message = remove_space(message); //remove spaces 
    std::cout <<message << std::endl; //print message

    if(choice == 1) {        
        p1 = caesar::encrypt(message, shift);
        p2 = caesar::decrypt(p1, shift);
        std::cout << "Encode: " << p1 << std::endl;
    } else if(choice == 2) {
        p2 = caesar::decrypt(message, shift);
        std::cout  << "Decode: "<< p2 << std::endl;
    }
}

std::string caesar::encrypt(std::string& message, int shift){
    std::string vals{""}; 
    for(auto i = 0; i < message.length(); ++i){
        if(isupper(message[i])){
            vals += char(int(message[i] + shift - 65)%26 + 65);
        } else {
            vals += char(int(message[i] + shift - 97)%26 + 97);
        }
    }
    return vals;
}

std::string caesar::decrypt(std::string& message, int shift){
    shift%=26;
    return caesar::encrypt(message, 26 - shift);
}

std::string caesar::remove_space(std::string& message){
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    return message;
}
