#
# PROGRAM:    assign4
# PROGRAMMER: Harry Chieng
# LOGON ID:   z1811457
# DATE DUE:   10/19/2017
#

# Compiler variables
CCFLAGS = -ansi -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o Complex.o
	g++ $(CCFLAGS) -o assign4 assign4.o Complex.o

# Rule to compile source code file to object code
assign4.o: assign4.cpp
	g++ $(CCFLAGS) -c assign4.cpp

Complex.o: Complex.h Complex.cpp
	g++ $(CCFLAGS) -c Complex.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
