#include <iostream>
#include <stdio.h>
#include <string.h>
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
	
	void encode(string message){
		string encodedMessage;
		
		for (int i = 0; i <= message.length(); ++i){
			if (message[i] == 'a'){
			encodedMessage += a;
			}
			else if (message[i] == 'b'){
				encodedMessage += b;
			}
			else if (message[i] == 'c'){
				encodedMessage += c;
			}
			else if (message[i] == 'd'){
				encodedMessage += d;
			}
			else if (message[i] == 'e'){
				encodedMessage += e;
			}
			else if (message[i] == 'f'){
				encodedMessage += f;
			}
			else if (message[i] == 'g'){
				encodedMessage += g;
			}
			else if (message[i] == 'h'){
				encodedMessage += h;
			}
			else if (message[i] == 'i'){
				encodedMessage += i;
			}
			else if (message[i] == 'j'){
				encodedMessage += j;
			}
			else if (message[i] == 'k'){
				encodedMessage += k;
			}
			else if (message[i] == 'l'){
				encodedMessage += l;
			}
			else if (message[i] == 'm'){
				encodedMessage += m;
			}
			else if (message[i] == 'n'){
				encodedMessage += n;
			}
			else if (message[i] == 'o'){
				encodedMessage += o;
			}
			else if (message[i] == 'p'){
				encodedMessage += p;
			}
			else if (message[i] == 'q'){
				encodedMessage += q;
			}
			else if (message[i] == 'r'){
				encodedMessage += r;
			}
			else if (message[i] == 's'){
				encodedMessage += s;
			}
			else if (message[i] == 't'){
				encodedMessage += t;
			}
			else if (message[i] == 'u'){
				encodedMessage += u;
			}
			else if (message[i] == 'v'){
				encodedMessage += v;
			}
			else if (message[i] == 'w'){
				encodedMessage += w;
			}
			else if (message[i] == 'x'){
				encodedMessage += x;
			}
			else if (message[i] == 'y'){
				encodedMessage += y;
			}
			else if (message[i] == 'z'){
				encodedMessage += z;
			}
		}
		
		return;
	}
	
	void input(){
		string message;
		
		cout << "Enter a message to be encoded: ";
		cin >> message;
		
		return;
	}
};

int main() {
	alphabet basic, encode;
	
	encode.allVariables();
	
	
	return 0;
}

