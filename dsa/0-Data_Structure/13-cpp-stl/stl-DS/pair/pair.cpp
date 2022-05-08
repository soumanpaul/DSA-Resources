#include <bits/stdc++.h>
using namespace std;

// Driver Code
int main() {
    // defining a pair
    pair<int, char> PAIR1;

    // first part of the pair
    PAIR1.first = 100;
    // second part of the pair
    PAIR1.second = 'G';

    cout << PAIR1.first << " ";
    cout << PAIR1.second << endl;

    pair<string, double> PAIR2("GeeksForGeeks", 1.23);

    cout << PAIR2.first << " ";
    cout << PAIR2.second << endl;

    pair<int, double> PAIR1;
    pair<string, char> PAIR2;

    pair<int, int> pair1 = {1, 2};
    int a, b;
    tie(a, b) = pair1;
    // it is initialised to 0
    cout << PAIR1.first;

    // it is initialised to 0
    cout << PAIR1.second;

    cout << " ";

    // // it prints nothing i.e NULL
    cout << PAIR2.first;

    // it prints nothing i.e NULL
    cout << PAIR2.second;

    // Illustrating pair of pairs
    pair<int, pair<int, char>> pair3 = {3, {4, 'a'}};
    int x, y;
    char z;

    // tie(x,y,z) = pair3; Gives compilation error
    // tie(x, tie(y,z)) = pair3; Gives compilation error
    // Each pair needs to be explicitly handled
    x = pair3.first;
    tie(y, z) = pair3.second;
    cout << x << " " << y << " " << z << "\n";
    return 0;
}
