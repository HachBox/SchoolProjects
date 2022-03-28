#
# PROGRAM:    assign6
# PROGRAMMER: Harry Chieng
# LOGON ID:   z1811457
# DATE DUE:   11/10/2017
#

# Compiler variables
CCFLAGS = -ansi -g -Wall -std=c++11

# Rule to link object code files to create executable file
assign6: assign6.o Queue.o
	g++ $(CCFLAGS) -o assign6 assign6.o Queue.o

# Rule to compile source code file to object code
assign6.o: assign6.cpp
	g++ $(CCFLAGS) -c assign6.cpp

Queue.o: Queue.hpp Queue.cpp
	g++ $(CCFLAGS) -c Queue.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign6
