class Animal {
    public:
        void eat() {
            cout << "eating" << endl;
        }
};
// child class1
class Dog: public Animal {
    public: void bark() {
        cout << "barking" << endl;
    }
};
// child class2
class Cat: public Animal {
    public: void meow() {
        cout << "meowing" << endl;
    }
};