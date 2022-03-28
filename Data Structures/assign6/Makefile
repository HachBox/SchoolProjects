CXX         = g++
CXXFLAGS    = -std=c++1z -Wall -Wextra -Wparentheses

all: assignment6main clean

assignment6main: assignment6main.o assignment6.o assignment5.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.o
