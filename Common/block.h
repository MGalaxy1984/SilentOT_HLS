//
// Created by MGalaxy on 10/6/21.
//

#ifndef SILENTOT_HLS_BLOCK_H
#define SILENTOT_HLS_BLOCK_H

#include "../Defines.h"
#include <array>
#include <wmmintrin.h>


class block {
private:
    __m128i data;
public:

    block() = default;

    block(const u64 data1, const u64 data2) {
        data = _mm_set_epi64x(data1, data2);
    }

    block& operator^ (const block& op);

    explicit operator __m128i& () {
        return data;
    }

};


#endif //SILENTOT_HLS_BLOCK_H
