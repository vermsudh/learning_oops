#include<iostream>
#include<string>
using namespace std;

class Person{
public : 
    string name;
    int age;

    Person(){
         cout << "THis is a Parent constructor \n" << endl;
    }
    ~Person(){
        cout << "THis is a Parent destructor \n" << endl;

    }
};

class Student : public Person{ // we are inheriting from Person class to use Person class properties
public:
    //name, age, rollno
    int rollNo;

    Student(){
        cout << "THis is a child constructor \n" << endl;
    }
    ~Student(){
        cout << "THis is a Child destructor \n" << endl;
    }

    void getInfo(){
        cout << "name : " << name << endl;
        cout << "Age : " << age << endl;
        cout << "RollNo : " << rollNo << endl;
    }

};

class GradStudent : public Student{
public: 
    string researchArea; 

};
 
int main()
{

    Student s1;

    s1.name = "Sudhanshu Verma";
    s1.age = 25;
    s1.rollNo = 14;

    s1.getInfo();

    GradStudent s2;
    s2.name = "Tony Stark";
    s2.researchArea ="quantam physics";
    s2.age = 23;

    s2.getInfo();

    return 0;
}