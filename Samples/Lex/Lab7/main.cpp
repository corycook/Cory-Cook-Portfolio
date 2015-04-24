#include "Grammar.h"

int main(int argc, char ** argv)
{
	Grammar * G = new Grammar (argv[1]);
	G->print_productions();
	G->print_first_sets();
	G->print_follow_sets();
	G->print_LR0_set();
	return 0;
}
