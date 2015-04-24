calc.o: lex.yy.c
	g++ calc.tab.c lex.yy.c -o calc.o -lm
lex.yy.c: calc.l calc.tab.h calc.tab.c
	flex calc.l
calc.tab.h calc.tab.c: calc.y
	bison -d calc.y
clean:
	rm calc.tab.* lex.yy.c