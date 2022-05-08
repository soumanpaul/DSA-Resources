//  Multiset is similar to set except the fact that it can also store duplicate elements,

/*
 multiset::erase()  -      used to erase all occurrences of a particular element from the multiset.
 multiset::count()  -      element in the multiset container and returns the number of occurrence of that element.
 multiset::lower_bound() -  returns an iterator pointing to the first element in the container which is equivalent to k passed in the paramete
 multiset::upper_bound()   -
 multiset::equal_range() is a built-in function in C++ STL which returns an iterator of pairs.

*/

#include <algorithm>
#include <iostream>
#include <set>

using namespace std;
int main() {
    multiset<int> s = {15, 10, 15, 11, 10, 18, 18, 20, 20};

    auto it = s.lower_bound(2);
    s.erase(15);
    s.erase(s.begin(), s.end());

    cout << "15 occurs " << s.count(15)
         << " times in container.\n";
    cout << "15 occurs " << s.count(15)
         << " times in container.\n";
    cout << "Size of multiset: " << s.size();

    return 0;
}
