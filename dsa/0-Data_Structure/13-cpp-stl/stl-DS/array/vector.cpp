// template < class T, class Alloc = allocator<T> > class vector;

/*
Iterators:

begin             -Return iterator to beginning (public member function )
end               -Return iterator to end (public member function )
rbegin            -Return reverse iterator to reverse beginning (public member function )
rend              -Return reverse iterator to reverse end (public member function )
cbegin            -Return const_iterator to beginning (public member function )
cend              -Return const_iterator to end (public member function )
crbegin           -Return const_reverse_iterator to reverse beginning (public member function )
crend             -Return const_reverse_iterator to reverse end (public member function )


Capacity:

size            -Return size (public member function )
max_size        -Return maximum size (public member function )
resize          -Change size (public member function )
capacity        -Return size of allocated storage capacity (public member function )
empty           -Test whether vector is empty (public member function )
reserve         -Request a change in capacity (public member function )
shrink_to_fit   -Shrink to fit (public member function )


Element access:

operator[]       -Access element (public member function )
at               -Access element (public member function )
front            -Access first element (public member function )
back             -Access last element (public member function )
data             -Access data (public member function )

Modifiers:

assign           -Assign vector content (public member function )
push_back        -Add element at the end (public member function )
pop_back         -Delete last element (public member function )
insert           -Insert elements (public member function )
erase            -Erase elements (public member function )
swap             -Swap content (public member function )
clear            -Clear content (public member function )
emplace          -Construct and insert element (public member function )
emplace_back     -Construct and insert element at the end (public member function )

Overloads

relational operators           -Relational operators for vector (function template )
swap                           -Exchange contents of vectors (function template )


Algorithms:




*/

#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> v;
    vector<int> v1(5, 1);
    vector<int> vect1{10, 20, 30};
    vector<int> v1(5);
    vector<int> vect2(vect1.begin(), vect1.end());
    fill(vect1.begin(), vect1.end(), 20);

    for (int i = 1; i <= 5; i++)
        v.push_back(i);

    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << " ";

    v.size();
    v.empty();
    v.emplace(v.begin(), 5); // inserts at the beginning
    v.emplace_back(20);      // Inserts 20 at the end
    v.clear();
    v.size();

    return 0;
}
