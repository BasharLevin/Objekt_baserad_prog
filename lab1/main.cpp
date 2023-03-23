#include "person.h"
#include <iostream>


int main()
{

    char choice;
    while (1)
    {
        std::cout << "\t Meny" << std::endl;
        std::cout << "1- Find by name" << std::endl;
        std::cout << "2- Find by city" << std::endl;
        std::cout << "3- End program" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            find_name();
            break;
        case '2':
            find_city();
            break;
        case '3':
            return 0;
        default:
            break;
        }

    }
    return 0;
}