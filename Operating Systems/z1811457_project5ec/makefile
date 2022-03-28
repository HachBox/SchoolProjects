#
# PROGRAM: Lab Training Exercise
# AUTHOR:  Harry Chieng
#

CXXFLAGS = -Wall -Werror -pthread -Wuninitialized -Wshadow -Wunused -Wmissing-field-initializers -std=c++17

z1811457_project5: z1811457_project5.o MemoryChunk.o PageTable.o PhysicalMemory.o
	g++ $(CXXFLAGS) -o $@ $^

%.o: %.cpp %.h

%.o: %.c %.hpp

clean:
	-rm -f *.o 
	-rm -f z1811457_project5 
	-rm -f *~
