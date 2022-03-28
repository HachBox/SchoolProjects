#
# PROGRAM: Lab Training Exercise
# AUTHOR:  your name
#

CXXFLAGS = -Wall -Werror -std=c++11

cout: cout.o
	g++ $(CXXFLAGS) -o cout cout.o

cout.o: cout.cpp
	g++ $(CXXFLAGS) -c cout.cpp

clean:
	rm -f *.o cout
