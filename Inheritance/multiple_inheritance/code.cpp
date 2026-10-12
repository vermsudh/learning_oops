#include<iostream>
#include<vector>
using namespace std;

class Teacher{
public: 
    string name;
    int rollNo;
};

class  Student{
public: 
    string subject;
    double salary;
};

class TA : public Student, public Teacher{
public: 
    string researchArea;
};
 
int main()
{
    TA t1;
    t1.name = "Tony Stark";
    t1.rollNo = 23;
    t1.researchArea = "Physics";

    cout << t1.name << endl;
    cout << t1.researchArea << endl;

    return 0;
}