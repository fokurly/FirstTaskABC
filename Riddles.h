//
// Created by buval on 06.10.2021.
//

#ifndef FIRSTTASKABC_RIDDLES_H
#define FIRSTTASKABC_RIDDLES_H

#include <iostream>
#include <cstring>
#include <fstream>

struct Riddles {
    char *answer;

};

void inputStream(Riddles& riddles, std::ifstream& input);

void OutputStream(Riddles& riddles, std::ofstream& output);

void RandomInput(Riddles& riddles, std::ifstream& input);


#endif //FIRSTTASKABC_RIDDLES_H
