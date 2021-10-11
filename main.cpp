#include <iostream>
#include <array>
#include <vector>
#include "Debug/DebugPrint.h"
#include "ModuleReference/AESReference.h"
#include "Modules/AES128Unit.h"
#include "Defines.h"
#include "wmmintrin.h"
//#include "ThirdParty/cryptopp/cryptlib.h"
//#include "ThirdParty/cryptopp/rijndael.h"
//#include "ThirdParty/cryptopp/modes.h"
//#include "ThirdParty/cryptopp/files.h"
//#include "ThirdParty/cryptopp/osrng.h"
//#include "ThirdParty/cryptopp/hex.h"

using namespace std;

int main() {
    int a = _MM_SHUFFLE(3, 3, 3, 3);
    cout << a << endl;
    AES128Unit(_mm_set_epi64x(0, 0));
    return 0;
}
