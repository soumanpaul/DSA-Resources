// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to convert decimal
// to binary number
void bin(unsigned n) {
    if (n > 1)
        bin(n >> 1);

    printf("%d", n & 1);
}

// Driver code
int main(void) {
    bin(131);
    printf("\n");
    bin(3);

    // using bitset
    int n = 5, m = -5;
    bitset<8> b(n);
    bitset<8> b1(m);
    cout << "Binary of 5:" << b << endl;
    cout << "Binary of -5:" << b1 << endl;

    // Binary to cpp
    auto number = 0b011;
    cout << number;
    return 0;
}

//