#ifndef __GRAMMAR_H__
#define __GRAMMAR_H__
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;

struct Productions {
	vector<string> productions;
	set<char> reference_map;
	set<char> first_set;
	set<char> follow_set;
};

class Grammar
{
	vector<set<pair<int, int> > > LR0_set;
	map<char, Productions> nonterminals;
	string production_set[100];
	char nonterminal_set[100];
	int num_of_productions;
	set<char> symbol_set;
	set<char> follow_set;
	set<char> terminals;
	char AugmentedStart;
	char start_symbol;
	char LR0_ref[100];

	// Private Functions
	set<pair<int, int> > CLOSURE (pair<int, int> I);
	set<pair<int, int> > GOTO (pair<int, int> I, char X);
	vector<set<pair<int, int> > > LR0();
	set<char> first (char target);
	set<char> follow (char target);

	public: 
		Grammar (char* filename);
		~Grammar ();
		void print_nonterminals (const char* seperator);
		void print_set (set<char> print, char target, const char* prefix, const char* seperator, const char* suffix);
		void print_first_sets();
		void print_follow_sets();
		void print_productions();
		void print_item_sets(set<pair<int, int> > items);
		void print_LR0_set();
};

#endif 
