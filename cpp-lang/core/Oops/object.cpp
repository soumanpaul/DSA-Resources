#include<iostream>
using namespace std;

class Hero {
    int health;
    public:
    char level;
    static int timeToColplete;

    Hero() {
        cout << "Constructor..."<<endl;;
    }
    Hero(int health){
        cout << "P health"<<endl;
        this->health = health;
    }

    Hero(int health, char level) {
        this->health = health;
        this->level = level;
    }

    // copy constructor
    Hero(Hero& temp){
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;
        this->health = temp.health;
        this->level = temp.level;
    }
    ~Hero() {
        cout << "Destructor called...";
    }

    // static function 
    // only static menber can access
    static int random() {
        return timeToColplete;
    }

    void print() {
        cout << endl;
        cout << "Name: " << this->name << " , ";
        cout << "health: " << this->health << " ,"
        cout << "level: " << this->level << endl;
        cout << level << endl;

    }

    char getLevel() {
        return level;
    }
    int getHealth() {
        return health;
    }
    void setHealth (int h){
        health = h;
    }
    void setLevel(char ch){
        level = ch;
    }
    void setName(char name[]) {
        strcpy(this->name, name);
    }
};

int Hero::timeToColplete = 8;

int main() {

    cout << Hero::timeToColplete << endl;

    // Hero ramesh(2);

    // static allocation
    // Hero a;
    // a.setHealth(80);
    // a.setLevel('B');
    // cout << "level is...." << a.level << endl;
    // cout << "Health is..." << a.getHealth() << endl;

    // // dynamic
    // Hero *b = new Hero;
    // b->setLevel('A');
    // b->setHealth(70);
    // cout << "level is.." << (*b).level << endl;
    // cout << "health is " << (*b).getHealth() << endl; 

    // cout << "level is  " << b->level << endl;
    // cout << " health is " << b->getHealth() << endl;

    Hero s(70, 'C');
    s.print();

    Hero R(s);
    R.print();

    Hero hero1;
    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[7] = "Souman"
    hero1.setName(name)

    // hero1 = hero2

    // cout << "size : " << sizeof(ramesh) << endl;

    Hero z;



    return 0;
}