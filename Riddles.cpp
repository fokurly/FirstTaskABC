//
// Created by buval on 06.10.2021.
//

#include "Riddles.h"
#include <istream>
#include <ctime>
#include <stdlib.h>

void inputStream(Riddles& riddles, std::ifstream& input) {
    riddles.answer = new char[64];
    input >> riddles.answer;
}

void OutputStream(Riddles& riddles, std::ofstream& output) {
    output << "The answer on the riddle is: ";
    output << riddles.answer << "\n";
}

void RandomInput(Riddles& riddles, std::ifstream& input) {
    riddles.answer = new char[64];
    int word = rand() % 2184;

    for (int i = 0; i < word; ++i) {
        input >> riddles.answer;
    }
}



