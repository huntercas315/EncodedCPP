#include <iostream>
#include <random>
#include <fstream>
#include <unistd.h>

using namespace std;

class alphabet{
public:
	char baseAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char legend[2][26] = {{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'},
						  {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'}};
	
	void allVariables(){
		for (int i = 0; i <= 25; ++i){
			randomInator(legend[1][i]);
		}
		
		return;
	}
	
	void randomInator(char& letter){
		random_device randInat;
		
		int randLetter = 0;
		
		do {
			randLetter = (randInat() % 26);
		} while (baseAlphabet[randLetter] == '#');
		
		letter = baseAlphabet[randLetter];
		baseAlphabet[randLetter] = '#';
		
		return;
	}
	
	void encode(string message, string& encodedMessage){
		for (int i = 0; i < message.length(); ++i) {
			if (isspace(message[i])){
				encodedMessage += ' ';
			}
			else {
				encodedMessage += legend[1][int(message[i]) - 97];
			}
		}
		return;
	}
	
    void decode(string encodedMessage, string& message){
		for (int i = 0; i <= encodedMessage.length(); ++i) {
			if (isspace(encodedMessage[i])){
				message += ' ';
			}
			else {
				for (int e = 0; e <= 25; ++e){
					if (encodedMessage[i] == legend[1][e]){
						message += legend[0][e]; //- 1];
						break;
					}
				}
				
			}
		}
	return;
	}
	
	void input(string& message){
		cout << "Enter a message to be encoded: ";
		cin.ignore();
		getline(cin, message);
		
		return;
	}
	
	void inputEncode(string& message, string& encodedMessage){
		input(message);
		encode(message, encodedMessage);
		
		cout << "\nEncoded message is "<<encodedMessage<<endl;
	}
	
	void inputDecodeFunc(string& decodedMessage){
		string encodedMessage;
		
		cout << "Enter message to be decoded: ";
		cin.ignore();
		getline(cin, encodedMessage);
		
		decode(encodedMessage, decodedMessage);
		
		cout << "\nDecoded message is "<<decodedMessage<<endl;
		
		return;
	}
};

void legendDir(){
	string cwd = get_current_dir_name();
	cwd.erase(36);
	cwd += "/'Code Legends'";
	chdir(cwd.c_str());
	
	
	return;
}


int main() {
	alphabet encode;
	string message, encodedMessage, decodedMessage;
	char encodeDecode = 'i';
	encode.allVariables();
	
	////Temp current working directory finder debug stuff thing thing.
	legendDir();
	
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

