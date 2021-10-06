#include <iostream>
#include <array>
#include <vector>
#include "Debug/DebugPrint.h"
#include "ModuleReference/AESReference.h"

//using namespace std;

typedef struct {
    uint64_t data0;
    uint64_t data1;
} block;

int main() {
    AESReference a;
    a.test();
    return 0;
}
