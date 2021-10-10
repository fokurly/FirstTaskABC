//
// Created by buval on 06.10.2021.
//

#include "Proverbs.h"
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <stdlib.h>


void inputStream(Proverbs& proverb, std::ifstream& input) {
    proverb.country = new char[64];
    input >> proverb.country;
}

void OutputStream(Proverbs& proverb, std::ofstream& output) {
    output << "The country of this proverb is: ";
    output << proverb.country << "\n";
}

void RandomInput(Proverbs& proverb, std::ifstream& input) {\
    proverb.country = new char[64];
    int word = rand() % 2184;
    for (int i = 0; i < word; ++i) {
        input >> proverb.country;
    }
}
