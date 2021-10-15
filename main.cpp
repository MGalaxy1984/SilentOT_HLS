#include <iostream>
//#include "Debug/DebugPrint.h"
#include "Modules/AES128Unit.h"
//#include "Defines.h"

int main() {
    byte key[16] = {0x11, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x00,
                    0x00, 0x00, 0x00, 0x11};

    word roundKeys[4 * (Nr + 1)];

    std::cout << "KEY IS: ";
    for (int i = 0; i < 16; ++i)
        std::cout << std::hex << key[i].to_ulong() << " ";
    std::cout << std::endl;

    KeyExpansion(key, roundKeys);
    for (int i = 0; i < 4 * (Nr + 1); ++i) {

            std::cout << "roundKeys[" << std::dec << i << "] = " << std::hex << roundKeys[i][0].to_ulong() << roundKeys[i][1].to_ulong() << roundKeys[i][2].to_ulong() << roundKeys[i][3].to_ulong() << std::endl;
    }

    word plaintext[4] = {{0x00, 0x00, 0x00, 0x00},
                         {0x0a, 0xb0, 0x00, 0x00},
                         {0x00, 0x00, 0x00, 0x00},
                         {0x00, 0x00, 0x00, 0x11}};
    word ciphertext[4];

    AESEncryption(plaintext, ciphertext, roundKeys);

//    for (int i = 0; i < 4; i++) {
//        std::cout << "ciphertext[" << i << "]: ";
//        std::cout << std::hex << ciphertext[i][0].to_ulong() << ciphertext[i][1].to_ulong()
//                  << ciphertext[i][2].to_ulong() << ciphertext[i][3].to_ulong();
//        std::cout << std::endl;
//    }

    return 0;
}
