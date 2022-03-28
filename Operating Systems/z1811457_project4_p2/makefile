#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -pthread

z1811457_project4_p2: z1811457_project4_p2.o
	gcc $(CXXFLAGS) -o $@ $^

z1811457_project4_p2.o: z1811457_project4_p2.c
	gcc $(CXXFLAGS) -c -o $@ $^

clean:
	-rm -f *.o 
	-rm -f z1811457_project4_p2 
	-rm -f *~
