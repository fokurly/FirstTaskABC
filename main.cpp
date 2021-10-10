#include <iostream>
#include <cstring>
#include <ctime>

#include "Container.h"

void InvalidArgs() {
    std::cout << "Invalid input. Use: \"-i <input_file> <out_file_data> <out_file_sorted_data>\" or \"-f <input_file> <out_file_data> <out_file_sorted_data>\"\n";
}

void InputFromFile(char* argv[], Container& container) {
    char str1[256];
    std::ifstream input;
    input.open(argv[2]);
    int size;
    input >> size;

    init(container, size);
    inputStream(container, input);
}

void RandomInput(char* argv[], Container& container) {
    std::cout << "Generating random content...";
    srand(time(NULL));
    int rnd = rand() % 10000;
    rndInput(container, rnd, argv[2]);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        InvalidArgs();
        return 1;
    }

    std::cout << "The program has started.\n";

    Container container;
    std::cout << "Container was created.\n";

    if (strcmp(argv[1], "-i") == 0) {
        InputFromFile(argv, container);
        std::cout << "Container was filled.\n";
    } else if (strcmp(argv[1], "-f") == 0) {
        RandomInput(argv, container);
    } else {
        std::cout << "Argument exception. Use -i or -f.\n";
        return -1;
    }

    std::ofstream output(argv[3]);
    std::ofstream sortedOutput(argv[4]);

    outputStream(container, output);

    std::cout << "Sorting content...\n";
    bubbleSort(container);
    outputStream(container, sortedOutput);

    clear(container);

    std::cout << "End of program.\n";
    return 0;
}
