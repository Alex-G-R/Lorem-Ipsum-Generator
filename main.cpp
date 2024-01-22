#include <iostream>


#include "functions.hpp"


int main()
{
    greet_user();
    setup();

    return 0;
}

void greet_user()
{
    std::cout << "Hey, this is a lorem text generator." << std::endl;
    std::cout << "Text will be random everytime!" << std::endl;
    new_line();
}

int setup()
{
    std::cout << "Please provide the number of words you want to generate: ";
    int number_of_words = get_number_input();
    new_line();
}

int get_number_input()
{
    int number;
    std::cin >> number;
    return number;
}

void new_line()
{
    std::cout << "" << std::endl;
}