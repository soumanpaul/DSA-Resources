#include <iostream>
using namespace std;

// function template
template <typename T>
T myMax(T x, T y) {
    return (x > y) ? x : y;
}



int main () {
    cout << myMax(2,4);
    cout << myMax('d','l');
    cout << myMax(2.67,4.45);
return 0;
}