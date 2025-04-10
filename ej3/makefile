HEADERS = -I ../ej1/headers/armas/ -I ../ej1/headers/personajes/ -I ../ej1/headers/efectos/ -I ../utils/ -I ../ej2/Factory.hpp -I main.hpp
SRC = ../ej1/src/armas/*.cpp ../ej1/src/personajes/*.cpp ../ej1/src/efectos/*.cpp ../ej2/Factory.cpp

make:
	g++ -std=c++11 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	./main
	rm main
	rm -rf main.dSYM/
