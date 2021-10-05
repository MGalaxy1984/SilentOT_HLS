#include <iostream>
#include <array>
#include <vector>
#include "Debug/DebugPrint.h"

//using namespace std;

typedef struct {
    uint64_t data0;
    uint64_t data1;
} block;

int main() {
    std::vector<uint64_t> a(19);
    std::cout << a.size() << std::endl;
    printU8Binary(100);
    return 0;
}
