CXX         = g++
CXXFLAGS    = -std=c++1z -Wall -Wextra -Wparentheses

all: assignment9.exe clean

assignment9.exe: assignment9.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.o
