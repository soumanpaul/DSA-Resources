#include <cstring>
#include <iostream>
using namespace std;

/*
Memset() is a C++ function. It copies a single character for a specified number of times to an object
memcpy() is used to copy a block of memory from a location to another
memmove() is used to copy a block of memory from a location to another handle string overlap.
*/

char str[] = "geeksforgeeks";
// value 0 or 1, string all
memset(str, 't', sizeof(str));

string str1, str2;

/* Copies contents of str2 to str1 */
memcpy(str1, str2, sizeof(str2));

/* Copies contents of str2 to sr1 handle when strings overlap.  */
memmove(str1, str2, sizeof(str2));