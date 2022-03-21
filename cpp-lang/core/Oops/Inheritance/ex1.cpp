#include <iostream>
using namespace std;

class Car {
   public:
    int noOfGear;
    string color;
	Car(int noOfGear, string color):noOfGear(noOfGear), color(color){}
    void printCarInfo() {
        cout << "noOfGear: "<< this->noOfGear <<endl << "color: "<< this->color<<endl ;
    }
};


class RaceCar: public Car {
    public:
   	int maxSpeed;
	RaceCar(int noOfGear, string color, int maxSpeed):Car(noOfGear,color) , maxSpeed(maxSpeed){}
    void printRaceCarInfo() {
        Car::printCarInfo();
        cout  <<"maxSpeed: "<< this->maxSpeed;
    }
};


int main() {
    int noOfGear, maxSpeed;
    string color;
    cin >> noOfGear >> color >> maxSpeed;
    RaceCar raceCar(noOfGear, color, maxSpeed);
    raceCar.printRaceCarInfo();
    return 0;
}