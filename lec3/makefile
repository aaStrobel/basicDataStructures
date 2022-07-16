time: main.o time.o
	g++ -o time main.o time.o

main.o: main.cpp
	g++ -c main.cpp

time.o: time.cpp time.h
	g++ -c time.cpp

clean:
	rm time *.o
