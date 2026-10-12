#include<iostream>
#include<vector>
using namespace std;

class Student{
public:
    string name;
    double *cgpaPtr;

    Student(string name, double cgpa){
        this-> name = name;
        cgpaPtr = new double;
        *cgpaPtr = cgpa;
    }
    Student(Student &obj){
        cout << "From the copy constuctor"  << endl;
        this-> name = obj.name; 
        this-> cgpaPtr = obj.cgpaPtr;
    }

    //hard copy constrcutor
    Student(Student &obj){
        this-> name = obj.name; 
        cgpaPtr = new double;
        *cgpaPtr = *obj.cgpaPtr;
    }

    void getInfo(){
        cout << " name : " << name << endl;
        cout << " age : " << *cgpaPtr << endl;
    }

};
 
int main()
{

    Student s1("Sudhanshu Verma", 8.8);

    Student s2(s1);// Now, lets suppose, we have to change the name of the student.  If we use shallow copy. 
    // it will copy all the variable values


    s2.getInfo();
    *(s2.cgpaPtr) = 9.2;
    s1.getInfo();

    s2.name = "neha";
    s2.getInfo();

    
    return 0;
}