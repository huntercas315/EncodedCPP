#include <iostream>
#include <random>
#include <fstream>
#include <iomanip>
#include <string>
#include "headers/json.hpp"

using namespace std;
using json = nlohmann::json;

class alphabet{
public:
	char baseAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char legend[2][26] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
						  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}};
	
	void allVariables(){
		for (int i = 0; i <= 25; ++i){
			randomInator(legend[1][i]);
		}
	}
	
	void randomInator(char& letter){
		random_device randInat;
		
		unsigned int randLetter;
		
		do {
			randLetter = (randInat() % 26);
		} while (baseAlphabet[randLetter] == '#');
		
		letter = baseAlphabet[randLetter];
		baseAlphabet[randLetter] = '#';
	}
	
	void encode(const string& message, string& encodedMessage){
		for (char i : message) {
			if (isspace(i)){
				encodedMessage += ' ';
			}
			else {
				encodedMessage += legend[1][int(i) - 97];
			}
		}
	}
	
    void decode(string encodedMessage, string& message){
		for (int i = 0; i <= encodedMessage.length(); ++i) {
			if (isspace(encodedMessage[i])){
				message += ' ';
			}
			else {
				for (int e = 0; e <= 25; ++e){
					if (encodedMessage[i] == legend[1][e]){
						message += legend[0][e];
						break;
					}
				}
				
			}
		}
	}
	
	static void input(string& message){
		cout << "Enter a message: ";
		cin.ignore();
		getline(cin, message);
	}
	
	void inputEncode(string& message, string& encodedMessage){
		input(message);
		encode(message, encodedMessage);
		
		cout << "\nEncoded message is "<<encodedMessage<<endl;
	}
	
	void inputDecodeFunc(string& decodedMessage){
		string encodedMessage;
		
		input(encodedMessage);
		
		decode(encodedMessage, decodedMessage);
		
		cout << "\nDecoded message is "<<decodedMessage<<endl;
	}
};

bool osCheck(){
#ifndef _WIN32
	return false;
#else
	return true;
#endif
}

class codeLegendStorage{
public:
	char legend[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	string cwd;
	string legendName;
	string storagePath;
	json legendData;
	bool weenDOS = osCheck();
	
	static bool useOldCode(){
		char input;
		
		do {
			cout << "Do you have an old code to use? [y/n]: ";
			cin >> input;
		} while (!(input == 'Y' || input == 'y' || input == 'N' || input == 'n'));
		
		cout << endl;
		
		if (input == 'Y' || input == 'y'){
			return true;
		}
		else {
			return false;
		}
	}
	
	void reuseOldCode(){
		string codeName;
		
		cout << "Enter the name of the code: ";
		cin >> codeName;
		
		ifstream legendStorage(cwd + codeName + ".json");
		
		legendStorage >> legendData;
		
		int i = 0;
		for (auto z: legendData["code"].get<string>()){
			legend[i] = z;
			++i;
		}
		
		legendStorage.close();
	}
	
	void legendDir(){
		if (weenDOS) {
            cout << "PATH: " << getenv("PATH") << endl;
            int count = 0;
            cwd = "";
            for (auto z : string(getenv("PATH"))){
                if (count != 3){
                    cwd += z;
                    if (z == '\\'){
                        ++count;
                    }
                }
            }
            cwd += "Documents\\CodeLegends\\";
		}
		else {
			int count = 0;
			cwd = "";
			for (auto z : string(getenv("PATH"))){
				if (count != 3){
					cwd += z;
					if (z == '/'){
						++count;
					}
				}
			}
			cwd += "Documents/CodeLegends/";
		}
	}
	
	void jsonLegendStorage(){
		storagePath = cwd + legendName + string(".json");
		fstream jsonFile(storagePath.c_str(), fstream::out | fstream::trunc);
		
		if (!(jsonFile.is_open())){
			cout << "ERROR - File " << legendName << ".json" << " was not created" << endl;
		}
		
		legendData["code"] = legend;
		
		jsonFile << setw(4) << legendData << endl;
			
		jsonFile.close();
	}
	
	void storeLegend(){
		char store;
		
		do {
			cout << "Would you like to store this code? [y/n]: ";
			cin >> store;
		} while (!(store == 'Y' || store == 'y' || store == 'N' || store == 'n'));
		
		cout <<endl;
		
		if (store == 'Y' || store == 'y') {
			cout << "Enter a name for this code: "; /// TODO: Later needs to make sure no duplicate names are entered
			cin >> legendName;
			cout << endl;
			
			jsonLegendStorage();
		}
	}
};

int main() {
	alphabet encode;
	codeLegendStorage legendStorage;
	legendStorage.legendDir(); /// Sets up Legend Storage Directories
	if (codeLegendStorage::useOldCode()){
		legendStorage.reuseOldCode();
		for (int i = 0; i <= 26; ++i) {
			encode.legend[1][i] = legendStorage.legend[i];
		}
	}
	else {
		encode.allVariables();
		
		/// Moves a copy of the legend into the legendStorage class to turn into JSON data
		for (int i = 0; i <= 26; ++i) {
			legendStorage.legend[i] = encode.legend[1][i];
		}
		
		legendStorage.storeLegend();
	}
	string message, encodedMessage, decodedMessage;
	char encodeDecode = 'i';
	
	do {
		message = "";
		encodedMessage = "";
		decodedMessage = "";
		cout << "Would you like to decode or encode? [e/d] ([x] to exit): ";
		cin >> encodeDecode;
		while (encodeDecode != 'e' && encodeDecode != 'd' && encodeDecode != 'x'){
			cout << "\n[e/d] ([x] to exit)\n"<<endl;
			cout << "Would you like to decode or encode?: ";
			cin >> encodeDecode;
		}
		
		if (encodeDecode == 'e') {
			cout << endl;
			encode.inputEncode(message, encodedMessage);
			cout << endl;
		} else if (encodeDecode == 'd') {
			cout << endl;
			encode.inputDecodeFunc(decodedMessage);
			cout << endl;
		}
	} while (encodeDecode != 'x');
	
	return 0;
}

