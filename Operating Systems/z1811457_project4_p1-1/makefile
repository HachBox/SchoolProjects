#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -pthread

z1811457_project4_p1-1: z1811457_project4_p1-1.o
	gcc $(CXXFLAGS) -o $@ $^

z1811457_project4_p1-1.o: z1811457_project4_p1-1.c
	gcc $(CXXFLAGS) -c -o $@ $^

clean:
	rm -f *.o z1811457_project4_p1-1
