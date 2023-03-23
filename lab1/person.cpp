#include "person.h"

std::ostream& operator<<(std::ostream& os, Person per)
{
    os << per.name << "\n" << per.id << "\n" << per.location.street << "\n" << per.location.city << "\n" << per.location.zip << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Person& per)
{
    char a = ',';
    std::string s;
    int zip2;
    std::string zip1, location, location2;
    std::getline(is, per.name);
    std::getline(is, per.id);
    std::getline(is, per.location.street, a);
    std::getline(is, s);
    zip1 = s.substr(0, 7);
    location = s.erase(0, 9);
    location.erase(remove(location.begin(), location.end(), ' '), location.end());
    per.location.city = location;

    for (int i = 0; i < zip1.length(); i++)
    {
        if (zip1[i] == ' ')
        {
            zip1.erase(i, 1);
        }
        std::stringstream omv(zip1);
        omv >> zip2;
        per.location.zip = zip2;

    }
    return is;
}

std::string to_upper(std::string s)
{
    std::transform(s.begin(), s.end(), s.begin(), ::toupper);
    /*
    while (s.find("å") != std::string::npos)
        s.replace(s.find("å"), 2, "Å");
    while (s.find("ä") != std::string::npos)
        s.replace(s.find("ä"), 2, "Ä");
    while (s.find("ö") != std::string::npos)
        s.replace(s.find("ö"), 2, "Ö");
      */
    return s;
}
std::vector<Person> read_file(const std::string filename)
{
    std::ifstream file(filename);
    std::vector<Person> per;
    Person p;
    while (file >> p)
    {
        per.push_back(p);
    }
    return per;
}
size_t find_in_names(const std::vector <Person>& haystack, std::string name_part) {

    name_part = to_upper(name_part);
/*
* funktionen find_in_names är en funktion som innehåller två parameterar.
* funktionen räknar hur många matchningar lambda funktionen hittar
* Lambda funktionen omvandlar stringen till stor bokstäver sen returnar matchningar om de finns

*/
    return std::count_if(haystack.begin(), haystack.end(), [&](const Person& p) {
        std::string temp = p.name;
        temp = to_upper(temp);

        return temp.find(name_part) != std::string::npos;



        });
};

std::vector <Person> find_person_from_city(const std::vector<Person>& haystack, std::string city) {

    city = to_upper(city);
    std::vector <Person> person_found;
    for (std::vector<Person>::const_iterator it = haystack.begin(); it != haystack.end(); it++) {

        std::string tem;
        tem = (*it).location.city; //tem = it->location.city 
        tem = to_upper(tem);
      
        if (tem == city) {

            person_found.push_back(*it);
        }
    }
    return person_found;


}

void find_name()
{
    std::string part;
    Person p;
    auto lista = read_file("names.txt");
    std::cout << "write a name" << std::endl;
    std::cin >> part;
    auto count = find_in_names(lista, part);
    std::cout << "the name : " << part << " was found " << count << " times" << std::endl;
}

void find_city()
{
    std::string ort;
    auto list = read_file("names.txt");
    std::cout << "Write a city" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, ort);
    ort.erase(remove(ort.begin(), ort.end(), ' '), ort.end());
    auto result = find_person_from_city(list, ort);
    if (!result.empty())
    {
        for (std::vector<Person>::const_iterator it = result.begin(); it != result.end(); it++)
        {

            std::cout << "found " << (*it).name << " lives in " << (*it).location.city << std::endl;

        }

    }
    else {
        std::cout << "No such name was found" << std::endl;

    }
    std::cout << ort << std::endl;
}