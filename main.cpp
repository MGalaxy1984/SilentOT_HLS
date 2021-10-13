#include <iostream>
//#include "Debug/DebugPrint.h"
#include "Modules/AES128Unit.h"
//#include "Defines.h"

int main() {
    byte key[16] = {0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x01};

    word w[4 * (Nr + 1)];

    std::cout << "KEY IS: ";
    for (int i = 0; i < 16; ++i)
        std::cout << std::hex << key[i].to_ulong() << " ";
    std::cout << std::endl;

    KeyExpansion(key, w);
    for (int i = 0; i < 4 * (Nr + 1); ++i) {

            std::cout << "w[" << std::dec << i << "] = " << std::hex << w[i][0].to_ulong() << w[i][1].to_ulong() << w[i][2].to_ulong()<< w[i][3].to_ulong() << std::endl;
    }

    return 0;
}
