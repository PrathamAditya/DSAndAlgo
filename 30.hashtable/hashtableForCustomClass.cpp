#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Student
{
public:
    string firstname;
    string lastname;
    string rollno;

    Student(string f, string l, string no)
    {
        firstname = f;
        lastname = l;
        rollno = no;
    }

    bool operator==(const Student &s) const
    {
        return rollno == s.rollno ? true : false;
    }
};

class HashFun
{
public:
    size_t operator()(const Student &s)
    {
        return s.firstname.length() + s.firstname.length();
    }
};

int main()
{
    unordered_map<Student, int, HashFun> student_map;
    Student s1{"Prateek", "Narang", "010"};
    Student s2{"Rahul", "Kumar", "023"};
    Student s3{"Prateek", "Gupta", "030"};
    Student s4{"Rahul", "Kumar", "120"};

    // Adding marks
    student_map[s1] = 100;
    student_map[s2] = 120;
    student_map[s3] = 99;
    student_map[s4] = 120;

    // itratre over all
    for (auto it = student_map.begin(); it != student_map.end(); it++)
    {
        cout << (*it).first.firstname << " : " << (*it).first.rollno << endl;
    }
}