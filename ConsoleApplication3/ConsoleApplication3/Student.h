#pragma once
#include <string>
#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int age;

public:
    Student();
    Student(string name, int age);

    void setName(string name);
    void setAge(int age);
    string getName() const;
    int getAge() const;
    void print() const;
};
