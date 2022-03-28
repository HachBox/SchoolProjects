#
# PROGRAM:    assign9
# PROGRAMMER: Harry Chieng
# LOGON ID:   z1811457
# DATE DUE:   12/05/2017
#

# Compiler variables
CCFLAGS = -ansi -g -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o 
	g++ $(CCFLAGS) -o assign9 assign9.o

# Rule to compile source code file to object code
assign9.o: assign9.cpp shape.h circle.h cylinder.h cone.h
	g++ $(CCFLAGS) -c assign9.cpp shape.cpp circle.cpp cylinder.cpp cone.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
