/*
Some basic functions associated with Set:

    begin() – Returns an iterator to the first element in the set.
    end() – Returns an iterator to the theoretical element that follows last element in the set.
    size() – Returns the number of elements in the set.
    insert(val) – Inserts a new element val in the Set.
    find(val) - Returns an iterator pointing to the element val in the set if it is present.
    empty() – Returns whether the set is empty.
    set::lower_bound() - returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter.
    set::upper_bound() -  returns an iterator pointing to the immediate next element which is just greater than k.

*/

#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {

    set<int> s;

    set<int, greater<int>> s; // to store data in decreasing order in the Set

    int arr[] = {40, 20, 60, 30, 50, 50, 10};

    for (int i = 0; i < 7; i++)
        s.insert(arr[i]);

    auto pos = s.find(3);

    for (auto itr = s.begin(); itr != s.end(); itr++) {
        cout << *itr << " ";
    }

    if (s.find(50) != s.end()) {
        cout << "\n\n50 is present";
    } else {
        cout << "\n\n50 is not present";
    }

    return 0;
}
