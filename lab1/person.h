#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>

struct adress
{
    std::string street, city;
    int zip;
};
struct Person
{
    std::string name, id;
    adress location;
};
//inlänsnings operator
std::ostream& operator<<(std::ostream& os, Person per);
//utskrvings operator
std::istream& operator>>(std::istream& is, Person& per);
//funktionen to_upper omvandlar inlästa strings till stora bokstäver
std::string to_upper(std::string s);

std::vector<Person> read_file(const std::string filename);
// funktionen read_files har två paremeterar och returnerar hur många matchningar de
size_t find_in_names(const std::vector <Person>& haystack, std::string name_part);

std::vector <Person> find_person_from_city(const std::vector<Person>& haystack, std::string city);

void find_name();

void find_city();
