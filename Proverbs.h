//
// Created by buval on 06.10.2021.
//

#ifndef FIRSTTASKABC_PROVERBS_H
#define FIRSTTASKABC_PROVERBS_H

#include <fstream>


struct Proverbs {
    char* country;
};

void inputStream(Proverbs& proverb, std::ifstream& input);

void OutputStream(Proverbs& proverb, std::ofstream& output);

void RandomInput(Proverbs& proverb, std::ifstream& input);



#endif //FIRSTTASKABC_PROVERBS_H
