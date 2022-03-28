#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -std=c++11 -Wextra

rv32i: main.o memory.o hex.o rv32i_decode.o
	g++ $(CXXFLAGS) -o $@ $^

rv32i_decode.o: rv32i_decode.cpp rv32i_decode.h hex.h memory.h

main.o: main.cpp hex.h memory.h

memory.o: memory.h hex.h memory.cpp

hex.o: hex.h hex.cpp

clean:
	-rm -f *.o rv32i
