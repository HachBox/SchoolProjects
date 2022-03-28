#
# PROGRAM: IPC
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -g -ansi -pedantic -Werror -std=c++14 -pthread

all: client server

client: client.o
	g++ $(CXXFLAGS) -o client client.o

server: server.o
	g++ $(CXXFLAGS) -o server server.o

client.o: client.cpp
	g++ $(CXXFLAGS) -c -o client.o client.cpp

server.o: server.cpp
	g++ $(CXXFLAGS) -c -o server.o server.cpp

clean:
	rm -f *.o client server
