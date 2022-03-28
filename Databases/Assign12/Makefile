CXX = g++
CXXFLAGS = -Wall -std=c++14 -I/usr/include/mysql
CXXLFLAGS = -L/usr/lib/mysql -lmysqlclient
HPPS = $(wildcard *.h)
OBJECTS = $(HPPS:.h=.o)
	all: mysql.exe
%.bin: $(OBJECTS) %.o
	        $(CXX) $(CXXLFLAGS) -o $@ $^
%.o: %.cc
	        $(CXX) $(CXXFLAGS) -c $^ -o $@
clean:
	        - rm -f *.o *.exe
