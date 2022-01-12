#include <iostream>
#include <string>
#include "headers/json.hpp"
#include "classes/alphabet.hpp"
#include "classes/codeLegendStorage.hpp"

using namespace std;


int main() {
	alphabet encode;
	codeLegendStorage legendStorage;
	legendStorage.legendDir(); /// Sets up Legend Storage Directories
	if (codeLegendStorage::useOldCode()) {
		legendStorage.reuseOldCode();
		for (int i = 0; i <= 26; ++i) {
			encode.legend[1][i] = legendStorage.legend[i];
		}
	} else {
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
		while (encodeDecode != 'e' && encodeDecode != 'd' && encodeDecode != 'x') {
			cout << "\n[e/d] ([x] to exit)\n" << endl;
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

