#include <iostream>
#include <random>

using namespace std;

class alphabet{
public:
	char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char legend[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	
	void allVariables(){
		for (int i = 0; i <= 25; ++i){
			randomInator(legend[i]);
		}
		
		return;
	}
	
	void randomInator(char& letter){
		random_device randInat;
		
		int randLetter = 0;
		
		do {
			randLetter = (randInat() % 26);
		} while (letters[randLetter] == '#');
		
		letter = letters[randLetter];
		letters[randLetter] = '#';
		
		return;
	}
	
	void encode(string message, string& encodedMessage){
		for (int i = 0; i < message.length(); ++i) {
			if (isspace(message[i])){
				encodedMessage += ' ';
			}
			else {
				encodedMessage += legend[int(message[i]) - 96];
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
				if (encodedMessage[i] == legend[e]){
					message += letters[e];
					break;
				}
			}
			
		}
	}
	return;
}
	
	void input(string& message){
		cout << "Enter a message to be encoded: ";
		cin >> message;
		
		return;
	}
	
	void inputEncode(string& message, string& encodedMessage){
		input(message);
		encode(message, encodedMessage);
		
		cout << "\nEncoded message is "<<encodedMessage<<endl;
	}
	
	void decodeFunc(string encodedMessage, string& decodedMessage){
		decode(encodedMessage, decodedMessage);
		
		cout << "\nDecoded message is "<<decodedMessage<<endl;
	}
	
	void inputDecodeFunc(string& decodedMessage){
		string encodedMessage;
		
		cout << "Enter message to be decoded: ";
		cin >> encodedMessage;
		
		decode(encodedMessage, decodedMessage);
		
		cout << "\nDecoded message is "<<decodedMessage<<endl;
		
		return;
	}
};


int main() {
	alphabet encode;
	string message, encodedMessage, decodedMessage;
	char encodeDecode = 'i';
	encode.allVariables();
	
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

