#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -pthread

z1811457_project4_p1: z1811457_project4_p1.o
	gcc $(CXXFLAGS) -o $@ $^

z1811457_project4_p1.o: z1811457_project4_p1.c
	gcc $(CXXFLAGS) -c -o $@ $^

clean:
	-rm -f *.o 
	-rm -f z1811457_project4_p1 
	-rm -f *~
