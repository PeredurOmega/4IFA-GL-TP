CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++0x 
DFLAGS=
EXEC=main

ifdef debug
    DFLAGS=-DDEBUG
endif

all: $(EXEC)

main: lexer.o symbols.o main.o automaton.o state.o
	$(CC) -o $@ $^ $(LDFLAGS)

automaton.o: automaton.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)

state.o: state.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)

lexer.o: lexer.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)

symbols.o: symbols.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)

main.o: main.cpp
	$(CC) -o $@ -c $< $(CFLAGS) $(DFLAGS)


run: all
	@./main

rebuild: cleanall all

clean:
	@rm -rf *.o
	@echo "Binary files deleted."

cleanall: clean
	@rm -rf $(EXEC)
	@echo "Executable deleted."
