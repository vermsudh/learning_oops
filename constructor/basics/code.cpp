#include<iostream>
#include<string>
using namespace std;

class Teacher{

private: 
    double salary;

public:
    //create a constructor.

    Teacher(){
        cout << "Hi, I am a constructor \n";
        dept = "Computer Science";
    }

    Teacher(string n, string d, string s, double sal){
        name = n;
        dept = d;
        subject = s;
        salary = sal;

    }//parameterized constructor
    //properties  or attributes
    string name;
    string dept;
    string subject;

    
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

    t1.name = "Sudhanshu";
    t1.subject = "c++";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary() << endl;

    cout << t1.dept << endl;

    return 0;
}