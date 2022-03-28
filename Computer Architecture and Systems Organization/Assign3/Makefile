#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -std=c++11 -errors -Wextra

memsim: main.o memory.o hex.o main.o
	g++ $(CXXFLAGS) -o memsim memory.o hex.o main.o

main.o: main.cpp hex.hpp memory.hpp
	g++ $(CXXFLAGS) -c -o main.o main.cpp

memory.o: memory.cpp memory.hpp
	g++ $(CXXFLAGS) -c -o memory.o memory.cpp

hex.o: hex.cpp hex.hpp
	g++ $(CXXFLAGS) -c -o hex.o hex.cpp
clean:
	rm -f *.o memsim
