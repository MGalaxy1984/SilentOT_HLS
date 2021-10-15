//
// Created by mgalaxy on 10/3/21.
//

#include "DebugPrint.h"

void printPRNG() {
    std::cout << "printPRNG" << std::endl;
}

void printU8Binary(u8 toPrint) {
    std::cout << std::bitset<8>((int) toPrint);
}

void printByte(std::bitset<8> byteToPrint) {
    std::cout << std::setfill('0') << std::setw(2)
              << std::right << std::hex
              << byteToPrint.to_ulong();
}

void printWord(std::array<std::bitset<8>, 4> wordToPrint) {
    printByte(wordToPrint[0]);
    printByte(wordToPrint[1]);
    printByte(wordToPrint[2]);
    printByte(wordToPrint[3]);
    std::cout << std::endl;
}

void printWord(std::bitset<8> wordToPrint[4]) {
    std::array<std::bitset<8>, 4> tmp;
    for (int i = 0; i < 4; i++) {
        tmp[i] = wordToPrint[i];
    }
    printWord(tmp);
}
