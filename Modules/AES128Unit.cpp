//
// Created by MGalaxy on 10/6/21.
//

#include "AES128Unit.h"

__m128i AES128Unit::keyGenerate(__m128i previousKey, __m128i parameter) {
    return _mm_set_epi64x(0, 0);
}
