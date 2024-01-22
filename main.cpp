#include <iostream>


#include "functions.hpp"


int main()
{
    greet_user();


    return 0;
}

void greet_user()
{
    std::cout << "Hey, this is a lorem text generator." << std::endl;
    std::cout << "Text will be random everytime!" << std::endl;
}