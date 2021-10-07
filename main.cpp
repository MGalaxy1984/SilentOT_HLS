#include <iostream>
#include <array>
#include <vector>
#include "Debug/DebugPrint.h"
#include "ModuleReference/AESReference.h"
#include "Defines.h"
#include "wmmintrin.h"

using namespace std;

typedef struct {
    uint64_t data0;
    uint64_t data1;
} block;

int main() {
    __m128i a = _mm_set_epi64x(10, 0);
    cout << sizeof a << endl;
    return 0;
}
