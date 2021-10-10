//
// Created by buval on 06.10.2021.
//

#include "aphorisms.h"
#include <fstream>
#include <ctime>
#include <stdlib.h>

void inputStream(aphorisms& aphorism, std::ifstream& input) {
    aphorism.author = new char[64];
    input >> aphorism.author;
}

void OutputStream(aphorisms& aphorism, std::ofstream& output) {
    output << "The author of the aphorism is: ";
    output << aphorism.author << "\n";
}

void RandomInput(aphorisms& aphorism, std::ifstream& input) {
    aphorism.author = new char [64];
    srand(time(NULL));
    int word = rand() % 2184;
    for (int i = 0; i < word; ++i) {
        input >> aphorism.author;
    }
}

