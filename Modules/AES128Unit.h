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
    std::array<__m128i, 11> roundKeys;

    AES128Unit() = default;

    static __m128i keyGenerate(__m128i previousKey, __m128i parameter);

    AES128Unit(const __m128i& userKey) {
        roundKeys[0] = userKey;
        roundKeys[1] = keyGenerate(roundKeys[0], _mm_aeskeygenassist_si128(roundKeys[0], 0x01));
    }
};


#endif //SILENTOT_HLS_AES128UNIT_H
