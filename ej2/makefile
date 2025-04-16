HEADERS = -I ../ej1/headers/armas/ -I ../ej1/headers/personajes/ -I ../ej1/headers/efectos/ -I ../utils/ -I Factory.hpp
SRC = ../ej1/src/armas/*.cpp ../ej1/src/personajes/*.cpp ../ej1/src/efectos/*.cpp Factory.cpp

make:
	g++ -std=c++14 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	./main
	rm main
	rm -rf main.dSYM/
