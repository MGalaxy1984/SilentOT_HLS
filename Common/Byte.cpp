//
// Created by mgalaxy on 10/16/21.
//

#include "Byte.h"

std::string processString(const std::string &inputStr) {
    std::string str = inputStr;
    for (char c : str) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }

    str.erase(std::remove_if(str.begin(), str.end(), isspace), str.end());

    while (str.size() < 32) {
        str += '0';
    }

    return str;
}


void assignKeys(const std::string& keyString, byte key[16]) {
    const std::string hexValues = "0123456789abcdef";
    std::string processedStr = processString(keyString);
    for (int i = 0; i < 16; i += 1) {
        int upperValue = (int) (hexValues.find(processedStr[i * 2]));
        int lowerValue = (int) (hexValues.find(processedStr[i * 2 + 1]));
        int value = (upperValue << 4) + lowerValue;
        key[i] = byte(value);
    }
}

void assignWords(const std::string &keyString, word w[4]) {
    const std::string hexValues = "0123456789abcedf";
    std::string processedStr = processString(keyString);
    for (int i = 0; i < 4; i += 1) {
        for (int j = 0; j < 4; j++) {
            int bitIndex = (i * 4 + j) * 2;
            int upperValue = (int) (hexValues.find(processedStr[bitIndex]));
            int lowerValue = (int) (hexValues.find(processedStr[bitIndex + 1]));
            int value = (upperValue << 4) + lowerValue;
            w[i][j] = byte(value);
        }
    }
}
