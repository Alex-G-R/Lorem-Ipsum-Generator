#include <iostream>
#include <string>
#include <cctype>
#include <random>

#include "functions.hpp"

std::string lorem_array[69] =
    {
        "lorem", "ipsum", "dolor", "sit", "amet", "consectetur",
        "adipiscing", "elit", "sed", "do", "eiusmod", "tempor",
        "incididunt", "ut", "labore", "et", "dolore", "magna",
        "aliqua", "Ut", "enim", "ad", "minim", "veniam", "quis"
        "nostrud","exercitation", "ullamco", "laboris",
        "nisi", "ut", "aliquip", "ex", "ea", "commodo", "consequat",
        "duis", "aute", "irure", "dolor", "in", "reprehenderit", "in",
        "voluptate", "velit", "esse", "cillum", "dolore", "eu", "fugiat",
        "nulla", "pariatur", "excepteur", "sint", "occaecat", "cupidatat",
        "non", "proident", "sunt", "in", "culpa", "qui", "officia", "deserunt",
        "mollit", "anim", "id", "est", "laborum"
};

int main()
{
    greet_user();
    int words_to_generate = setup_words();
    int words_generated;

    start_generation(words_generated, words_to_generate);

    return 0;
}

void greet_user()
{
    std::cout << "Hey, this is a lorem text generator." << std::endl;
    std::cout << "Text will be random everytime!" << std::endl;
    std::cout << "The generator will not exceed your word limit." << std::endl;
    std::cout << "If there will be too little words left it will end." << std::endl;
    std::cout << "Generator will always end with a dot, it won't cut off a sentence." << std::endl;
    new_line();
}

int setup_words()
{
    std::cout << "Please provide the number of words you want to generate: ";
    int number_of_words = get_number_input();
    new_line();
    return number_of_words;
}

/* Generation */

void start_generation(int &words_generated, int max_words)
{
    generate_first_passage(words_generated, max_words);
    if(words_generated < max_words)
    {
        generate_sentence(words_generated, max_words);
    }
}

void generate_sentence(int &words_generated, int max_words)
{
    while(words_generated < max_words)
    {
        int random_n = random_sentence_length();
        while(random_n > max_words - words_generated)
        {
            random_n = random_sentence_length();
        }

        int sentence_words_generated = 1;
        std::cout << generate_first_word() << " ";
        while (random_n > sentence_words_generated)
        {
            if(random_n - sentence_words_generated != 1)
            {
                std::cout << generate_word() << " ";
                sentence_words_generated++;
            }
            else
            {
                std::cout << generate_word() << ". ";
                sentence_words_generated++;
            }
        }
        

        words_generated += random_n;
    }
    get_number_input();
}

std::string generate_first_word()
{
    std::string first_word = lorem_array[random_lorem_word()];
    first_word[0] = toupper(first_word[0]);
    return first_word;
}

std::string generate_word()
{
    std::string word = lorem_array[random_lorem_word()];
    return word;
}

void generate_first_passage(int &words_generated, int max_words)
{
    if(max_words >= 8)
    {
        std::cout << "Lorem ipsum dolor sit amet, consectetur adipiscing elit. ";
        words_generated += words_generated + 8;
    }
    else
    {
        std::cout << "You must generate at least 8 words of lorem to fit first passage." << std::endl;
        exit(0);
    }
}

/* Utils */

int random_sentence_length()
{
    std::random_device seed;
    std::mt19937 gen{seed()}; // seed the generator
    std::uniform_int_distribution<> dist{4, 14}; // set min and max
    int n = dist(gen); // generate number
    return n;
}

int random_lorem_word()
{
    std::random_device seed;
    std::mt19937 gen{seed()}; // seed the generator
    std::uniform_int_distribution<> dist{0, 68}; // set min and max
    int n = dist(gen); // generate number
    return n;
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