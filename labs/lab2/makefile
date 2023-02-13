all:	main

main: main.o C4Col.o C4Board.o
	g++ -g main.o C4Col.o C4Board.o -o main

main.o: main.cpp
	g++ -c -g main.cpp
C4Col.o:  C4Col.cpp C4Col.h
	g++ -c -g C4Col.cpp
C4Board.o:  C4Board.cpp C4Board.h
	g++ -c -g C4Board.cpp

clean:
	rm -f *.o main
