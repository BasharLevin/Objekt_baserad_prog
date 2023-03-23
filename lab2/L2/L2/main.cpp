
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "Labb2.h"

void print_list(linked_list l);
linked_list merge(linked_list& l, linked_list& l2);
bool isSorted(linked_list& l);


int main(){
    linked_list forsta;
    linked_list andra;
    linked_list tredje;
    linked_list fjarde;

    //Uppgift 1
    int randNumb = 0;
    int randomNumber2 = 0;
    for(int i = 0; i < 50; i++){
        int a, b;
        a = std::rand()%5;
        b = std::rand()%5;
        forsta.push_back(randNumb); 
        andra.push_back(randNumb);
        randNumb += a;
        randNumb += b;
    }
    std::cout << "Första Listan" << std::endl;
    print_list(forsta);

    std::cout << "======================================" << std::endl;
    std::cin.get();

    std::cout<< "Andra listan" << std::endl;
    print_list(andra);
    
    
    
    //Uppgift 2
    if(forsta.at(24) > andra.at(24)){
        std::cout << "forsta list har den största talet lagrat på 25:te platsen och är nu en node mindre" << std::endl << std::endl;
        forsta.remove(24); 
    }else if(forsta.at(24) < andra.at(24)){
        std::cout << "andra list har den största talet lagrat på 25:te platsen och är nu en node mindre" << std::endl<< std::endl;
        andra.remove(24);
    }else{
        std::cout << "forsta och andra har lika stort värde på talet lagrat på 25:te platsen så jag väljer att ta bort en node från forsta listan" << std::endl<< std::endl;
        forsta.remove(24);
    }
   
    //Uppgift 3 
    if (forsta.size() < andra.size()){
        std::cout << "tredje listan blir deklarerad av forsta listan då den är mindre." << std::endl;  
        tredje = forsta;
    }else{
        std::cout << "tredje listan blir deklarerad av andra listan då den är mindre." << std::endl;
        tredje = andra;
    } 
    
    //Uppgift 4 
    if (forsta.size() < andra.size()){
        std::cout << "Vi tar bort vartannat element från andra list då den fortfarande har 50 element" << std::endl;
        for(int i = 0; i < 25; i++){
            andra.pop_back();
            andra.push_front(andra.pop_back());
        }
    }
    else{
        std::cout << "Vi tar bort vartannat element från forsta list då den fortfarande har 50 element" << std::endl;
        for(int i = 0; i < 25; i++){
            forsta.pop_back();
            forsta.push_front(forsta.pop_back());
        }
    }

    //Uppgift 5
    if (forsta.size() < andra.size()){
        std::cout << "Listan som skrivs ut är den halverade listan, i detta fall är det forsta" << std::endl;
        print_list(forsta);
    }else{
        std::cout << "Listan som skrivs ut är den halverade listan, i detta fall är det andra" << std::endl;
        print_list(andra);
    }
    
    //Uppgift6
    fjarde = merge(forsta, andra);

    //Uppgift 7
    if(isSorted(fjarde) == true){
        std::cout << "Filen är sorterad och mergad" << std::endl;
        print_list(fjarde);
    }else{
        std::cout << "Filen är sorterad men EJ merged" << std::endl;
        print_list(fjarde);

    }     
    return 0;
}

linked_list merge(linked_list& l, linked_list& l2){
    linked_list ml;  
    while (!l.is_empty() && !l2.is_empty())
    {
        if (l.front() <= l2.front()){
            ml.push_back(l.pop_front());
            
        }else{
            ml.push_back(l2.pop_front());
        }        
    }

    while (!l2.is_empty()){
        ml.push_back(l2.pop_front());
    }
    
    while (!l.is_empty()){
        ml.push_back(l.pop_front());
    }
    
    return ml;
}
bool isSorted(linked_list& l){
    for(int i =0; i < (l.size()-1);i++){
        if(l.at(i) > l.at(i + 1)){
            return false;
        }
    }
    return true;
}
void print_list(linked_list l){
    l.print_list();
}
