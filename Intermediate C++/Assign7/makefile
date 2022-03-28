#
# PROGRAM:    assign7
# PROGRAMMER: Harry Chieng
# LOGON ID:   z1811457
# DATE DUE:   11/16/2017
#

# Compiler variables
CCFLAGS = -ansi -g -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o 
	g++ $(CCFLAGS) -o assign7 assign7.o

# Rule to compile source code file to object code
assign7.o: assign7.cpp Stack.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
