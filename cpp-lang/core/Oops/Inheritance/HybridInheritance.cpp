// Parent class1
class Vehicle {
    public:
        Vehicle() {
            cout << "This is a Vehicle" << endl;
        }
};
//Parent class2 
class Fare {
    public:
        Fare() {
            cout << "Fare of Vehicle\n";
        }
};
//Child class1
class Car: public Vehicle {
};
//Child class2 
class Bus: public Vehicle, public Fare {
};