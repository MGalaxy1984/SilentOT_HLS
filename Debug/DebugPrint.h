//
// Created by mgalaxy on 10/3/21.
//

#ifndef SILENTOT_HLS_DEBUGPRINT_H
#define SILENTOT_HLS_DEBUGPRINT_H

#include <iostream>
#include <iomanip>
#include <bitset>
#include "../Defines.h"

void printPRNG();

void printMessage();

void printU8Binary(u8);

void printWord(std::array<std::bitset<8>, 4>);

void printWord(std::bitset<8>[4]);




#endif //SILENTOT_HLS_DEBUGPRINT_H
