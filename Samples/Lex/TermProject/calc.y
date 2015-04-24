%{
	#include <cstdio>
	#include <iostream>
	#include <cmath>
	#include <string.h>
	#include <map>
	using namespace std;
	extern "C" int yylex();
	extern "C" int yyparse();
	extern "C" FILE * yyin;
	void yyerror(const char * s);
	int ylineno = 1;
	map<string, double> symbols;
	map<string, double (*)(double)> funcptr;
%}
%union {
	double dval;
	char * sval;
};
%token ENDL
%token <dval> NUMBER
%token <sval> ID FUNC
%type <dval> E F G T
%%
S: PRG
PRG: D ENDL				{ ylineno++; }
	| PRG D ENDL		{ ylineno++; }
D: ID '=' E				{ cout << $1 << " = " << $3 << endl; symbols[$1] = $3; }
	| E					{ cout << " = " << $1 << endl; }
E: E '+' T				{ $$ = $1 + $3; }
	| E '-' T			{ $$ = $1 - $3; }
	| T
T: T '*' F				{ $$ = $1 * $3; }
	| T '/' F			{
							if ($3 == 0.0) yyerror("divide by zero");
							else $$ = $1 / $3; 
						}
	| G
G: G '^' F				{ $$ = pow($1, $3); }
	| FUNC F			{ $$ = funcptr[$1]($2); }
	| F
F: NUMBER
	| '(' E ')'			{ $$ = $2; }
	| ID				{ $$ = symbols[$1]; }
%%
int main(int argc, char ** argv) {
	funcptr["sin"] = sin;
	funcptr["asin"] = asin;
	funcptr["cos"] = cos;
	funcptr["acos"] = acos;
	funcptr["tan"] = tan;
	funcptr["atan"] = atan;
	funcptr["ceil"] = ceil;
	funcptr["floor"] = floor;
	if (argc > 1) {
		FILE * g_file = fopen(argv[1], "r");
		if (!g_file) {
			cout << "Cannot open calc file." << endl;
			return -1;
		}
		yyin = g_file;
	}
	do {
		yyparse();
	} while (!feof(yyin));
}
void yyerror(const char * s) {
	cout << "error " << ylineno << ": " << s << endl;
	exit(-1);
}