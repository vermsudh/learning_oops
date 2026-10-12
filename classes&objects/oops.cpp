#include<iostream>
#include<string>
using namespace std;

class Teacher{

private: 
    double salary;

public:
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

};

class Student{
public:
    string name;
};
 
int main()
{
    Teacher t1;
    Teacher t2;
    Teacher t3;

    t1.name = "Sudhanshu";
    t1.subject = "c++";
    t1.dept = "IT";
    t1.setSalary(25000);

    cout << t1.name << endl;
    cout << t1.getSalary();

    return 0;
}