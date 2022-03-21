class Animal {
    public:
        void eat() {
            cout << "Eating...." << end;
        }
};

class Dog {
    public: void bark(){
        cout << "Bark..";
    } 
};

class BabyDog: public Animal, public Dog {
    public:
        void weep(){
            cout << "Weeping";
        }
}

