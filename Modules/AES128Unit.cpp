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

void subBytes(word input[Nk]) {
    for (int i = 0; i < Nk; i++) {
        for (int j = 0; j < 4; j++) {
            input[i][j] = SBox[(int) (input[i][j].to_ulong())];
        }
    }
}

void shiftRows(word input[Nk]) {
    byte tmp;
    // the first row doesn't shift
    tmp = input[1][0];
    input[1][0] = input[1][1];
    input[1][1] = input[1][2];
    input[1][2] = input[1][3];
    input[1][3] = tmp;

    tmp = input[2][0];
    input[2][0] = input[2][2];
    input[2][2] = tmp;
    tmp = input[2][1];
    input[2][1] = input[2][3];
    input[2][3] = tmp;

    tmp = input[3][3];
    input[1][3] = input[1][2];
    input[1][2] = input[1][1];
    input[1][1] = input[1][0];
    input[1][0] = tmp;
}

inline uint8_t xTime(uint8_t x) {
    return ((x << 1) ^ (((x >> 7) & 1) * 0x1b));
}

inline byte xTime(byte xByte) {
    auto x = (uint8_t) (xByte.to_ulong());
    return ((x << 1) ^ (((x >> 7) & 1) * 0x1b));
}

inline byte Multiply(byte xByte, byte yByte) {
    auto x = (uint8_t) xByte.to_ulong();
    auto y = (uint8_t) yByte.to_ulong();
    uint8_t result =
            (((y & 1) * x) ^
             ((y >> 1 & 1) * xTime(x)) ^
             ((y >> 2 & 1) * xTime(xTime(x))) ^
             ((y >> 3 & 1) * xTime(xTime(xTime(x)))) ^
             ((y >> 4 & 1) * xTime(xTime(xTime(xTime(x)))))); /* this last call to xTime() can be omitted */
    return {result};
}

void mixColumns(word input[4]) {
    byte tmp1, tmp2, t;
    for (int i = 0; i < 4; ++i) {
        t = input[i][0];
        tmp1 = input[i][0] ^ input[i][1] ^ input[i][2] ^ input[i][3];
        tmp2 = input[i][0] ^ input[i][1];
        tmp2 = xTime(tmp2);
        input[i][0] ^= tmp2 ^ tmp1;
        tmp2 = input[i][1] ^ input[i][2];
        tmp2 = xTime(tmp2);
        input[i][1] ^= tmp2 ^ tmp1;
        tmp2 = input[i][2] ^ input[i][3];
        tmp2 = xTime(tmp2);
        input[i][2] ^= tmp2 ^ tmp1;
        tmp2 = input[i][3] ^ t;
        tmp2 = xTime(tmp2);
        input[i][3] ^= tmp2 ^ tmp1;
    }
}

word wordXOR(word &w1, word &w2) {
    word result;
    result[0] = w1[0] ^ w2[0];
    result[1] = w1[1] ^ w2[1];
    result[2] =w1[2] ^ w2[2];
    result[3] = w1[3] ^ w2[3];
    return result;
}

void AESEncryption(word plaintext[4], word ciphertext[4], word roundKeys[4 * (Nr + 1)]) {
    ciphertext[0] = wordXOR(plaintext[0], roundKeys[0]);
    ciphertext[1] = wordXOR(plaintext[1], roundKeys[1]);
    ciphertext[2] = wordXOR(plaintext[2], roundKeys[2]);
    ciphertext[3] = wordXOR(plaintext[3], roundKeys[3]);

    std::cout << "Round #" << 0 << std::endl;
    for (int j = 0; j < 4; j++) {
        std::cout << "ciphertext[" << j << "]: ";
        printWord(ciphertext[j]);
    }

    for (int i = 1; i < Nr; i++) {
        subBytes(ciphertext);
        shiftRows(ciphertext);
        mixColumns(ciphertext);
        ciphertext[0] = wordXOR(ciphertext[0], roundKeys[i * 4]);
        ciphertext[1] = wordXOR(ciphertext[1], roundKeys[i * 4 + 1]);
        ciphertext[2] = wordXOR(ciphertext[2], roundKeys[i * 4 + 2]);
        ciphertext[3] = wordXOR(ciphertext[3], roundKeys[i * 4 + 3]);
        std::cout << "Round #" << i << std::endl;
        for (int j = 0; j < 4; j++) {
            std::cout << "ciphertext[" << j << "]: ";
            printWord(ciphertext[j]);
        }
    }

    subBytes(ciphertext);
    shiftRows(ciphertext);
    ciphertext[0] = wordXOR(ciphertext[0], roundKeys[Nr * 4]);
    ciphertext[1] = wordXOR(ciphertext[1], roundKeys[Nr * 4 + 1]);
    ciphertext[2] = wordXOR(ciphertext[2], roundKeys[Nr * 4 + 2]);
    ciphertext[3] = wordXOR(ciphertext[3], roundKeys[Nr * 4 + 3]);

    std::cout << "Round #10" << std::endl;
    for (int j = 0; j < 4; j++) {
        std::cout << "ciphertext[" << j << "]: ";
        printWord(ciphertext[j]);
    }
}
