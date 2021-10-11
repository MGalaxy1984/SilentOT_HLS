//
// Created by MGalaxy on 10/6/21.
//

#ifndef SILENTOT_HLS_AES128UNIT_H
#define SILENTOT_HLS_AES128UNIT_H

#include <array>
#include "../Defines.h"
#include "../Common/block.h"
#include "wmmintrin.h"

class AES128Unit {
private:
    std::array<__m128i, 11> roundKeys;

public:
    AES128Unit() = default;

    static __m128i keyGenerate(__m128i previousKey, __m128i parameter);

    AES128Unit(const __m128i& userKey) {
        roundKeys[0] = userKey;
        roundKeys[1] = keyGenerate(roundKeys[0], _mm_aeskeygenassist_si128(roundKeys[0], 0x01));
        roundKeys[1] = keyGenerate(roundKeys[0], _mm_aeskeygenassist_si128(roundKeys[0], 0x01));
        roundKeys[2] = keyGenerate(roundKeys[1], _mm_aeskeygenassist_si128(roundKeys[1], 0x02));
        roundKeys[3] = keyGenerate(roundKeys[2], _mm_aeskeygenassist_si128(roundKeys[2], 0x04));
        roundKeys[4] = keyGenerate(roundKeys[3], _mm_aeskeygenassist_si128(roundKeys[3], 0x08));
        roundKeys[5] = keyGenerate(roundKeys[4], _mm_aeskeygenassist_si128(roundKeys[4], 0x10));
        roundKeys[6] = keyGenerate(roundKeys[5], _mm_aeskeygenassist_si128(roundKeys[5], 0x20));
        roundKeys[7] = keyGenerate(roundKeys[6], _mm_aeskeygenassist_si128(roundKeys[6], 0x40));
        roundKeys[8] = keyGenerate(roundKeys[7], _mm_aeskeygenassist_si128(roundKeys[7], 0x80));
        roundKeys[9] = keyGenerate(roundKeys[8], _mm_aeskeygenassist_si128(roundKeys[8], 0x1B));
        roundKeys[10] = keyGenerate(roundKeys[9], _mm_aeskeygenassist_si128(roundKeys[9], 0x36));
    }

    __m128i getRoundKey(int index);
};


#endif //SILENTOT_HLS_AES128UNIT_H
