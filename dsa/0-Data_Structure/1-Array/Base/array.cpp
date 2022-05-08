#include <bits/stdc++.h>
using namespace std;

int arr1[10];
int const n = 10;
int arr2[n];
int arr[] = {10, 20, 30, 40};

// Array declaration by specifying size and initializing
// elements
int arr[6] = {10, 20, 30, 40};

/*
Syntax to use new operator: To allocate memory of any data type, the syntax is:
pointer-variable = new data-type;

// Pointer initialized with NULL
// Then request memory for the variable
int *p = NULL;
p = new int;
            OR
// Combine declaration of pointer
// and their assignment
int *p = new int
*/

int *p = new int(25);
float *q = new float(75.25);

// Custom data type
struct cust {
    int p;
    cust(int q) : p(q) {}
};

cust *var1 = new cust(2);
// or cust* var1 = new cust();
// or cust* var = new cust(25)

// Allocate block of memory: new operator is also used to
// allocate a block(an array) of memory of type data-type.
// pointer-variable = new data-type[size];

// delete operator

// Since it is programmer’s responsibility to deallocate dynamically allocated memory, programmers are provided delete operator by C++ language.
// Syntax:

// Release memory pointed by pointer-variable
// delete pointer-variable;

// delete p;
// delete q;
