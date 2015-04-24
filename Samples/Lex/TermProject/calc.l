INT				([0-9]+)
NUMBER			({INT}|({INT}\.{INT})([eE][-+]?{INT})?)
ID				([a-zA-Z]+)
OP				([+-/*\(\)^=])
FUNC			(a?sin|a?cos|a?tan|ceil|floor)
%{
/*
 * Author: Cory Cook
 * TermProject - Calculator
 * Flex (Lex)
 * Recognizes integers or floating point numbers
 *	strings for variable names
 *	operators (,),+,-,*,/,^,=
 */
#include <iostream>
#include "calc.tab.h"
using namespace std;
#define YY_DECL extern "C" int yylex()
%}
%option noyywrap
%%
\n			{ return ENDL; }
{FUNC}		{ yylval.sval = strdup(yytext); return FUNC; }
{NUMBER}	{ yylval.dval = atof(yytext); return NUMBER; }
{ID}		{ yylval.sval = strdup(yytext); return ID; }
{OP}		{ return yytext[0]; }
[ \t] ;
. ;
%%
