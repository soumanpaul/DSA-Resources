// C++ Program to illustrate map in C++ STL
/*
    map::find() :
    map::count()
    map::lower_bound(k)
    map::upper_bound()
    map::erase()
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
using namespace std;

int main() {

    map<int, int> m;

    m.insert({10, 100});
    m.insert({30, 300});
    m[20] = 200;
    m[40];

    for (auto itr = m.begin(); itr != m.end(); itr++) {
        cout << itr->first << itr->second << '\n';
    }
    m[40] = 400;

    if (m.find(3) != m.end())
        cout << "3 Found!\n\n";
    else
        cout << "3 Not Found!\n";

    // when 2 is present
    auto it = m.lower_bound(2);
    cout << "The lower bound of key 2 is ";
    cout << (*it).first << " " << (*it).second << endl;

    return 0;
}
