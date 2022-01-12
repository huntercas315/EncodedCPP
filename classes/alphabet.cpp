//
// Created by cason on 2022-01-11.
//

#include "alphabet.hpp"

void alphabet::allVariables() {
	for (int i = 0; i <= 25; ++i) {
		randomInator(legend[1][i]);
	}
}

void alphabet::randomInator(char &letter) {
	std::random_device randInat;
	
	unsigned int randLetter;
	
	do {
		randLetter = (randInat() % 26);
	} while (baseAlphabet[randLetter] == '#');
	
	letter = baseAlphabet[randLetter];
	baseAlphabet[randLetter] = '#';
}

void alphabet::encode(const std::string &message, std::string &encodedMessage) {
	for (char i : message) {
		if (isspace(i)) {
			encodedMessage += ' ';
		} else {
			encodedMessage += legend[1][int(i) - 97];
		}
	}
}

void alphabet::decode(std::string encodedMessage, std::string &message) {
	for (int i = 0; i <= encodedMessage.length(); ++i) {
		if (isspace(encodedMessage[i])) {
			message += ' ';
		} else {
			for (int e = 0; e <= 25; ++e) {
				if (encodedMessage[i] == legend[1][e]) {
					message += legend[0][e];
					break;
				}
			}
			
		}
	}
}

void alphabet::inputEncode(std::string &message, std::string &encodedMessage) {
	input(message);
	encode(message, encodedMessage);
	
	std::cout << "\nEncoded message is " << encodedMessage << std::endl;
}

void alphabet::inputDecodeFunc(std::string &decodedMessage) {
	std::string encodedMessage;
	
	input(encodedMessage);
	
	decode(encodedMessage, decodedMessage);
	
	std::cout << "\nDecoded message is " << decodedMessage << std::endl;
}