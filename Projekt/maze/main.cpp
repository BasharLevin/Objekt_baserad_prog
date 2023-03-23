#include "maze.hpp"

void genPrin();

int main(){
    srand(time(NULL));
    std::string inpt;
    while(1){
    std::cout<<"Choose a function"<<std::endl;
    std::cout<<"1- Generate a maze"<<std::endl;
    std::cout<<"2- Avbryt"<<std::endl;
    std::cin>>inpt;
    if (inpt.length() > 1){
        std::cout<<"Please enter a valid choice"<<std::endl;
        continue;
    }
    char val = inpt[0];
    if((val >= 65 && val <= 90 ) || (val >= 97 && val <= 122))
        std::cout <<"A character ' " << val <<"' was entered";
        
    switch (val)
    {
    case '1' : 
        genPrin();
        break;
    case '2' : 
        return 0;
        break;
    default:
        std::cout<<"Invalid choice"<<std::endl;
        break;
    }
    }
    return 0;
}

void genPrin(){
    Maze l;
    l.dfs();
    std::cout<<l<<std::endl;
}
/*int main(){
    Maze l;
    l.dfs();
    std::cout<<l<<std::endl;
    Maze m;
    std::cout<<m<<std::endl;
    return 0;
}*/