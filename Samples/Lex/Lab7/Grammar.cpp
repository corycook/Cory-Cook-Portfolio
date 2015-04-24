#include "Grammar.h"
/*
 * The constructor opens the file and parses the grammar
 * into object properties. It then calls the functions necessary
 * to build its First, Follow, and LR(0) Sets
 */
Grammar::Grammar (char* filename) {
	this->num_of_productions = 1;
	int state = 0;
	string buffer;
	ifstream gfile;

	// Parse File
	gfile.open(filename, fstream::in);
	char c = gfile.get(), nt;
	while (c != '$') {
		if (c != '\n' && c != ' ' && c != '\t') {
			this->terminals.insert(c);
			this->symbol_set.insert(c);
		}
		c = gfile.get();
	}
	c = gfile.get();
	while (c != '$') {
		if (c != ' ' && c != '\t') {
			switch (state++) {
				case 0: c = gfile.get(); this->start_symbol = c; state++;
					/* no break */
				case 1: nt = c; break;
				case 2|3: break;
				case 4: buffer = c; break;
				default:
					if (c == '\n' || c == '|') {
						this->nonterminals[nt].productions.push_back(buffer);
						this->nonterminal_set[num_of_productions] = nt;
						this->production_set[num_of_productions++] = buffer;
						this->symbol_set.insert(nt);
						state = c == '\n' ? 1 : 4;
					}
					else buffer += c; break;
			}
			if (state > 4 && this->terminals.count(c) == 0 && c != 'e' && c != nt)
				this->nonterminals[c].reference_map.insert(nt);
		}
		c = gfile.get();
	}
	gfile.close();

	// Augmented Start Symbol
	this->AugmentedStart = 'S';
	while (this->symbol_set.count(this->AugmentedStart) > 0) this->AugmentedStart++;
	this->symbol_set.insert(this->AugmentedStart);
	this->nonterminal_set[0] = this->AugmentedStart;
	this->production_set[0] = this->start_symbol;
	this->nonterminals[this->AugmentedStart].productions.push_back(string() + this->start_symbol);
	for (map<char, Productions>::iterator i = this->nonterminals.begin();
			i != this->nonterminals.end(); ++i) {
		i->second.first_set = this->first(i->first);
		i->second.follow_set = this->follow(i->first);
	}
	this->LR0_set = this->LR0();
}
Grammar::~Grammar () { }
set<char> Grammar::first(char target) {
	set<char> p, q;
	if (this->terminals.count(target) != 0 || target == 'e') p.insert(target);
	else {
		for (vector<string>::iterator i = this->nonterminals[target].productions.begin();
				i != this->nonterminals[target].productions.end(); ++i) {
			if ((*i)[0] == target) continue;
			for (unsigned int j = 0; j < (*i).length(); j++)
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
set<char> Grammar::follow(char target) {
	set<char> p, q;
	p.insert('$');
	for (set<char>::iterator i = this->nonterminals[target].reference_map.begin();
			i != this->nonterminals[target].reference_map.end(); ++i) {
		for (vector<string>::iterator j = this->nonterminals[*i].productions.begin();
				j != this->nonterminals[*i].productions.end(); ++j) {
			for (unsigned int k = 0; k < (*j).length(); k++) {
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
/*
 * CLOSURE({a,b})
 * 	set K, J
 * 	J.insert({a,b})
 *  for every production P in Grammar G indexed as i
 *  	if P[a][b] == G[i] and a != i then
 *  		K = CLOSURE({i,0})
 *  		J.insert(K)
 *  return J
 */
set<pair<int, int> > Grammar::CLOSURE(pair<int, int> I) {
	set<pair<int, int> > J, K;
	J.insert(I);
	for (unsigned int i = 0; i < this->num_of_productions; i++) {
		if (this->production_set[I.first][I.second] == this->nonterminal_set[i] &&
				I.first != i) {
			K = CLOSURE(pair<int, int>(i, 0));
			J.insert(K.begin(), K.end());
		}
	}
	return J;
}
/*
 * GOTO({a,b},X)
 * 	if production[a][b] == X and b < production[a].length
 * 		return CLOSURE({a, b+1});
 * 	return empty set;
 */
set<pair<int, int> > Grammar::GOTO(pair<int, int> I, char X) {
	if (this->production_set[I.first][I.second] == X
			&& I.second < this->production_set[I.first].length())
		return this->CLOSURE(pair<int, int>(I.first, I.second+1));
	return set<pair<int, int> >();
}
/*
 * LR0()
 *	C = CLOSURE({0,0});
 *	J.add(C);
 *	do
 *		added = false
 *		for every item I in C
 *			for every symbol X in G
 *				L = GOTO(I,X)
 *				if L is not empty
 *					for every item Y in L
 *						if Y is not in C then
 *							C.add(Y)
 *							added = true
 *					if added is true
 *						J.add(L)
 *	while added is true
 */
vector<set<pair<int, int> > > Grammar::LR0() {
	vector<set<pair<int, int> > > J;
	set<pair<int, int> > C, L;
	bool added;
	int num_added = 0;
	char target;
	C = CLOSURE(pair<int, int>(0, 0));
	J.push_back(C);
	this->LR0_ref[num_added++] = this->AugmentedStart;
	do {
		added = false;
		for (set<pair<int, int> >::iterator p = C.begin(); p != C.end(); ++p) {
			for (set<char>::iterator i = this->symbol_set.begin();
					i != this->symbol_set.end(); ++i) {
				L = GOTO(*p, *i);
				if (!L.empty()) {
					for (set<pair<int, int> >::iterator p = L.begin();
							p != L.end(); ++p) {
						if (C.count(*p) == 0) {
							added = true;
							C.insert(*p);
						}
					}
					if (added) {
						J.push_back(L);
						this->LR0_ref[num_added++] = *i;
					}
				}
			}
		}
	} while (added);
	return J;
}
// Functions below are for printing output
void Grammar::print_nonterminals(const char* seperator) {
	for (map<char, Productions >::iterator p = this->nonterminals.begin();
			p != this->nonterminals.end(); ++p) {
		for (vector<string>::iterator i = p->second.productions.begin(); i != p->second.productions.end(); ++i) {
			if (i != p->second.productions.begin()) cout << seperator << *i;
			else cout << p->first << "->" << *i;
		}
		cout << endl;
	}
}
void Grammar::print_set (set<char> print, char target, const char* prefix, const char* seperator, const char* suffix) {
	cout << target << prefix;
	for (set<char>::iterator q = print.begin(); q != print.end(); ++q) {
		if (q != print.begin())
			cout << seperator << *q;
		else
			cout << *q;
	}
	cout << suffix << endl;
}
void Grammar::print_first_sets() {
	cout << endl << "First Sets" << endl;
	for (map<char, Productions >::iterator p = this->nonterminals.begin();
			p != this->nonterminals.end(); ++p)
		this->print_set(p->second.first_set, p->first, ": ", ", ", "");
}
void Grammar::print_follow_sets() {
	cout << endl << "Follow Sets" << endl;
	for (map<char, Productions >::iterator p = this->nonterminals.begin();
			p != this->nonterminals.end(); ++p)
		this->print_set(p->second.follow_set, p->first, ": ", ", ", "");
}
void Grammar::print_productions() {
	cout << endl << "Productions" << endl;
	for (int i = 0; i < this->num_of_productions; i++) {
		cout << i << ": " << this->nonterminal_set[i] <<
				"->" << this->production_set[i] << endl;
	}
}
void Grammar::print_item_sets(set<pair<int, int> > items) {
	for(set<pair<int, int> >::iterator p = items.begin();
			p != items.end(); ++p) {
		string a = this->production_set[p->first];
		cout << this->nonterminal_set[p->first] << "->"
				<< a.insert(p->second, ".") << "  ";
	}
}
void Grammar::print_LR0_set() {
	int state = 0;
	cout << endl << "LR0 Sets" << endl;
	for (vector<set<pair<int, int> > >::iterator p = this->LR0_set.begin();
			p != this->LR0_set.end(); ++p) {
		cout << "State " << state++ << " \'" << this->LR0_ref[state] << "\': ";
		this->print_item_sets(*p);
		cout << endl;
	}
}
