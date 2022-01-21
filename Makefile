all: analyzer


analyzer: lexer.o symbol.o main.o
	g++ -std=c++11 -o analyzer lexer.o symbol.o main.o

lexer.o: lexer.cpp lexer.h
	g++ -std=c++11 -o lexer.o -c lexer.cpp

symbol.o: symbol.cpp symbol.h
	g++ -std=c++11 -o symbol.o -c symbol.cpp

main.o: main.cpp symbol.h lexer.h
	g++ -std=c++11 -o main.o -c main.cpp

clean:
	rm -rf *.o

clean_all: clean
	rm -rf analyzer