//
// Created by mgalaxy on 10/4/21.
//

#ifndef SILENTOT_HLS_MESSAGE_H
#define SILENTOT_HLS_MESSAGE_H

#include <array>
#include "../Defines.h"

class Message {
public:
    Message() = default;

    ~Message() = default;

private:
    std::array<u8, NUMBER_OF_MSG_BYTES> data;


};


#endif //SILENTOT_HLS_MESSAGE_H
