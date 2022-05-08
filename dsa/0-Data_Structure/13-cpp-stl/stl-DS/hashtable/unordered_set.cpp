
// C++ program to illustrate unordered_set

/*

insert()– Inserts a new {element} in the unordered_set container.
begin()– Returns an iterator pointing to the first element in the unordered_set container.
end()– Returns an iterator pointing to the past-the-end-element.
strong>clear()– Removes all of the elements from an unordered_set and empties it.
size()– Return the number of elements in the unordered_set container.
find() - The find() function returns an iterator to end() if key is not there in set, otherwise an iterator to the key position is returned. The iterator works as a pointer to the key values so that we can get the key by dereferencing them using * operator.
count(): - The count() function works similar to the find() function. It is used to return the count of a key present in the unordered_set, but as unordered_set doesnot allows duplicates, the count function returns 1 if the key is present in the set or 0 if it is not present.
erase():  The erase() function is used to remove either a single element of a range of elements ranging from start(inclusive) to end(exclusive).

*/

#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;

    // Inserting elements using
    // insert() function
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(20);

    // Traversing the unordered_set
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << (*it) << " ";
    }
    cout << endl;

    cout << "Size of unordered_set: " << s.size() << endl;

    // Clear all elements
    s.clear();

    cout << "Size after clearing unordered_set: "
         << s.size() << endl;

    return 0;
}
