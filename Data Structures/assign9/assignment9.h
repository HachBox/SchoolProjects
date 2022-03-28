#ifndef ASSIGNMENT9_H
#define ASSIGNMENT9_H
#include <vector>
#include <list>

typedef int vertex;

class graph {
    private:
        int size;
        std::vector< std::list<vertex> > adj_list;
        std::vector< char > labels;
        void depth_first(vertex);
    public:
        graph( const char* filename );
        int get_size() const;
        void traverse( ) ;
        void print ( ) const;
};

#endif 
