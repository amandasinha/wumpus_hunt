CC = g++ -std=c++11	
exe_file = wumpus_hunt

#$() = target name, after : what is needed to make the target
#basically does g++ -o [file_name] (dependencies)
$(exe_file): bats.o event.o game.o gold.o pit.o room.o wumpus.o driver.o		
	$(CC) -o $(exe_file) bats.o event.o game.o gold.o pit.o room.o wumpus.o driver.o

#repeat with dependencies EXCEPT use -c instead of -o
#-c means just compile this shit p much
bats.o: bats.cpp
	$(CC) -c bats.cpp
event.o: event.cpp
	$(CC) -c event.cpp
game.o: game.cpp
	$(CC) -c game.cpp
gold.o: gold.cpp
	$(CC) -c gold.cpp
pit.o: pit.cpp
	$(CC) -c pit.cpp
room.o: room.cpp
	$(CC) -c room.cpp
wumpus.o: wumpus.cpp
	$(CC) -c wumpus.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

#if you wanna delete
clean:
	rm -f *.out *.o $(exe_file)