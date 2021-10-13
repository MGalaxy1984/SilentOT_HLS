#include "AES128Unit.h"

word setWord(byte &k1, byte &k2, byte &k3, byte &k4) {
    word result(0x00000000);
    word tmp;
    tmp = k1.to_ulong();  // K1
    tmp <<= 24;
    result |= tmp;
    tmp = k2.to_ulong();  // K2
    tmp <<= 16;
    result |= tmp;
    tmp = k3.to_ulong();  // K3
    tmp <<= 8;
    result |= tmp;
    tmp = k4.to_ulong();  // K4
    result |= tmp;
    return result;
}

word rotWord(word &inputWord) {
    word high24 = inputWord << 8;
    word low8 = inputWord >> 24;
    return high24 | low8;
}

word subWord(word &inputWord) {
    word tmp;
    for (int i = 0; i < 32; i += 8) {
        int row = inputWord[i + 7] * 8 + inputWord[i + 6] * 4 + inputWord[i + 5] * 2 + inputWord[i + 4];
        int col = inputWord[i + 3] * 8 + inputWord[i + 2] * 4 + inputWord[i + 1] * 2 + inputWord[i];
        byte val = SBox[row][col];
        for (int j = 0; j < 8; ++j)
            tmp[i + j] = val[j];
    }
    return tmp;
}

void KeyExpansion(byte key[4 * Nk], word w[4 * (Nr + 1)]) {
    word tmp;
    int i = 0;

    // the first 4 bytes are equivalent to the input user key
    while (i < Nk) {
        w[i] = setWord(key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
        ++i;
    }

    i = Nk;

    while (i < 4 * (Nr + 1)) {
        tmp = w[i - 1]; // record the previous word
        if (i % Nk == 0) {
            word rotatedWord = rotWord(tmp);
            w[i] = w[i - Nk] ^ subWord(rotatedWord) ^ keyRcon[i / Nk - 1];
        } else {
            w[i] = w[i - Nk] ^ tmp;
        }
        ++i;
    }
}