
// CPP program to implement
/*
assign() : This function is used to assign values to forward list,
            its another variant is used to assign repeated elements.
remove(): This function removes all the elements from the forward list that
                is mentioned in its argument.

insert_after(): This function gives us a choice to insert elements at
     O(m)                any position in forward list. The arguments in this function are copied at the desired position. Look into the linked article to get more details.

emplace_after() This function also does the same operation as above function but
                     the elements are directly made without any copy operation.
                      For a large object of data the emplace_after() function is more optimised than the insert_after() function.

push_front() :O(1)


pop_front():0(1)

reverse():  O(n)
erase_after() This function is used to erase elements from a particular position in the forward_list.
     O(m)
clear(): This function is used to remove all the elements of the forward list container, thus making its size 0

empty(): This function returns a boolean value indicating whether the forward_list is empty, i.e. whether its size is 0 or not.

reverse(): This is an inbuilt function in CPP STL which reverses the order of the elements present in the forward_list.
merge(): This is an inbuilt function in C++ STL which merges two sorted forward_lists into one. This function merges the second list into the first, thus emptying the second list.
sort(): This function is used to sort the elements of the container by changing their positions.


forward_list l1 = {5, 15, 10};

         l1.sort();
*/

// doubly linked list
#include <forward_list>
#include <iostream>
using namespace std;

int main() {

    // Initialising a forward list
    forward_list<int> l = {10, 15, 20}, l1, l2;

    // Pushing elements into the list
    l.push_front(5);

    // Pushing elements into the list
    l.push_front(3);

    // Popping out elements from list
    l.pop_front();
    // Assigning values to the list
    l.assign({10, 20, 30, 10});

    // Assigning one list to another
    l.assign(l.begin(), l.end());

    // Removing elements from list
    l.remove(10);
    auto it = l1.begin();
    // forward_list<int> it : iterator l;
    // inserting a set of elements to the list
    auto it1 = l.insert_after(it, {2, 3, 5});

    // The function is similar to the insert()
    // function
    it = l.emplace_after(it, 40);

    // Removes an element from the forward_list
    it = l1.erase_after(it);

    l = {10, 20, 30};
    l2 = {5, 15};
    l1.merge(l2);

    // Operation:

    // Displaying the list
    for (auto it = l.begin(); it != l.end(); it++)
        cout << (*it) << " ";

    // Displaying the list
    for (int x : l)
        cout << x << " ";
    return 0;
}
