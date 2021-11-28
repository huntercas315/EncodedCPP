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
		
		uint randLetter;
		
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
#ifdef _WIN32
	return true;
#elifdef __APPLE__
	return false;
#elifdef __LINUX__
	return false;
#else
	return false;
#endif
}

class codeLegendStorage{
public:
	char legend[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	string cwd;
	string legendName;
	json legendData;
	bool weenDOS = osCheck();
	//char slash = (osCheck()) ? '\\' : '/';
	
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
		
		cout << legendData["code"] << endl;
		
		int i = 0;
		for (auto z: legendData["code"].get<string>()){
			legend[i] = z;
			++i;
		}
		
		legendStorage.close();
	}
	
	void legendDir(){
		if (weenDOS) {
			cwd = R"(%userprofile%\Documents\CodeLegends\)";
		}
		else {
			cwd = "~/Documents/CodeLegends/";
		}
	}
	
	void jsonLegendStorage(){
		/// temp
		
		/// temp
		cout << cwd + legendName + ".json" << endl; /// Temp
		ofstream jsonFile(cwd + legendName + ".json");//, ios_base::out);
		
		if (!(jsonFile.is_open())){
			cout << "ERROR - File " << legendName << ".json" << " was not created" << endl;
		}
			
		legendData["code"] = legend;
		
		jsonFile << setw(4) << legendData << endl;
			
		cout << legendData << endl; /// Temp
			
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

