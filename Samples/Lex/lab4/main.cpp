#include "Grammar.h"

int main(int argc, char ** argv)
{
	Grammar * G = new Grammar (argv[1]);
	printf("\nProductions\n");
	G->print_nonterminals("|");
	printf("\nFirst Sets\n");
	G->print_first_sets();
	printf("\nFollow Sets\n");
	G->print_follow_sets();
	return 0;
}
