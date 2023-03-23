#include "lab2.h"
#include <iostream>
#include <cstdlib>
/**
 * @brief skriver ut listan 
 * @param l Linked list
 * har ingen return värde
 */
void print_list(Linked_list l);


/**
 * @brief Ligger ihop två Länkade listor och sorterar de
 * param två Linkad_lists
 * @return Linked_list 
 * The merged and sorted linked list
 */
Linked_list merge(Linked_list&, Linked_list&);

/**
 * @brief Kontrollerar om listan är sorrterad
 * @param l en linked_list
 * @return true om listan är sorterad
 * @return false om listan inte är sorterad
 */
bool sorted(Linked_list& l);

int main(){
    //uppgift 1
    srand(time(NULL));
    Linked_list l1;
    Linked_list l2;
    Linked_list l3;
    Linked_list l4;
    int n1= 0, n2 = 0, n3 = 0;
    int frst = 0, scnd = 0;
    while (n3 < 50){
        n1 = std::rand()%5;
        n2 = std::rand()%5;
        l1.push_back(frst);
        l2.push_back(scnd);
        frst += n1;
        scnd += n2;
        n3++;
    }
    
    std::cout<<"First list : " <<std::endl;
    std::cout<< "************"<<std::endl;
    l1.print_lista();
    std::cout<< "======================================================"<<std::endl;
    std::cin.get();
    std::cout <<"Seconde list : " << std::endl;
    std::cout<< "************"<<std::endl;
    l2.print_lista();
    std::cout<< "======================================================"<<std::endl;
    std::cin.get();
    
    //uppgift 2 
    if(l2.at(24) < l1.at(24)){
        std::cout << "The first list has the bigger 25th elment : " << l1.at(24)<<std::endl;
         std::cout<< "======================================================"<<std::endl;
        l1.remove(24);
    }
    else if (l2.at(24) > l1.at(24)){
        std::cout<< "The second list has the bigger 25th element : " << l2.at(24)<<std::endl;
         std::cout<< "======================================================"<<std::endl;
        l2.remove(24);
    }
    else{
        std::cout << "Both list has the same element at pos 25, it will be removed from the first list"<<std::endl;
        std::cout<< "======================================================"<<std::endl;
        l1.remove(24);
    }
    
    std::cin.get();
    
    //uppgift 3
    if(l1.size() > l2.size()){
     
        l3 = l2;
        std::cout<<"The third list in revers : "<<std::endl;
        std::cout<< "************************"<<std::endl;
        l3.print_reverse();
        std::cout<< "======================================================"<<std::endl;
    }
    else{
        l3 = l1;
        std::cout<<"The third list in revers : "<<std::endl;
        std::cout<< "************************"<<std::endl;
        l3.print_reverse();
        std::cout<< "======================================================"<<std::endl;
    }

    std::cin.get();
    
    //uppgift 4 
    if(l1.size() > l2.size()){
        std::cout<<"Vartannat element från första listan tas bort"<<std::endl;
        std::cout<< "======================================================"<<std::endl;
        for(int i = 0; i < 25; i++){
            l1.pop_back();
            l1.push_front(l1.pop_back());
        }
    }
    else{
        std::cout<<"Vartannat element från andra listan tas bort"<<std::endl;
        std::cout<< "======================================================"<<std::endl;
        for(int i = 0; i <25; i++){
            l2.pop_back();
            l2.push_back(l2.pop_back());
        }
    }

    //uppgift 5 
    if (l1.size() < l2.size()){
        print_list(l1);
    }
    else{
        print_list(l2);
    }

    //uppgift 6
    l4 = merge(l1,l2);
    std::cout<<std::endl;
    std::cin.get();
    std::cout<< "The new merged list : "<<std::endl;
    std::cout<< "======================================================"<<std::endl;
    l4.print_lista();
    std::cout<<std::endl;
    std::cout<<"size of the merged list = "<< l4.size()<<std::endl;

    //uppgift 7
    sorted(l4);


    return 0;
}
void print_list(Linked_list l){
    l.print_lista();
}

Linked_list merge(Linked_list& first, Linked_list& second){
    Linked_list merge;
    while(!first.is_empty() && !second.is_empty()){
        if (first.front() < second.front()){
            merge.push_back(first.pop_front());
        }
        else{
            merge.push_back(second.pop_front());
        }  
    }
    
    merge += first;
    merge += second;
    return merge;
}
bool sorted(Linked_list& l){
    for(int i = 0; i < l.size()-1; i++){
        if(l.at(i) > l.at(i +1 )){
            std::cout<<"The list is not sorted"<<std::endl;
            return false;
        }
    }
    std::cout<<"The list is sorted"<<std::endl;
    return true;
}