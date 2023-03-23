#ifndef maze_hpp
#define maze_hpp
#include <iostream>
#include <string>
#include <vector>
#include <cstddef>
#include <stack>

class Maze{
public:
    size_t kulm;
    size_t rad;
    //konstruktor
    Maze();
    //Destruktor
    ~Maze();
    //Depth first search
    void dfs();
    //utskrivnings operator
    friend std::ostream &operator<<(std::ostream &os, const Maze &maze);

private:
    std::string Wall;
    std::string Way;

    struct node{
        int x,y;
        bool wall, visited;
        //Konstruktor
        node(int x, int y, bool wall = false){
            this->x = x;
            this->y = y;
            this->wall = wall;
            this->visited = false;
        }
    };
    //2D vector (vector of vectors)
    std::vector<std::vector<node> >maze;
    //Fyller labrynet med rader och kulmoner 
    void grid();
};


#endif