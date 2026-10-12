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
   ~Student(){
    cout << "Hi, I am deleteing everything!";

    delete cgpaPtr; //memory leak
   }

    void getInfo(){
        cout << " name : " << name << endl;
        cout << " age : " << *cgpaPtr << endl;
    }

};
 
int main()
{

    Student s1("rahul kumar", 8.9);
    s1.getInfo();

    return 0;
}