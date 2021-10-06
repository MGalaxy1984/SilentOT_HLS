//
// Created by MGalaxy on 10/6/21.
//

#include "block.h"

block &block::operator^(const block &op) {
    auto* result = new block();
    for (int i = 0; i < 16; i++) {
        result->data[i] = this->data[i] ^ op.data[i];
    }
    return *result;
}
