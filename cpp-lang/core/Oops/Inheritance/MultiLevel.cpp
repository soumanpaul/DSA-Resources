#include<iostream>
using namespace std;
class Animal {
    public:
    void eat(){
        cout << "Eating...";
    }
};

class Dog: public Animal {
    public:
    void bark() {
        cout << "Barking";
    }
};

class BabyDog: public Dog {
    public:
    void weep() {
        cout << "Weeping";
    }
};

int main() {
    BabyDog obj;
    obj.eat();
    obj.bark();
    obj.weep();
}