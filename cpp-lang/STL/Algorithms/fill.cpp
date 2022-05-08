/*
fill() - The ‘fill’ function assigns the value ‘val’ to all the elements in the range [begin, end), where ‘begin’ is the initial position and ‘end’ is the last position.
fill_n() - In fill_n(), we specify beginning position, number of elements to be filled and values to be filled.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> vect(8);

    // calling fill to initialize values in the
    // range to 4
    fill(vect.begin() + 2, vect.end() - 1, 4);

    // calling fill to initialize first four values
    // to 7
    fill_n(vect.begin(), 4, 7);

    for (int i = 0; i < vect.size(); i++)
        cout << vect[i] << " ";
    return 0;
}
