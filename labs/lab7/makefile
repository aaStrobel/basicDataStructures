CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		nqueens2

nqueens2:	nqueens2.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f nqueens2 

test:		test-8 test-10

test-8:	nqueens2
	@echo Testing board size of 8 input/output...
	@diff --suppress-common-lines -y <(./nqueens2 8) output

test-10: nqueens2
	@echo Testing board size of 10 input/output...
	@diff --suppress-common-lines -y <(./nqueens2 10) output2
