//
// Created by mgalaxy on 10/3/21.
//

#include <bitset>
#include "DebugPrint.h"

void printPRNG() {
    std::cout << "printPRNG" << std::endl;
}

void printU8Binary(u8 toPrint) {
    std::cout << std::bitset<8>((int) toPrint);
}