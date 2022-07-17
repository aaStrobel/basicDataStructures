CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		gold

gold:	gold.cpp
	$(CXX) $(CXXFLAGS) -o bin/$@ $^

clean:
	rm -f gold

test:		test-output 

test-output:	gold
	@echo Testing output...
	@/home/jplank/cs202/Labs/Lab0/gradeall

