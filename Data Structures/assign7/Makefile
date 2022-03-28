CXX         = g++
CXXFLAGS    = -std=c++1z -Wall -Wextra -Wparentheses

all: assignment7main clean

assignment7main: assignment7.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.o
