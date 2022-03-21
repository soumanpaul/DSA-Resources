#include<iostream>
using namespace std;

class Student {
    private: 
    string studentName;
    int rollNo;
    int Age;

    public:
        string getName() {
            return studentName;
        }
        void setStudentName(string name) {
           this -> studentName = name;
        }
         void setStudentRollno(int studentRollno) {
        this -> studentRollno = studentRollno;
    }
    
    int getStudentAge() {
        return studentAge;
    }
    void setStudentAge(int studentAge) {
        this -> studentAge = studentAge;
    }
};
int main() {
    Student obj;
    // setting the values of the variables
    obj.setStudentName("Rahul");
    obj.setStudentRollno(101);
    obj.setStudentAge(22);
    // printing the values of the variables
    cout << "Student Name : " << obj.getStudentName() << endl;
    cout << "Student Rollno : " << obj.getStudentRollno() << endl;
    cout << "Student Age : " << obj.getStudentAge();
}