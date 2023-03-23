/**
 * @file maze.cpp
 * @author Bashar Levin (Bale2100@student.miun)
 * @brief Projekt
 * @date 2022-05-15
 */
#include "maze.hpp"


/**
 * @brief Construct a new Maze:: Maze object
 * 
 */
Maze::Maze(){
    this->kulm = 21;
    this->rad = 21;
    this->Wall = "🌫";
    this->Way = " ";
    grid();
}

Maze::~Maze(){
}
/**
 * @brief Loopar genom rader och kolumner, sparar start och slut punkter i en temporär vektor.
 * skriver jämna rader och kolumner som en vägg och resten som gång.
 * Sparar allt som finns i temp i 2d vektorn.
 */
void Maze::grid(){

    for(int i = 0; i < rad; i++){

        std::vector<node> rader;

        for(int j = 0; j < kulm; j++){

            if (j == 0 && i == 1)//start punkten
                rader.push_back(node(j, i));
            else if (j == kulm - 1 && i == rad - 2 )//Slut punkten
                rader.push_back(node(j, i));
            else if (j % 2 == 0 || i % 2 == 0)// Kontrollerar om de är jämna
                rader.push_back(node(j, i, true));
            else
                rader.push_back(node(j, i));
        }
        maze.push_back(rader);//Spara allt i 2d vektorn
    }
};
/**
 * @brief 
 * 
 * @param os 
 * @param maze 
 * @return std::ostream& 
 */
std::ostream &operator<<(std::ostream &os, const Maze &maze){

    for (int i = 0; i < maze.rad; i++){
        for (int j = 0; j < maze.rad; j++){
            if (j == maze.kulm - 1  && i == maze.rad - 2 )
                os <<"E";
            if (maze.maze[i][j].wall){

                if(j % 2 == 1)
                    os << maze.Wall << maze.Wall << maze.Wall;
                else
                    os << maze.Wall;
            }
            else if (j % 2 ==1)
                os << maze.Way << maze.Way << maze.Way;
            else if (j == 0 && i == 1)
                os <<"S";
            else
                os << maze.Way;
        }
        os << std::endl;
    }
    return os;
}
/**
 * @brief Depth first search.
 * Start node save in a  stack, as long as the stack is not empty this function get its neighbours.
 * it gets all unvisited neighbours then chooses one randomly then set it to visited.
 * 
 * 
 */
void Maze::dfs(){
    
    std::stack<node> S;
    maze[1][1].visited = true;
    S.push(maze[1][1]);

    while(!S.empty()){
        
        node pos = S.top();
        std::vector<node> n;
    
        if (pos.x > 1 && !maze[pos.y][pos.x - 2].visited)//kontrollerar grannen till vänster
            n.push_back(maze[pos.y][pos.x - 2]);
        if (pos.x < kulm - 2 && !maze[pos.y][pos.x + 2].visited) //kontrollerar granne till högre
            n.push_back(maze[pos.y][pos.x + 2]);

        if (pos.y < kulm - 2 && !maze[pos.y + 2][pos.x].visited)//kontrollerar granne ovanför
            n.push_back(maze[pos.y + 2][pos.x]);
        if (pos.y > 1 && !maze[pos.y -2 ][pos.x].visited)//kontrollerar granne under
            n.push_back(maze[pos.y - 2][pos.x]);

        if (n.empty())
            S.pop();
        else{
            node prev = S.top();

            S.push(n[rand() % n.size()]);
            node P = S.top();

            maze[P.y][P.x].visited = true; 
            if (P.x == prev.x && P.y > prev.y)
                maze[P.y - 1][P.x].wall = false;
            if (P.x == prev.x && P.y < prev.y)
                maze[P.y + 1][P.x].wall = false;
            if (P.y == prev.y && P.x > prev.x)
                maze[P.y][P.x - 1].wall = false;
            if (P.y == prev.y && P.x < prev.x)
                maze[P.y][P.x + 1].wall = false;
        }
    }
}
