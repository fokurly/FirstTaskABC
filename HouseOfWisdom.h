//
// Created by buval on 06.10.2021.
//

#ifndef FIRSTTASKABC_HOUSEOFWISDOM_H
#define FIRSTTASKABC_HOUSEOFWISDOM_H

#include <iostream>
#include <cstring>
#include "Proverbs.h"
#include "Riddles.h"
#include "aphorisms.h"


struct HouseOfWisdom {
    enum Key { RIDDLES, APHORISM, PROVERB};


    union {
        Riddles riddle;
        aphorisms aphorism;
        Proverbs proverb;
    };
    Key k;
    char* string = new char[1024];
    int meaning;
};

void inputStream(HouseOfWisdom& hw, std::ifstream& input);

void OutputToStream(HouseOfWisdom& hw, std::ofstream& output);

void RandomInput(HouseOfWisdom& hw, char file_name[]);

int Meaning(HouseOfWisdom& hw);

#endif //FIRSTTASKABC_HOUSEOFWISDOM_H
