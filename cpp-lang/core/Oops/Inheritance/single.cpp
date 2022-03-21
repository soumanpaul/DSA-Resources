#include<bits/stdc++.h>
using namespace std;

class Animal {
    public: 
        void eat() {
            cout << "eating..." <<endl;
        }
};

class Dog: public Animal {
    public: void bark() {
        cout << "barking..";
    }
};

int main () {
    Dog obj;
    obj.eat();
    obj.bark();
    return 0;
}