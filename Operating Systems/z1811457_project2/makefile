#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -std=c++11

z1811457_project2: z1811457_project2.o
	g++ $(CXXFLAGS) -o $@ $^

z1811457_project2.o: z1811457_project2.cpp
	g++ $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f *.o z1811457_project2
