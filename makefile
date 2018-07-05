Project: Barbarian.o BlueMen.o HarryPotter.o Medusa.o Monster.o Queue.o TournamentClientCode.o Vampire.o Zfighterstats.o
	g++ Barbarian.o BlueMen.o HarryPotter.o Medusa.o Monster.o Queue.o TournamentClientCode.o Vampire.o Zfighterstats.o -o Project4BS

Barbarian.o: Barbarian.cpp Barbarian.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp
	g++ -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp
	g++ -c Medusa.cpp

Monster.o: Monster.cpp Monster.hpp
	g++ -c Monster.cpp

Queue.o: Queue.cpp Queue.hpp
	g++ -c Queue.cpp

Vampire.o: Vampire.cpp Vampire.hpp
	g++ -c Vampire.cpp

Zfighterstats.o: Zfighterstats.cpp Zfighterstats.hpp
	g++ -c Zfighterstats.cpp

clean:
	rm Barbarian.o BlueMen.o HarryPotter.o Medusa.o Monster.o Queue.o TournamentClientCode.o Vampire.o Zfighterstats.o
	
