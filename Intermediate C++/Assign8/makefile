#
# PROGRAM:    assign8
# PROGRAMMER: Harry Chieng
# LOGON ID:   z1811457
# DATE DUE:   11/29/2017
#

# Compiler variables
CCFLAGS = -ansi -g -std=c++11

# Rule to link object code files to create executable file
assign8: assign8.o 
	g++ $(CCFLAGS) -o assign8 assign8.o

# Rule to compile source code file to object code
assign8.o: assign8.cpp sorts.h quicksort.h mergesort.h 
	g++ $(CCFLAGS) -c assign8.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign8
