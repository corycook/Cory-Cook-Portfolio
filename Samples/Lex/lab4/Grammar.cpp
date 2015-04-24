#include "Grammar.h"
Grammar::Grammar (char* filename)
{
    this->start_found = false;
	this->grammar_file.open(filename, std::fstream::in);
	this->parse_terminals();
	this->parse_nonterminals();
	this->build_first_sets();
	this->build_follow_sets();
}
Grammar::~Grammar ()
{
	this->grammar_file.close();
}
/* PARSE_TERMINALS
 * 	every nonblank or newline character up to '$' is a terminal
 */
void Grammar::parse_terminals()
{
	char c = this->grammar_file.get();
	while (c != '$')
	{
		if (c != '\n' && c != ' ' && c != '\t')
			this->terminals.insert(c);
		c = this->grammar_file.get();
	}
}
/* PARSE_NONTERMINALS
 * 	Start state is 0 
 * 	get char from file while char is blankspace
 * 	loop while char is not '$'
 * 		STATE 0: START state assumes first non-blank 
 * 			character is newline after PARSE_TERMINALS 
 * 			ended with '$'
 * 		STATE 1: first character on new line is nonterminal
 * 		STATE 2 & 3: absorb "->" symbols
 * 			optional syntax checking may be done here
 * 		STATE 4: first element of production
 * 		DEFAULT: add elements to the production until
 * 			newline '\n' or bar '|' character is reached
 * 				if newline return to state 1 if bar return to state 4
 * 				write production
 * 		if state higher than 4 and c is not 'e', a terminal, or the current nonterminal
 * 			add c to reference map of current nonterminal
 */
int Grammar::parse_nonterminals()
{
	int state = 0;
	std::string buffer;
	char nt, c;
	do
		c = this->grammar_file.get(); 
	while (c == ' ' || c == '\t');
	while (c != '$') {
		switch (state++) {
			case 0: break; 
			case 1: nt = c;
                    if (!this->start_found) this->start_state = c;
                    this->start_found = true;
			case 2: case 3: break;
			case 4: buffer = c; break;
			default:
				if (c == '\n' || c == '|') {
					this->nonterminals[nt].productions.push_back(buffer);
					state = c == '\n' ? 1 : 4;
				}
				else buffer += c; break;
		}
		if (state > 4 && this->terminals.count(c) == 0 && c != 'e' && c != nt)
			this->nonterminals[c].reference_map.insert(nt);
		do
			c = this->grammar_file.get(); 
		while (c == ' ' || c == '\t');
	}
}
/* BUILD_FIRST_SETS
 * runs FIRST on every nonterminal
 */
void Grammar::build_first_sets() {
	for (std::map<char, Productions>::iterator i = this->nonterminals.begin();
		   	i != this->nonterminals.end(); ++i)
		i->second.first_set = this->first(i->first);
}
/* FIRST (target)
 * 	create sets p (output) and q (temp)
 * 	if terminal or 'e' return set {target}
 * 	else
 * 		loop through productions of target 
 * 			if left recursive skip production
 *			loop through elements in production
 *				q = FIRST (element)
 *				if set q contains 'e' and not last element in production remove 'e'
 *				p += q
 *				if set q does not contain 'e' break out of loop
 * 	return p
 */
std::set<char> Grammar::first(char target) {
	std::set<char> p, q;
	if (this->terminals.count(target) != 0 || target == 'e') p.insert(target);
	else {
		for (std::vector<std::string>::iterator i = this->nonterminals[target].productions.begin();
				i != this->nonterminals[target].productions.end(); ++i) {
			if ((*i)[0] == target) continue;
			for (int j = 0; j < (*i).length(); j++)
			{
				q = first((*i)[j]);
				if (q.count('e') != 0 && j != (*i).length() - 1) q.erase('e');
				p.insert(q.begin(), q.end());
				if (q.count('e') == 0) break;
			}
	   	}
	}
	return p;
}
void Grammar::build_follow_sets() {
	for (std::map<char, Productions>::iterator i = this->nonterminals.begin();
		   	i != this->nonterminals.end(); ++i)
		i->second.follow_set = this->follow(i->first);
}
/* FOLLOW (target)
 * 	create sets p (output) and q (temp)
 * 	loop through nonterminals
 * 		loop through productions
 * 			loop through characters in production
 * 				if character is target
 * 					if target is last character
 * 						q = FOLLOW (nonterminal)
 * 					else
 * 						q = FIRST (character+1)
 * 						if set q contains 'e' 
 * 							remove 'e'
 * 							p += q
 * 							q = FOLLOW (nonterminal)
 * 					p += q
 */
std::set<char> Grammar::follow(char target) {
	std::set<char> p, q;
	if (start_state == target) p.insert('$');
    for (std::set<char>::iterator i = this->nonterminals[target].reference_map.begin();
            i != this->nonterminals[target].reference_map.end(); ++i) {
        for (std::vector<std::string>::iterator j = this->nonterminals[*i].productions.begin();
                j != this->nonterminals[*i].productions.end(); ++j) {
            for (int k = 0; k < (*j).length(); k++) {
                if ((*j)[k] == target) {
                    if (k == (*j).length() - 1) q = follow(*i);
                    else {
                        q = first ((*j)[k + 1]);
                        if (q.count('e') != 0) {
                            q.erase('e');
                            p.insert(q.begin(), q.end());
                            q = follow(*i);
                        }
                    }
                    p.insert(q.begin(), q.end());
                }
            }
        }
    }
	return p;
}
// Everything below is for printing output.
void Grammar::print_nonterminals(const char* seperator) {
	for (std::map<char, Productions >::iterator p = this->nonterminals.begin(); 
			p != this->nonterminals.end(); ++p) {
		for (std::vector<std::string>::iterator i = p->second.productions.begin(); i != p->second.productions.end(); ++i) {
			if (i != p->second.productions.begin()) std::cout << seperator << *i;
			else std::cout << p->first << "->" << *i;
		}
		std::cout << std::endl;
	}
}
void Grammar::print_set (std::set<char> print, char target, const char* prefix, const char* seperator, const char* suffix) {
	std::cout << target << prefix;
	for (std::set<char>::iterator q = print.begin(); q != print.end(); ++q) {
		if (q != print.begin())
			std::cout << seperator << *q;
		else
			std::cout << *q;
	}
	std::cout << suffix << std::endl;
}
void Grammar::print_first_sets() {
	for (std::map<char, Productions >::iterator p = this->nonterminals.begin(); 
			p != this->nonterminals.end(); ++p) 
		this->print_set(p->second.first_set, p->first, ": ", ", ", "");
}
void Grammar::print_follow_sets() {

	for (std::map<char, Productions >::iterator p = this->nonterminals.begin(); 
			p != this->nonterminals.end(); ++p) 
		this->print_set(p->second.follow_set, p->first, ": ", ", ", "");
}
