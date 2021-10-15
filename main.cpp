#include <iostream>
#include "Modules/AES128Unit.h"
#include "Debug/DebugPrint.h"
//#include "Defines.h"

int main() {
    byte key[16] = {0xab, 0x00, 0x00, 0x00,
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
        std::cout << "roundKeys[" << std::dec << i << "] = ";
        printWord(roundKeys[i]);
    }

    word plaintext[4] = {{0x00, 0x00, 0x00, 0x00},
                         {0x0a, 0xb0, 0x00, 0x00},
                         {0x00, 0x00, 0x00, 0x00},
                         {0x00, 0x00, 0x00, 0x11}};
    word ciphertext[4];

    AESEncryption(plaintext, ciphertext, roundKeys);

    std::cout << "Encrypted Word" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "ciphertext[" << i << "]: ";
        printWord(ciphertext[i]);
    }

    return 0;
}
