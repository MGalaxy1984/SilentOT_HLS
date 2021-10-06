//
// Created by MGalaxy on 10/6/21.
//

#ifndef SILENTOT_HLS_AES128UNIT_H
#define SILENTOT_HLS_AES128UNIT_H

#include <array>
#include "../Defines.h"
#include "../Common/block.h"

class AES128Unit {
    std::array<block, 11> roundKeys;

    AES128Unit() = default;

    AES128Unit(const block& userKey) {
        roundKeys[0] = block(userKey);

    }
};


#endif //SILENTOT_HLS_AES128UNIT_H
