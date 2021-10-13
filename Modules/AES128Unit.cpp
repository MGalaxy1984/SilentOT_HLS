#include "AES128Unit.h"

word setWord(byte &k1, byte &k2, byte &k3, byte &k4) {
    word result{};
    result[0] = byte(k1);
    result[1] = byte(k2);
    result[2] = byte(k3);
    result[3] = byte(k4);
    return result;
}

word rotWord(word &inputWord) {
    word result{};
    result[0] = inputWord[1];
    result[1] = inputWord[2];
    result[2] = inputWord[3];
    result[3] = inputWord[0];
    return result;
}

word subWord(word &inputWord) {
    word tmp;
    for (int i = 0; i < 4; i++) {
        tmp[i] = SBox[(int) (inputWord[i].to_ulong())];
    }
    return tmp;
}

void KeyExpansion(byte key[4 * Nk], word roundKeys[4 * (Nr + 1)]) {
    word tmp;
    int i;

    // the first 4 words are equivalent to the input user key
    for (i = 0; i < Nk; i++) {
        roundKeys[i] = setWord(key[4 * i], key[4 * i + 1], key[4 * i + 2], key[4 * i + 3]);
    }

    for (i = Nk; i < 4 * (Nr + 1); i++) {
        tmp = roundKeys[i - 1]; // record the previous word
        if (i % Nk == 0) {
            tmp = rotWord(tmp);
            tmp = subWord(tmp);
            tmp[0] ^= keyRcon[i / 4];
        }
        roundKeys[i][0] = roundKeys[i - 4][0] ^ tmp[0];
        roundKeys[i][1] = roundKeys[i - 4][1] ^ tmp[1];
        roundKeys[i][2] = roundKeys[i - 4][2] ^ tmp[2];
        roundKeys[i][3] = roundKeys[i - 4][3] ^ tmp[3];
    }
}

void AESEncryption(word plaintext[4], word ciphertext[4], word roundKeys[4 * (Nr + 1)]) {

}

void subBytes(word *input) {

}

void shiftRows(word *input) {

}

void mixColumns(word *input) {

}
