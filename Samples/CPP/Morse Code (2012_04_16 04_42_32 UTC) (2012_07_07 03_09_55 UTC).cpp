class Code
{
public:
  
  Code();  // Default constructor - loads morse code

  Code(vector<int> codewords);  // constructor loading customized code
  
  string encode(string message);  // encodes a message consisting of A-Z

  string decode(string message);  // decodes a message 

private:

  vector<string> codewords; // this is a parallel vector to A-Z

  vector<char>  alphacode(); // function returns vector - A B C etc.

  vector<string>  morsecode(); // function returns vector containing morse code

  string getnextcodeword(string message, int p); //returns the next codeword in message beginning at position p

};