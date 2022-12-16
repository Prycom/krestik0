all:
	g++ src/*.cpp -I SFML-2.5.1/include  -L SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system -o bin/game
	export LD_LIBRARY_PATH=SFML-2.5.1/lib && ./bin/game

start:
	export LD_LIBRARY_PATH=SFML-2.5.1/lib && ./bin/game