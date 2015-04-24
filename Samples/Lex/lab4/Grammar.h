#ifndef __GRAMMAR_H__
#define __GRAMMAR_H__
#include <set>
#include <map>
#include <iostream>
#include <vector>
#include <fstream>

struct Productions {
	std::vector<std::string> productions;
	std::set<char> reference_map;
	std::set<char> first_set;
	std::set<char> follow_set;
};

class Grammar
{
    // Grammar properties
	std::set<char> terminals;
	std::set<char> follow_set;
	std::ifstream grammar_file;
	std::map<char, Productions> nonterminals;
    bool start_found;
    char start_state;

    // Private Functions
	void parse_terminals ();
	int parse_nonterminals ();
	void build_first_sets ();
	std::set<char> first (char target);
	void build_follow_sets();
	std::set<char> follow (char target);
	int check(int state, char in);
    void print_set (std::set<char> print, char target, const char* prefix, const char* seperator, const char* suffix);

	public: 
		Grammar (char* filename);
		~Grammar ();
		void print_nonterminals (const char* seperator);
		void print_first_sets();
		void print_follow_sets();
};

#endif 
