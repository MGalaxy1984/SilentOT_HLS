#include <iostream>
#include <array>
#include <vector>

using namespace std;

typedef struct {
    uint64_t data0;
    uint64_t data1;
} block;

int main() {
    uint32_t a = 60;
    uint32_t b = 55;
    uint32_t c = a ^ b;
    cout << "Hello, World HIIII!" << c << endl;
    vector<array<block, 2>> message;
    return 0;
}
