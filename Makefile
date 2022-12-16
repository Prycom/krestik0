all:
	g++ -c src/main.cpp -I SFML-2.5.1/include -o obj/main.o
	g++ obj/main.o -o bin/sfml-app -L SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=SFML-2.5.1/lib && ./bin/sfml-app