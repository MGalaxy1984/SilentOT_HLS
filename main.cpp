#include <iostream>
#include "Modules/AES128Unit.h"
#include "Debug/DebugPrint.h"
//#include "Defines.h"
#include "Common/Byte.h"

int main() {
//    byte key[16] = {0xab, 0x00, 0x00, 0x00,
//                    0x00, 0x00, 0x00, 0x00,
//                    0x00, 0x00, 0x00, 0x00,
//                    0x00, 0x00, 0x00, 0x11};
    byte key[16];
    std::string keyValue = "11412d654bca23ea87dfdadba826e894";
    assignKeys(keyValue, key);

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

    word plaintext[4];
    std::string textValue = "00000000 00000000 00000000 00000000";
    assignWords(textValue, plaintext);
    std::cout << "Plain text" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "plaintext[" << i << "]: ";
        printWord(plaintext[i]);
    }

    word ciphertext[4];

    AESEncryption(plaintext, ciphertext, roundKeys);

    std::cout << "Encrypted Word" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "ciphertext[" << i << "]: ";
        printWord(ciphertext[i]);
    }

    return 0;
}
