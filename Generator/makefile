
Battleship: funcoes.o embarcacoes.o main.o
	g++ -Wall -std=c++11 funcoes.o embarcacoes.o main.o -o Battleship -lm
	-rm *.o
funcoes.o:
	g++ -std=c++11 -o funcoes.o -c src/funcoes.cpp
embarcacoes.o:
	g++ -std=c++11 -o embarcacoes.o -c src/embarcacoes.cpp
main.o:
	g++ -std=c++11 -o main.o -c src/main.cpp