

void greet_user();
int setup_words();

/* Generation */
void start_generation(int &words_generated, int max_words);
void generate_first_passage(int &words_generated, int max_words);
void generate_sentence(int &words_generated, int max_words);
std::string generate_first_word();
std::string generate_word();

/* Utils */
int random_sentence_length();
int random_comma_space();
int random_lorem_word();
int get_number_input();
void new_line();