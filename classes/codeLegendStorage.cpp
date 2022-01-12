//
// Created by cason on 2022-01-11.
//

#include "codeLegendStorage.hpp"

void codeLegendStorage::reuseOldCode(){
	std::string codeName;
	
	std::cout << "Enter the name of the code: ";
	std::cin >> codeName;
	
	std::ifstream legendStorage(cwd + codeName + ".json");
	
	legendStorage >> legendData;
	
	int i = 0;
	for (auto z: legendData["code"].get<std::string>()){
		legend[i] = z;
		++i;
	}
	
	legendStorage.close();
}

void codeLegendStorage::legendDir(){
	int count = 0;
#ifdef _WIN32
	cwd = "";
	for (auto z : std::string(getenv("PATH"))){
		if (count != 3){
			if (z == '\\'){
				++count;
			}
			cwd += z;
		}
	}
	cwd += "Documents/CodeLegends/";
	for (auto z : cwd){
		if (z == '\\'){
			z = '/';
		}
	}
#else
	cwd = "";
	for (auto z : std::string(getenv("PATH"))){
		if (count != 3){
			cwd += z;
			if (z == '/'){
				++count;
			}
		}
	}
	cwd += "Documents/CodeLegends/";
#endif
}

void codeLegendStorage::jsonLegendStorage(){
	storagePath = cwd + legendName + std::string(".json");
	std::fstream jsonFile(storagePath.c_str(), std::fstream::out | std::fstream::trunc);
	
	if (!(jsonFile.is_open())){
		std::cout << "ERROR - File " << legendName << ".json" << " was not created" << std::endl;
	}
	
	legendData["code"] = legend;
	
	jsonFile << std::setw(4) << legendData << std::endl;
	
	jsonFile.close();
}

void codeLegendStorage::storeLegend(){
	char store;
	
	do {
		std::cout << "Would you like to store this code? [y/n]: ";
		std::cin >> store;
	} while (!(store == 'Y' || store == 'y' || store == 'N' || store == 'n'));
	
	std::cout << std::endl;
	
	if (store == 'Y' || store == 'y') {
		std::cout << "Enter a name for this code: "; /// TODO: Later needs to make sure no duplicate names are entered
		std::cin >> legendName;
		std::cout << std::endl;
		
		jsonLegendStorage();
	}
}