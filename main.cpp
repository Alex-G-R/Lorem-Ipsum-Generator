#include <iostream>

#include "functions.hpp"

std::string lorem_array[69] =
    {
        "Lorem", "ipsum", "dolor", "sit", "amet", "consectetur",
        "adipiscing", "elit", "Sed", "do", "eiusmod", "tempor",
        "incididunt", "ut", "labore", "et", "dolore", "magna",
        "aliqua", "Ut", "enim", "ad", "minim", "veniam", "quis"
        "nostrud","exercitation", "ullamco", "laboris",
        "nisi", "ut", "aliquip", "ex", "ea", "commodo", "consequat",
        "Duis", "aute", "irure", "dolor", "in", "reprehenderit", "in",
        "voluptate", "velit", "esse", "cillum", "dolore", "eu", "fugiat",
        "nulla", "pariatur", "Excepteur", "sint", "occaecat", "cupidatat",
        "non", "proident", "sunt", "in", "culpa", "qui", "officia", "deserunt",
        "mollit", "anim", "id", "est", "laborum"
};

int main()
{
    greet_user();
    int words_to_generate = setup_words();

    return 0;
}

void greet_user()
{
    std::cout << "Hey, this is a lorem text generator." << std::endl;
    std::cout << "Text will be random everytime!" << std::endl;
    new_line();
}

int setup_words()
{
    std::cout << "Please provide the number of words you want to generate: ";
    int number_of_words = get_number_input();
    new_line();
    return number_of_words;
}



/* Utils */

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