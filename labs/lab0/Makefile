CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		gold

gold:	gold.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f gold

test:		test-output 

test-output:	solution
	@echo Testing output...
	@/home/jplank/cs140/Labs/Lab0/gradeall

