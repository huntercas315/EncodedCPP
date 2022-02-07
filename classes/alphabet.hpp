//
// Created by huntercas315 on 2022-01-11.
//

#ifndef ENCODEDCPP_ALPHABET_HPP
#define ENCODEDCPP_ALPHABET_HPP

#include <iostream>
#include <random>
#include <string>

class alphabet {
public:
	char baseAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
	                         's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char legend[2][26] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
	                      {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}};
	
	void allVariables();
	
	void randomInator(char &letter);
	
	void encode(const std::string &message, std::string &encodedMessage);
	
	void decode(std::string encodedMessage, std::string &message);
	
	static void input(std::string &message) {
		std::cout << "Enter a message: ";
		std::cin.ignore();
		getline(std::cin, message);
	}
	
	void inputEncode(std::string &message, std::string &encodedMessage);
	
	void inputDecodeFunc(std::string &decodedMessage);
};


#endif //ENCODEDCPP_ALPHABET_HPP
