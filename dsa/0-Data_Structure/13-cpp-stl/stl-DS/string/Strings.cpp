/*
1) Input Functions:

getline()	This function is used to store a stream of characters as entered by the user in the object memory.
push_back() :	This function is used to input a character at the end of the string.
pop_back()	: Introduced from C++11(for strings), this function is used to delete the last character from the string.

2) Capacity Functions:

capacity()	: This function is used to return the capacity of the string.
resize()	: This function is used to resize the string.
length()	: This function is used to return the length of the string.
shring_to_fit()	: This function is used to shrink the string to fit the actual size.

3) Iterator Functions:

begin()	: This function is used to return the beginning of the string.
end()	: This function is used to return the end of the string.
rbegin()	: TThis function returns a reverse iterator pointing at the end of the string.
rend()	: This function returns a reverse iterator pointing at the beginning of the string.

4) Manipulating Functions:
copy()	: This function is used to copy the string.
swap()    : This function is used to swap the string.
find()	: This function is used to find the first occurrence of the substring specified in arguments.
find_first_of()	: This function is used to find the first occurrence of any of the characters specified in arguments.
find_last_of()	: This function is used to find the last occurrence of any of the characters specified in arguments.
insert()	: This function is used to insert the string specified in arguments at the specified position.
clear()	: This function is used to clear the string.
empty()	: This function is used to check if the string is empty.

stoi() : The stoi() function takes a string as an argument and returns its value.
atoi() : The atoi() function takes a character array or string literal as an argument and returns its value.
strtol() : The strtol() function takes a string as an argument and returns its value.
to_string() : The to_string() function takes an integer as an argument and returns its value.



*/
#include <bits/stdc++.h>
using namespace std;

int main() {

    string str;
    getline(cin, str);
    str.push_back('s');
    str.pop_back();

    str.resize(13);
    cout << str.capacity() << endl;
    str.shrink_to_fit();
    cout << str.capacity() << endl;

    std::string::iterator it;
    std::string::reverse_iterator it1;
    for (it = str.begin(); it != str.end(); it++)
        cout << *it;
    cout << endl;

    // Declaring character array
    char ch[80];
    str.copy(ch, 13, 0);
    str.swap(str);

    str.clear();
    str.insert(8, "Geeks");

    return 0;
}