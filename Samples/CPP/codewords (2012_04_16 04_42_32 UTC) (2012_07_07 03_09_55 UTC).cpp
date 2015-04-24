/*	Cory Cook
		This program takes a string as input and outputs an equivalent
		encoded or decoded message.
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Code
{
public:
  Code();  // Default constructor - loads morse code
  Code(vector<string> codewords);  // constructor loading customized code
  
  string encode(string message);  // encodes a message consisting of A-Z
  string decode(string message);  // decodes a message

private:
  vector<string> codewords; // this is a codeword vector parallel to A-Z
  vector<char> alpha; // this is the vector A-Z
  vector<char>  alphacode(); // function returns vector - A B C etc.
  vector<string>  morsecode(); // function returns vector containing morse code
  string getnextcodeword(string message, int p); //returns the next codeword in message beginning at position p
  string convertencode(char message);
  char convertdecode(string message);
};

Code::Code() {
this->codewords = morsecode();
this->alpha = alphacode();
}

Code::Code(vector<string> codewords) {
this->codewords = codewords;
this->alpha = alphacode();
}

string Code::encode(string message) {
	int p = 0;
	string decmsg, encmsg;
	while (p <= message.length()) {
		decmsg = this->getnextcodeword(message, p);
		for (int i = 0; i <= decmsg.length(); i++)
			encmsg += this->convertencode(decmsg[i]);
		p += decmsg.length();
	}
	return encmsg;
}

string Code::decode(string message) {
	int p = 0;
	string encmsg, decmsg;
	while (p <= message.length()) {
		encmsg = this->getnextcodeword(message, p);
		//cout << encmsg << endl;
		decmsg += this->convertdecode(encmsg);
		p += encmsg.length();
	}
	return decmsg;
}

vector<char> Code::alphacode()
{// This returns a vector containing the alphabet a-z and " " and "."
 vector<char> temp;
 for (char c='A'; c<='Z'; c++)
      temp.push_back(c);
 temp.push_back(' ');
 temp.push_back('.');
 return temp;
}

vector<string> Code::morsecode()
{ // This function returns a vector containing the morse code
 vector<string> temp(28);
 temp[0] = ".- ";
 temp[1] = "-... ";
 temp[2] = "-.-. ";
 temp[3] = "-.. ";
 temp[4] = ". ";
 temp[5] = "..-. ";
 temp[6] = "--. ";
 temp[7] = ".... ";
 temp[8] = ".. ";
 temp[9] = ".--- ";
 temp[10] = "-.- ";
 temp[11] = ".-.. ";
 temp[12] = "-- ";
 temp[13] = "-. ";
 temp[14] = "--- ";
 temp[15] = ".--. ";
 temp[16] = "--.-- ";
 temp[17] = ".-. ";
 temp[18] = "... ";
 temp[19] = "- ";
 temp[20] = "..- ";
 temp[21] = "...- ";
 temp[22] = ".-- ";
 temp[23] = "-..- ";
 temp[24] = "-.-- ";
 temp[25] = "--.. ";
 temp[26] = " ";
 temp[27] = "x";
 return temp;
}

string Code::getnextcodeword(string message, int p) {
/*	string temp;
	for (int i=p; i <= message.length(); i++) {
		temp += message[i];
		if (message[i] == ' ')
			return temp + ' ';
        else if (message[i] == 'x')
			return temp;
*/
    string output;
    while(message[p] != ' ') {
        output += message[p];
        p++;
    }
    output += ' ';
    return output;
}

string Code::convertencode(char message) {
	//subcode of Code::encode
	for (int i = 0; i < this->alpha.size(); i++) {
		if (message == this->alpha[i])
			return this->codewords[i];
	}
}

char Code::convertdecode(string message) {
	//subcode of Code::decode
	for (int i = 0; i < this->codewords.size(); i++) {
		if (message == this->codewords[i])
			return this->alpha[i];
	}
}

int main() {
	Code c;
	string message, output;
	int x = 0;
	
	message = "-... .  ... ..- .-. .  - ---  -.. .-. .. -. -.-  -.-- --- ..- .-.  --- ...- .- .-.. - .. -. . x";
	cout << c.decode(message) << endl;
	message = ".-- --- ..- -. -.. ...  -- -.--  .... . .- .-. -  .-- .. - ....  .-  -- --- -. --- - --- -. --- ..- ...  .-.. .- -. --. --- ..- .-. x";
	cout << c.decode(message) << endl;
	
	cin >> message;
	string decoded = c.decode(message);
    cout << decoded << endl;
	
    cin >> x;
	
	/*
    cout << "To encode enter 0; to decode enter 1: ";
	cin >> x;
	if (x == 0) {
		cout << "Enter a message: ";
		cin >> message;
		cout << c.encode(message) << endl;
	}
	else {
		cout << "Enter code: ";
		cin >> message;
		cout << c.decode(message) << endl;
	}
    */
}
