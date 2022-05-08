/*

begin() – Returns an iterator to the first element in the multimap.
end() – Returns an iterator to the theoretical element that follows the last element in the multimap.
size() – Returns the number of elements in the multimap.
empty() – Returns whether the multimap is empty.
insert(keyvalue,multimapvalue) – Adds a new element to the multimap.
erase()
multimap::lower_bound(k)
multimap::upper_bound(k)


multimap::equal_range()
 is a built-in function in C++ STL which
returns an iterator of pairs. The pair refers to the bounds of a range
that includes all the elements in the container which have a key equivalent
to k. If there are no matches with key K, the range returned is of length 0
with both iterators pointing to the first element that has a key consideration
to go after
k according to the container’s internal comparison object (key_comp).
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, int> mp;

    mp.insert({10, 20});
    mp.insert({5, 50});
    mp.insert({10, 25});

    for (auto x : mp)
        cout << x.first << " " << x.second << endl;

    // Erase the key 10
    mp.erase(10);
    cout << "\nCount of the key 10: " << mp.count(10);

    // when 3 is not present
    auto it1 = mp.lower_bound(3);
    cout << "The lower bound of key 3 is ";
    cout << (*it1).first << " ";

    // Stores the range of key 1
    auto it = mp.equal_range(1);

    cout << "The multimap elements of key 1 is : \n";
    cout << "KEY\tELEMENT\n";

    // Prints all the elements of key 1
    for (auto itr = it.first; itr != it.second; ++itr) {
        cout << itr->first
             << '\t' << itr->second << '\n';
    }

    return 0;
}
