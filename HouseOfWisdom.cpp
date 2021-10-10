//
// Created by buval on 06.10.2021.
//

#include "HouseOfWisdom.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctime>


void inputStream(HouseOfWisdom& hw, std::ifstream& input ) {
    int type;
    memset(hw.string, 0, sizeof hw.string);
    HouseOfWisdom::Key type2;
    int temp_size = 0;
    input >> type >> temp_size;

    if (type == 1) {
        type2 = HouseOfWisdom::RIDDLES;
        for (int i = 0; i < temp_size; ++i) {
            char temp[64];
            memset(temp, 0, sizeof temp);
            input >> temp;
            strcat(hw.string, temp);
            strcat(hw.string, " ");
        }
        inputStream(hw.riddle, input);
    } else if (type == 2) {
        type2 = HouseOfWisdom::APHORISM;
        for (int i = 0; i < temp_size; ++i) {
            char temp[255];
            memset(temp, 0, 255);
            input >> temp;

            strcat(hw.string, temp);
            strcat(hw.string, " ");
        }

        inputStream(hw.aphorism, input);

    } else if (type == 3) {
        type2 = HouseOfWisdom::PROVERB;
        for (int i = 0; i < temp_size; ++i) {
            char temp[255];
            memset(temp, 0, 255);
            input >> temp;

            strcat(hw.string, temp);
            strcat(hw.string, " ");
        }

        inputStream(hw.proverb, input);

    } else {
        std::cout << "Wrong input! Please use 1 to select proverb, 2 to select riddles, 3 to select aphorisms.";
        return;
    }

    hw.meaning = Meaning(hw);
    hw.k = type2;
}

void OutputToStream(HouseOfWisdom& hw, std::ofstream& output) {
    if (hw.k == HouseOfWisdom::PROVERB) {
        OutputStream(hw.proverb, output);
    } else if (hw.k == HouseOfWisdom::APHORISM) {
        OutputStream(hw.aphorism, output);
    } else if (hw.k == HouseOfWisdom::RIDDLES) {
        OutputStream(hw.riddle, output);
    }

    output << "Content: " << hw.string << "\n";
    output << "Special meaning of this content: " << hw.meaning << "\n";
}



void RandomInput(HouseOfWisdom& hw, char file_name[]) {
    srand(time(NULL));
    memset(hw.string, 0, sizeof hw.string);
    int type = rand() % 3 + 1;
    int num_of_words = rand() % 9;
    if (num_of_words == 0) {
        ++num_of_words;
    }

    HouseOfWisdom::Key type2;
    if (type == 1) {
        type2 = HouseOfWisdom::RIDDLES;


        for (int i = 0; i < num_of_words; ++i) {
            std::ifstream input(file_name);
            int word = rand() % 2184;
            int count = 0;
            char temp_word[64];
            memset(temp_word, 0, sizeof temp_word);
            for (int j = 0; j < word; ++j) {
                input >> temp_word;
            }
            strcat(hw.string, temp_word);
            strcat(hw.string, " ");
        }

        std::ifstream input(file_name);

        RandomInput(hw.riddle, input);

    } else if (type == 2) {
        type2 = HouseOfWisdom::APHORISM;
        for (int i = 0; i < num_of_words; ++i) {
            std::ifstream input(file_name);
            int word = rand() % 2184;
            int count = 0;
            char temp_word[64];
            memset(temp_word, 0, sizeof temp_word);
            for (int j = 0; j < word; ++j) {
                input >> temp_word;
            }
            strcat(hw.string, temp_word);
            strcat(hw.string, " ");
        }

        std::ifstream input(file_name);
        RandomInput(hw.aphorism, input);

    } else if (type == 3) {
        type2 = HouseOfWisdom::PROVERB;
        for (int i = 0; i < num_of_words; ++i) {
            std::ifstream input(file_name);
            int word = rand() % 2184;
            int count = 0;
            char temp_word[64];
            memset(temp_word, 0, sizeof temp_word);
            for (int j = 0; j < word; ++j) {
                input >> temp_word;
            }
            strcat(hw.string, temp_word);
            strcat(hw.string, " ");
        }

        std::ifstream input(file_name);
        RandomInput(hw.proverb, input);

    }

    hw.meaning = Meaning(hw);
    hw.k = type2;
}


int Meaning(HouseOfWisdom& hw) {
    int count = 0;
    for (int i = 0; i < strlen(hw.string); ++i)  {
        if (hw.string[i] == '.' || hw.string[i] == ',' || hw.string[i] == ';' || hw.string[i] == ' ') {
            ++count;
        }
    }

    if (count == 1)
        return 1;

    return strlen(hw.string) / count;
}