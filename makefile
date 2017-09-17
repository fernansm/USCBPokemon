SFMLFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

sfml-app: main.o
	g++ main.o -o USCBPokemon $(SFMLFLAGS)

main.o: main.C
	g++ -c main.C

clean:
	rm *.o
	rm sfml-app
