CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++0x
LDFLAGS=
EXEC=main

all: $(EXEC)

main: lexer.o symbol.o main.o automaton.o state.o
	$(CC) -o $@ $^ $(LDFLAGS)

automaton.o: automaton.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

state.o: state.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

lexer.o: lexer.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

symbol.o: symbol.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

clean_all: clean
	rm -rf $(EXEC)
