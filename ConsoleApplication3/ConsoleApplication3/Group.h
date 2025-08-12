#pragma once
#include "Student.h"

class Group {
private:
    string groupName;
    Student* students;
    int size;

public:
    Group(string name);
    ~Group();

    void addStudent(const Student& student);
    void removeStudent(int index);
    void showStudents() const;

    string getGroupName() const;
    void setGroupName(string name);
};
