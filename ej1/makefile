HEADERS = -I headers/armas/ -I headers/personajes/ -I headers/efectos/ -I utils/
SRC = src/armas/*.cpp src/personajes/*.cpp src/efectos/*.cpp

make:
	g++ -std=c++14 -Wall -Wextra $(HEADERS) -g main.cpp $(SRC) -o main
	./main
	rm main
	rm -rf main.dSYM/
