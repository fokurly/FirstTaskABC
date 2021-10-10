//
// Created by buval on 07.10.2021.
//

#include "Container.h"
#include <ctime>

void init(Container& container, int size) {
    container.size = size;
    container.data = new HouseOfWisdom[size];
}

void clear(Container& container) {
    delete container.data;
    container.size = 0;
}

void inputStream(Container& container, std::ifstream& input) {
    for (int i = 0; i < container.size; ++i) {
         HouseOfWisdom hw;
         inputStream(hw, input);
         container.data[i] = hw;
    }
}

void rndInput(Container& container, int size, char file_name[]) {
    init(container, size);

    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        HouseOfWisdom hw;
        RandomInput(hw, file_name);
        container.data[i] = hw;
    }


}

void outputStream(Container& container, std::ofstream& output) {
   output << "Container size: " << container.size << "\n";
    for (int i = 0; i < container.size; ++i) {
        output << "------" << "\n";
        OutputToStream(container.data[i], output);
    }
}

void bubbleSort(Container& container) {
    for (int i = 0; i < container.size; ++i) {
        for (int j = 0; j < container.size - i - 1; ++j) {
            if (container.data[j].meaning > container.data[j+1].meaning) {
                Container container1;
                init(container1, 1);
                container1.data[0] = container.data[j];
                container.data[j] = container.data[j+1];
                container.data[j+1] = container1.data[0];
                clear(container1);
            }

        }
    }

}