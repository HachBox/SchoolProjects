#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -std=c++11 -Wfatal-errors

prog2: prog2.o
	g++ $(CXXFLAGS) -o prog2 prog2.o

prog2.o: prog2.cpp
	g++ $(CXXFLAGS) -c prog2.cpp

clean:
	rm -f *.o prog2
