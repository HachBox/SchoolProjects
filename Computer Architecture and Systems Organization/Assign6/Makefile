#
# PROGRAM: C++ Multithreading
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -g -ansi -pedantic -Werror -std=c++14 -pthread

reduce: reduce.o
	g++ $(CXXFLAGS) -o reduce reduce.o

reduce.o: reduce.cpp
	g++ $(CXXFLAGS) -c -o reduce.o reduce.cpp

clean:
	rm -f *.o reduce
