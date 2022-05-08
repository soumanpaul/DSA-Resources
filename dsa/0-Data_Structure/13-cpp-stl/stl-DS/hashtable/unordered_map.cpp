/*
unordered_map vs unordered_set :
In unordered_set, we have only key, no value, these are mainly used to see presence/absence in a set. For example, consider the problem of counting the frequencies of individual words. We can’t use unordered_set (or set) as we can’t store counts.

unordered_map vs map :
map (like set) is an ordered sequence of unique keys whereas in unordered_map key can be stored in any order, so unordered.
The map is implemented as a balanced tree structure that is why it is possible to maintain order between the elements (by specific tree traversal). The time complexity of map operations is O(log n) while for unordered_map, it is O(1) on average.

Methods on unordered_map
A lot of functions are available which work on unordered_map. most useful of them are – operator =, operator [], empty and size for capacity, begin and end for the iterator, find and count for lookup, insert and erase for modification.
The C++11 library also provides functions to see internally used bucket count, bucket size, and also used hash function and various hash policies but they are less useful in real applications.
We can iterate over all elements of unordered_map using Iterator. Initialization, indexing, and iteration are shown in below sample code :

*/

// C++ program to demonstrate functionality of unordered_map
/*

begin(): Returns an iterator pointing to the first element in the container in the unordered_map container.
end(): Returns an iterator pointing to the position past the last element in the container in the unordered_map container.
count(): Counts the number of elements present in an unordered_map with a given key. Since keys are unique in an unordered_map, so it is basically used as a replacement of find() sometimes to check if a key-value pair with a given key exists in the unoredered_map or not.
size(): The size function is used to find the total size of the unorered_map. That is, the total number of elements present in the unordered_map.
erase(): The erase function is used to erase a particular element from the unordered_map. It can also be used to erase a range of elements from the map.

*/

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> umap;
    unordered_map<int, int> ump;
    unordered_map<char, int> um;

    umap["GeeksforGeeks"] = 10;
    umap["Practice"] = 20;
    umap["Contribute"] = 30;

    for (auto x : umap)
        cout << x.first << " " << x.second << endl;

    if (umap.find("Practice") != umap.end())
        cout << "The key Practice Found!\n";

    // insert elements in random order
    ump.insert({20, 130});
    ump.insert({100, 410});
    ump.insert({31, 60});

    auto it = ump.find('a');

    // inserts {3, 6} starting the search from
    // position where 2 is present
    ump.insert(it, {'c', 3});

    auto it1 = umap.find("Practice");
    if (it1 != umap.end())
        cout << "Key is: " << it->first << ", "
             << "Value is: " << it->second;

    umap.erase("Practice");

    cout << "Size after erasing: " << umap.size() << "\n";

    // Erasing a range
    umap.erase(umap.begin(), umap.end());

    // Size after erasing all elements
    cout << "Size after erasing all elements: "
         << umap.size();
}
