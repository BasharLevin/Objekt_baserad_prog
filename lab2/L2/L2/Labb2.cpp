
#include "Labb2.h"
#include <iostream>

//Tom lista
linked_list::linked_list(){
    head = nullptr;
    tail = nullptr;
}

//Distruktor
linked_list::~linked_list(){
}

/*
   Kontroll ifall listanär tom, size() value
*/
bool linked_list::is_empty() const{
    if(size() == 0){
        return true;
    }

    return false;
}

//Lägger till ett element till slutet av listan
void linked_list::push_back(double value){
    node* n = new node(value); //Peekare som peekar på värdet som finns i nodarna
    if (head == nullptr) //Kontrool ifall listan är tom
    {
        head = n;
        tail = n;

    }else if ((head != nullptr) && (head->next == nullptr)) //Kontroll ifall listan innehåller ett element
    {
        head->next = n;
        tail = n;
        tail->prev = head;
    }else
    {
        node* temp;
        for(temp = head; temp->next != nullptr; temp = temp->next){ ; } //Iterate to tail pointer
        temp->next = n;
        tail = n;
        tail->prev = temp;
    }
} 

//Lägger till ett element to början av listan
void linked_list::push_front(double value){
    node* n = new node(value);
    if (head == nullptr)//Kontroll ifall listan är tom
    {
        head = n;
        tail = n;
    }else if ((head != nullptr) && (head->next == nullptr))//Kontroll ifall listan innehåller ett element
    {
        tail->prev = n;
        head = n;
        head->prev = nullptr;
        head->next = tail;
    }else
    {
        head->prev = n;
        n->next = head;
        head = n;
    }  
}

//Utskrift till listorna
void linked_list::print_list(){
    for(node* pt = head; pt != nullptr; pt = pt->next){ //Itererar från head till tail
        std::cout << pt->value << std::endl;
    }
}

//Utskrift till listan men backlängs
void linked_list::print_reverse() const{
    for(node* pt = tail; pt != nullptr; pt = pt->prev){ //Itererar från tail till head för att bli backlängs
        std::cout << pt->value << std::endl;
    }
}

linked_list::node::node(double value) {     //Ny nod
    this->value = value;
    next = nullptr;
    prev = nullptr;
}

//Retunerar värdet där i vilken plats den ligger på
double linked_list::at(size_t pos) const{
    double counter = 0;
    node* temp = head;
    for(temp = head; counter < pos; temp = temp->next){//Iterate from head to the desired pos
        counter++;
    }
    return temp->value;
}

//Raderar värdet där i vilken plats den ligger på
void linked_list::remove(size_t pos){
    double counter = 0;
    node* temp = head;
    for(temp = head; counter < pos; temp = temp->next){//Iterate from head to desired pos
        counter++;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
}

//Man skapar en ny lista som passar (ANTAL ELEMENT) en annan lista 
linked_list& linked_list::operator=(const linked_list &rhs){
    if(this == &rhs){      //undviker self-assignment
        return *this;
    }
    while (!is_empty()){   //Gör listan tom
        pop_back();
    }
    return *this += rhs; // addar varje element till (this) från rhs listan

}


//Raderar sista element i listan 
double linked_list::pop_back(){
    
    double z = tail->value;
    if(head == nullptr){ //en  kontroll ifall den är tom
        return false; 
    }else if ((head != nullptr) && (head->next == nullptr)){ //Kontroll ifall listan inehåller ett element
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return z;
}

   // Raderar fösta element i listan
double linked_list::pop_front(){
    
    if(head == nullptr){ // en  kontroll ifall den är tom
        return false;
    }
    
    double z = head->value;
    if ((head != nullptr) && (head->next == nullptr)){ //Kontroll ifall listan inehåller ett element
        delete head;
        head = nullptr;
        tail = nullptr;
    }else{
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    return z; 
}

// Retunerar listans storlek
size_t linked_list::size() const{
    int counter = 0;
    
    for(node* pt = head; pt != nullptr; pt = pt->next){
        counter++;
    }
    return counter;
}
//Retunerar värdet på head
double linked_list::front() const{
    return head->value;
}

//Retunerar värdet på tail
double linked_list::back() const{
    return tail->value;
}

//För att lägga till listorna till en ny mha +=
linked_list& linked_list::operator+=(const linked_list& rhs) {

    for(node* pt = rhs.head; pt != nullptr; pt = pt->next){ 
        this->push_back(pt->value); //Push back värdet till lhs
    }

    return *this;  
}

// För att fixa en position till det nya värdet i listan
void linked_list::insert(double value, size_t pos){
    int counter = 0;
    node* n = new node(value);
    node* pt;
    for(pt = head; counter < pos; pt = pt->next){    
    }
    pt->prev = n;
    pt->prev->next = pt;

}

// DEep copy
linked_list::linked_list(const linked_list& src) {
    head = nullptr;
    tail = nullptr;
    
    for(int i= 0; i< src.size(); i++){ //itererar genom src
        push_back(src.at(i)); //push_back värde från varje element i src
    }
} 