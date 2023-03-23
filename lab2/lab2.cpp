#include "lab2.h"
#include <iostream>

//Konstruktor skappar en ny tom lista
Linked_list::Linked_list(){
    head = nullptr;
    tail = nullptr;
}
//Distruktur 
Linked_list::~Linked_list(){
    while(head){
        this->pop_front();//om listan inte är tom då tas bort alla element mha pop_front
    }
}
//Retuernerar heads värde
double Linked_list::front() const{
    return head->value;
}
//Reuernerar tails värde
double Linked_list::back() const{
    return tail->value;
}
//kontrollerar om listan är tom
bool Linked_list::is_empty() const 
{ 
    return head == nullptr; 
} 
//Skapar ny node
Linked_list::node::node(double value){
    this->value = value;
    next = nullptr;
    prev = nullptr;
}
//Ligger ny element i slutet av listan 
void Linked_list::push_back(double value){
    node* n = new node(value);// pointer som peekar på nodarnas värde
    if (is_empty()){//kontrollerar om listan är tom 
        head = n;
        tail = n;
    }
    else if ((head != nullptr)&& (head->next == nullptr)){//ifall listan har endast ett element
        head->next = n;
        tail = n;
        tail->prev = head;
    }
    else{
        node* last;
        last = head;
        while (last->next != nullptr){ //loopar genom listan till den hittar sista elementet
            last = last->next;
        } 
        last->next = n;//sista elementet pekar på nya noden 
        tail = n;//nya noden blir listans nya tail
        tail->prev = last;//Nya tail prev pekare pekar på elemntet som hittades mha while loopen dvs listans före tail
    }
}
//ligger till ett ny element i början av listan 
void Linked_list::push_front(double value){
    node* n = new node(value);
    if (is_empty()){//kontrollerar om listan är tom
        head = n;
        tail = n;
    }
    else if ((head != nullptr) && (head->next == nullptr)){//kontroller om listan innehåller enast ett element
        tail->prev = n;
        head = n;
        head->prev = nullptr;
        head->next = tail;
    }
    //Heads prev pekare bli lika med det nya elementet, nya elementet next pekar pekar på listans head
    //nya node är nu listans head
    else{
        head->prev = n;
        n->next = head;
        head = n;
    }
}
//Tar bort sista elementet i listan
double Linked_list::pop_back(){
    double x = tail->value;
    if (is_empty()){//kontorllerar ifall listan är tom;
        return false;
    }
    else if ((head != nullptr) && (head->next == nullptr)){//kontrollerar om listan har endast ett element
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else{//Listans nya tail blir elementet som fanns före listans gamla tail
        //listans nya tail pekare pekare på null på höger sidan
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    return x;
}
//radera listans första element
double Linked_list::pop_front(){
    double x = head->value;

    if(is_empty()){//kontrollerar om listan är tom
        return false;
    }
    else if ((head != nullptr)&&(head->next == nullptr)){//kontrollerar om listan innehåller et element
        delete head;//tar bort listans och gör att både listans head och tail blir lika med null så att listan blir tom
        head = nullptr;
        tail = nullptr;
    }
    else{
        //listans nya head blir elementet som fanns efter listans gamla head
        //listans nya head pekar på null från vänster sidan 
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    return x;
}
//Skriver ut listan
void Linked_list::print_lista() const{
    node* ptr = head;
    while (ptr != nullptr){ //loopar från head till tail tills den hittar noden som pekar på null på höger sidan 
        std::cout<< ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout<<std::endl;
}
//Skriver ut listan baklänges
void Linked_list::print_reverse() const{
    node* ptr = tail;
    while(ptr != nullptr){//Loopar från tail to head tills den hittar node som pekar på null från väsnter sidan
        std::cout << ptr->value << " ";
        ptr = ptr->prev;
    }
    std::cout<<std::endl;
}
//Copy operator, deep copy 
Linked_list::Linked_list(const Linked_list &src){
    node* copy;
    copy = src.head;//shallow copy
    while(copy){//ligger till värden mha push back
        push_back(copy->value);
        copy = copy->next;
    }
}
Linked_list& Linked_list::operator =(const Linked_list &rhs){
    if(this == &rhs){//kontrol mot self assigenment
        return *this;
    }
    while (!is_empty()){//om listan inte är tom körs pop_back tills den blir tom
        pop_back();
    }
    node* copy;
    copy = rhs.head;//shallow copy
    while (copy){//Sparar värden mha push_back for deep copy
        push_back(copy->value);
        copy = copy->next;
    }
    return *this;
    
}
// = operator 
Linked_list& Linked_list::operator+=(const Linked_list &rhs){
    node* copy;
    copy = rhs.head;//shallow copy
    while (copy){
        push_back(copy->value);// Sparar värden mha push_back for deep copy
        copy = copy->next;
    }
    return *this;
}
// Returnerar listans size
size_t Linked_list::size() const{
    int counter = 0;//en räknare
    node* ptr = head;
    while(ptr != nullptr){//loopar genom listan tills den hittar sista elementet
        ptr = ptr->next;
        counter++;//räknaren ökas med ett 
    }
    return counter;
}
//Returnerar värden på en valt pos
double Linked_list::at(size_t pos) const{
    double counter = 0;
    node* ptr = head;
    while (counter < pos){// loopar från head till den valdan pos
        ptr = ptr->next;
        counter++;
    }
    return ptr->value;
}
// Tar bort et element som ligger i en vald pos
void Linked_list::remove(size_t pos){
    double counter = 0;
    node* ptr = head;
    node* temp;
    while (counter < pos){//loopar från head tills den når den valda pos
        ptr = ptr->next;
        counter++;
    }
    //Elementet som hittadas nästa elements prev pekare, blir lika med elementets prev pekare 
    //Elementet som kommer innan elemntet som hittades next pekare pekar på elementets next
    ptr->next->prev = ptr->prev;
    ptr->prev->next = ptr->next;
    delete ptr;
}

void Linked_list::insert(double value, size_t pos){
    int counter = 0;
    node* n = new node(value);
    node* ptr = head;
    while(counter < pos ){// loopar från head tills den når den valda pos
        ptr = ptr->next;
        counter++;
    }
    //elementet som hittades pekar på den nya elementet från vänster sida
    //elementet som kommer innan ptr nästa element blir ptr
    ptr->prev = n;
    ptr->prev->next = ptr;
}