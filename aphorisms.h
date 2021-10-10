//
// Created by buval on 06.10.2021.
//

#ifndef FIRSTTASKABC_APHORISMS_H
#define FIRSTTASKABC_APHORISMS_H
#include <iostream>

struct aphorisms {
     char* author;
};


void inputStream(aphorisms& aphorism, std::ifstream& input);

void OutputStream(aphorisms& aphorism, std::ofstream& output);

void RandomInput(aphorisms& aphorism, std::ifstream& input);




#endif //FIRSTTASKABC_APHORISMS_H
