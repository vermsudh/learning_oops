#include<iostream>
#include<vector>
using namespace std;
 
class Student{
public: 

    string name;

    Student(){
        cout << "non-parameterized constructor \n";
    }
    Student(string name){
        this-> name = name;
        cout << "parameterized constructor\n";
    }
};

int main()
{
    Student s2("Tony Stark");
    Student s1;
    s1.name = "TOny Stark";

    return 0;
}