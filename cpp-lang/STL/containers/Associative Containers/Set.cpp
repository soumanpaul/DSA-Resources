/*
    Sets follow ----> the Binary search tree implementation.



Some basic functions associated with Set:

    0(1) - complexity

    begin() – Returns an iterator to the first element in the set.
    end() – Returns an iterator to the theoretical element that follows last element in the set.
    size() – Returns the number of elements in the set.
    empty() – Returns whether the set is empty.

    rbegin()	Returns a reverse iterator pointing to the last element in the container.
    rend()	Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
    crbegin()	Returns a constant iterator pointing to the last element in the container.
    crend()	Returns a constant iterator pointing to the position just before the first element in the container.
    cbegin()	Returns a constant iterator pointing to the first element in the container.
    cend()	Returns a constant iterator pointing to the position past the last element in the container

    0(log n) - complexity

    contains(key) – Returns whether the set contains the given key.
    clear() – Removes all elements from the set.
    count() – Returns the number of elements in the set with the given key.
    insert(val) – Inserts a new element val in the Set.
    find(val) - Returns an iterator pointing to the element val in the set if it is present.
    lower_bound() - returns an iterator pointing to the element in the container which is equivalent to k passed in the parameter.
    upper_bound() -  returns an iterator pointing to the immediate next element which is just greater than k.

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
