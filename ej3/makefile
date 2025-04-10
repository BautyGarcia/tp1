HEADERS = -I ../ej2/headers/armas/ -I ../ej2/headers/personajes/ -I ../ej2/headers/efectos/ -I ../utils/ -I Factory.hpp
SRC = ../ej2/src/armas/*.cpp ../ej2/src/personajes/*.cpp ../ej2/src/efectos/*.cpp Factory.cpp

make:
	g++ -std=c++11 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	./main
	rm main
	rm -rf main.dSYM/
