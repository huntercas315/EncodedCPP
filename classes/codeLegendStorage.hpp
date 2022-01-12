//
// Created by cason on 2022-01-11.
//

#ifndef ENCODEDCPP_CODELEGENDSTORAGE_HPP
#define ENCODEDCPP_CODELEGENDSTORAGE_HPP

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "../headers/json.hpp"

using json = nlohmann::json;

class codeLegendStorage{
public:
	char legend[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	std::string cwd;
	std::string legendName;
	std::string storagePath;
	json legendData;
	
	static bool useOldCode(){
		char input;
		
		do {
			std::cout << "Do you have an old code to use? [y/n]: ";
			std::cin >> input;
		} while (!(input == 'Y' || input == 'y' || input == 'N' || input == 'n'));
		
		std::cout << std::endl;
		
		if (input == 'Y' || input == 'y'){
			return true;
		}
		else {
			return false;
		}
	}
	
	void reuseOldCode();
	
	void legendDir();
	
	void jsonLegendStorage();
	
	void storeLegend();
};



#endif //ENCODEDCPP_CODELEGENDSTORAGE_HPP
