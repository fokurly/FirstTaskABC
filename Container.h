//
// Created by buval on 07.10.2021.
//

#ifndef FIRSTTASKABC_CONTAINER_H
#define FIRSTTASKABC_CONTAINER_H

#include "HouseOfWisdom.h"

struct Container {
    enum {max_size = 10000};

    int size;
    HouseOfWisdom* data;

};

void init(Container& container, int size);

void clear(Container& container);

void inputStream(Container& container, std::ifstream& input);

void rndInput(Container& container, int size, char file_name[]);

void outputStream(Container& container, std::ofstream& output);

void bubbleSort(Container& container);



#endif //FIRSTTASKABC_CONTAINER_H
