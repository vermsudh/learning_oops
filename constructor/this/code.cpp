#include<iostream>
#include<string>
using namespace std;

class Teacher{

private: 
    double salary;

public:
    //parameterized constructor
    //properties  or attributes
    string name;
    string dept;
    string subject;

    //create a constructor.

    Teacher(){
        cout << "Hi, I am a constructor \n";
        dept = "Computer Science";
    }

    Teacher(string name, string dept, string subject, double sal){
        this ->name = name;
        this -> dept = dept;
        this -> subject = subject;
        this -> salary = salary;
        //left is is object paramber and right is the constructor paramter

    }
    //methods
    void changeDept(string newDept){
        dept = newDept;
    }
    void setSalary(double s){
        salary = s;
    }
    double getSalary(){
        return salary;
    }

    void getInfo(){
        cout << "name : " << name << endl;
        cout << "subject : " << subject << endl;
    }

};

class Student{
public:
    string name;
};
 
int main()
{
    Teacher t1("sudhanshu", "computer science", "C++", 40000); //calling the default constructor. This calls automatically the contructor. It helps to initlize the objects.
    t1.getInfo();

    return 0;
}