all: analyseur


analyseur: lexer.o symbole.o main.o
	g++ -o analyseur lexer.o symbole.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -o lexer.o -c lexer.cpp

symbole.o: symbole.cpp symbole.h
	g++ -o symbole.o -c symbole.cpp

main.o: main.cpp symbole.h lexer.h
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o

cleanall: clean
	rm -rf analyseur