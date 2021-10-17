//
// Created by mgalaxy on 10/16/21.
//

#ifndef SILENTOT_HLS_BYTE_H
#define SILENTOT_HLS_BYTE_H

#include <bitset>
#include <array>
#include <algorithm>

// 8-bit bitset
typedef std::bitset<8> byte;

// 4 element array of byte (8-bit bitset)
//typedef std::bitset<32> word;
typedef std::array<byte, 4> word;


void assignKeys(const std::string& keyString, byte key[16]);

void assignWords(const std::string& keyString, word w[4]);


#endif //SILENTOT_HLS_BYTE_H
