#include "Group.h"

Group::Group(string name) {
    groupName = name;
    students = nullptr;
    size = 0;
}

Group::~Group() {
    delete[] students;
}

void Group::addStudent(const Student& student) {
    Student* newArr = new Student[size + 1];
    for (int i = 0; i < size; ++i)
        newArr[i] = students[i];
    newArr[size] = student;

    delete[] students;
    students = newArr;
    ++size;
}

void Group::removeStudent(int index) {
    if (index < 0 || index >= size) return;

    Student* newArr = new Student[size - 1];
    for (int i = 0, j = 0; i < size; ++i)
        if (i != index)
            newArr[j++] = students[i];

    delete[] students;
    students = newArr;
    --size;
}

void Group::showStudents() const {
    cout << "\nGroup: " << groupName << endl;
    for (int i = 0; i < size; ++i) {
        cout << i << ". ";
        students[i].print();
    }
}

string Group::getGroupName() const {
    return groupName;
}

void Group::setGroupName(string name) {
    groupName = name;
}
