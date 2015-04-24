/* options */
%option noyywrap
/* definitions */
string				([a-zA-Z][a-zA-Z0-9]*)
encapsulation		(\(|\)|\{|\}|\[|\]|\<|\>)
operators			("<<"|">>"|"+"|"-"|"="|"*"|"/"|"++"|"--")
identifier			({string}|{encapsulation}|{operators})
%{
	#include <iostream>
	#include <fstream>
	#include <string.h>
	#include <map>
	#include <vector>
	#include <set>
	using namespace std;
	int yylineno = (0);
	const int num_of_keywords = 45;
	string x[num_of_keywords] = {
		"bool", "break", "case", "catch", "char",
		"class", "const", "continue", "double", "else",
		"enum", "false", "float", "for", "friend",
		"if", "int", "long", "namespace", "new", 
		"not", "operator", "or", "private", "protected",
		"public", "return", "short", "signed", "sizeof",
		"static", "struct", "switch", "template", "this",
		"throw", "true", "try", "typedef", "unsigned", 
		"using", "virtual", "void", "while", "xor"
	};
	set<string> keywords(x, x+num_of_keywords);
	map<string, vector<int> > identifiers;
%}
%x COMMENT
%%
"//"[^\n]*          ECHO;
"/*"                ECHO; BEGIN COMMENT;
\n                  printf("\n%i\t", yylineno++);
{identifier}		ECHO; identifiers[yytext].push_back(yylineno-1);
[ \t]				ECHO;
<COMMENT>"*/"       ECHO; BEGIN INITIAL;
<COMMENT>\n         printf("\n%i\t", yylineno++);
<COMMENT>.			ECHO;
%%
int main(int argc, char **argv)
{
	istream* file = new ifstream(argv[1]);
    FlexLexer* lexer = new yyFlexLexer();
	lexer->switch_streams(file);
	cout << "-SOURCE-\n" << yylineno << "\t";
    while (lexer->yylex() != 0);
	cout << "\n-IDENTIFIERS-\n";
	for (map<string, vector<int> >::iterator i = identifiers.begin();
		i != identifiers.end(); ++i) {
		if (keywords.find(i->first) == keywords.end()) {
			cout << i->first << ": ";
			for (int j = 0; j < identifiers[i->first].size(); ++j) {
				cout << identifiers[i->first][j] << " ";
			}
			cout << endl;
		}
	}
    return 0;
}
