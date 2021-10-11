//
// Created by MGalaxy on 10/6/21.
//

#include "AES128Unit.h"


__m128i AES128Unit::keyGenerate(__m128i previousKey, __m128i parameter) {
    parameter = _mm_shuffle_epi32(parameter, _MM_SHUFFLE(3, 3, 3, 3));
    previousKey = _mm_xor_si128(previousKey, _mm_slli_si128(previousKey, 4));
    previousKey = _mm_xor_si128(previousKey, _mm_slli_si128(previousKey, 4));
    previousKey = _mm_xor_si128(previousKey, _mm_slli_si128(previousKey, 4));
    return _mm_xor_si128(previousKey, parameter);
    // return _mm_set_epi64x(0, 0);
}

__m128i AES128Unit::getRoundKey(int index) {
    return roundKeys[index];
}


