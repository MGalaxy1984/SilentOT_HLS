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
    std::array<u8, 16> data{};
    __m128i data2;
public:

    block() {
        for (u8 element : data) {
            element = 0;
        }
    }

    block(const block& ref) {
        for (int i = 0; i < 16; i++) {
            data[i] = ref.data[i];
        }
    }

    block(const u64 data_higher, const u64 data_lower) {
        for (int i = 0; i < 8; i++) {
            data[i] = (u8)((data_higher >> ((7 - i) * 8)) & 0xFF);
        }
        for (int i = 0; i < 8; i++) {
            data[i + 8] = (u8)((data_lower >> ((7 - i) * 8)) & 0xFF);
        }
    }

    block& operator^ (const block& op);

};


#endif //SILENTOT_HLS_BLOCK_H
