all: compile run
compile:
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp
	g++ -I ./include/ -o ./lib/SatirNode.o -c ./src/SatirNode.cpp
	g++ -I ./include/ -o ./lib/Screen.o -c ./src/Screen.cpp
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp
	g++ -I ./include/ -o ./lib/YoneticiNode.o -c ./src/YoneticiNode.cpp

	g++ -I ./include/ -o ./bin/main ./lib/SatirListesi.o ./lib/SatirNode.o ./lib/Screen.o ./lib/YoneticiListesi.o  ./lib/YoneticiNode.o   ./src/main.cpp
run: 
	./bin/Program