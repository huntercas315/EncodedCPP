#include <iostream>
#include <stdio.h>
#include <vector>
#include <random>

using namespace std;

class alphabet{
public:
	char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';
	char g = 'g';
	char h = 'h';
	char i = 'i';
	char j = 'j';
	char k = 'k';
	char l = 'l';
	char m = 'm';
	char n = 'n';
	char o = 'o';
	char p = 'p';
	char q = 'q';
	char r = 'r';
	char s = 's';
	char t = 't';
	char u = 'u';
	char v = 'v';
	char w = 'w';
	char x = 'x';
	char y = 'y';
	char z = 'z';
	
	void allVariables(){
		randomInator(a);
		randomInator(b);
		randomInator(c);
		randomInator(d);
		randomInator(e);
		randomInator(f);
		randomInator(g);
		randomInator(h);
		randomInator(i);
		randomInator(j);
		randomInator(k);
		randomInator(l);
		randomInator(m);
		randomInator(n);
		randomInator(o);
		randomInator(p);
		randomInator(q);
		randomInator(r);
		randomInator(s);
		randomInator(t);
		randomInator(u);
		randomInator(v);
		randomInator(w);
		randomInator(x);
		randomInator(y);
		randomInator(z);
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
		for (int ie = 0; ie <= message.length(); ++ie) {
			if (message[ie] == 'a') {
				encodedMessage += a;
			} else if (message[ie] == 'b') {
				encodedMessage += b;
			} else if (message[ie] == 'c') {
				encodedMessage += c;
			} else if (message[ie] == 'd') {
				encodedMessage += d;
			} else if (message[ie] == 'e') {
				encodedMessage += e;
			} else if (message[ie] == 'f') {
				encodedMessage += f;
			} else if (message[ie] == 'g') {
				encodedMessage += g;
			} else if (message[ie] == 'h') {
				encodedMessage += h;
			} else if (message[ie] == 'i') {
				encodedMessage += i;
			} else if (message[ie] == 'j') {
				encodedMessage += j;
			} else if (message[ie] == 'k') {
				encodedMessage += k;
			} else if (message[ie] == 'l') {
				encodedMessage += l;
			} else if (message[ie] == 'm') {
				encodedMessage += m;
			} else if (message[ie] == 'n') {
				encodedMessage += n;
			} else if (message[ie] == 'o') {
				encodedMessage += o;
			} else if (message[ie] == 'p') {
				encodedMessage += p;
			} else if (message[ie] == 'q') {
				encodedMessage += q;
			} else if (message[ie] == 'r') {
				encodedMessage += r;
			} else if (message[ie] == 's') {
				encodedMessage += s;
			} else if (message[ie] == 't') {
				encodedMessage += t;
			} else if (message[ie] == 'u') {
				encodedMessage += u;
			} else if (message[ie] == 'v') {
				encodedMessage += v;
			} else if (message[ie] == 'w') {
				encodedMessage += w;
			} else if (message[ie] == 'x') {
				encodedMessage += x;
			} else if (message[ie] == 'y') {
				encodedMessage += y;
			} else if (message[ie] == 'z') {
				encodedMessage += z;
			}
		}
		return;
	}
	
void decode(string encodedMessage, string& message){
	for (int ie = 0; ie <= encodedMessage.length(); ++ie) {
		if (encodedMessage[ie] == 'a') {
			message += a;
		}
		else if (encodedMessage[ie] == b) {
			message += 'b';
		}
		else if (encodedMessage[ie] == c) {
			message += 'c';
		}
		else if (encodedMessage[ie] == d) {
			message += 'd';
		}
		else if (encodedMessage[ie] == e) {
			message += 'e';
		}
		else if (encodedMessage[ie] == f) {
			message += 'f';
		}
		else if (encodedMessage[ie] == g) {
			message += 'g';
		}
		else if (encodedMessage[ie] == h) {
			message += 'h';
		}
		else if (encodedMessage[ie] == i) {
			message += 'i';
		}
		else if (encodedMessage[ie] == j) {
			message += 'j';
		}
		else if (encodedMessage[ie] == k) {
			message += 'k';
		}
		else if (encodedMessage[ie] == l) {
			message += 'l';
		}
		else if (encodedMessage[ie] == m) {
			message += 'm';
		}
		else if (encodedMessage[ie] == n) {
			message += 'n';
		}
		else if (encodedMessage[ie] == o) {
			message += 'o';
		}
		else if (encodedMessage[ie] == p) {
			message += 'p';
		}
		else if (encodedMessage[ie] == q) {
			message += 'q';
		}
		else if (encodedMessage[ie] == r) {
			message += 'r';
		}
		else if (encodedMessage[ie] == s) {
			message += 's';
		}
		else if (encodedMessage[ie] == t) {
			message += 't';
		}
		else if (encodedMessage[ie] == u) {
			message += 'u';
		}
		else if (encodedMessage[ie] == v) {
			message += 'v';
		}
		else if (encodedMessage[ie] == w) {
			message += 'w';
		}
		else if (encodedMessage[ie] == x) {
			message += 'x';
		}
		else if (encodedMessage[ie] == y) {
			message += 'y';
		}
		else if (encodedMessage[ie] == z) {
			message += 'z';
		}
		
		
	}
	return;
}
	
	void input(string& message){
		cout << "Enter a message to be encoded: ";
		cin >> message;
		
		return;
	}
};

int main() {
	alphabet basic, encode;
	string message, encodedMessage, decodedMessage;
	
	encode.allVariables();
	
	encode.input(message);
	encode.encode(message, encodedMessage);
	
	cout << "\nEncoded message is "<<encodedMessage<<endl;
	
	encode.decode(encodedMessage, decodedMessage);
	
	cout << "\nDecoded message is "<<decodedMessage<<endl;
	
	return 0;
}

