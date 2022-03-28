CXX         = g++
CXXFLAGS    = -std=c++1z -Wall -Wextra -Wparentheses

all: assignment8run clean

assignment8run: assignment8.o
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cc
	$(CXX) $(CXXFLAGS) -o $@ -c $^

clean:
	rm -f *.o
