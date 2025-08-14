#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
public:
    Student() : name(""), age(0) {}
    Student(string n, int a) : name(n), age(a) {}
    void print() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    string getName() { return name; }
    int getAge() { return age; }
};

class Group {
private:
    string groupName;
    Student* students;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        Student* temp = new Student[capacity];
        for (int i = 0; i < count; i++) temp[i] = students[i];
        delete[] students;
        students = temp;
    }

public:
    Group(string name = "Unnamed", int cap = 2) {
        groupName = name;
        capacity = cap;
        count = 0;
        students = new Student[capacity];
    }

    ~Group() {
        delete[] students;
    }

    void addStudent(const Student& s) {
        if (count >= capacity) resize();
        students[count] = s;
        count++;
    }

    void removeStudent(int index) {
        if (index < 0 || index >= count) return;
        for (int i = index; i < count - 1; i++) {
            students[i] = students[i + 1];
        }
        count--;
    }

    void printStudents() {
        cout << "Group: " << groupName << endl;
        for (int i = 0; i < count; i++) {
            cout << i + 1 << ". ";
            students[i].print();
        }
    }

    void setGroupName(string name) { groupName = name; }
    string getGroupName() { return groupName; }
    int getCount() { return count; }
};

int main() {
    Group* group = nullptr;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create group\n";
        cout << "2. Add student\n";
        cout << "3. Remove student\n";
        cout << "4. Show students\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            string name;
            cout << "Enter group name: ";
            cin >> name;
            if (group) delete group;
            group = new Group(name);
        }
        else if (choice == 2 && group) {
            string name;
            int age;
            cout << "Enter student name: ";
            cin >> name;
            cout << "Enter student age: ";
            cin >> age;
            group->addStudent(Student(name, age));
        }
        else if (choice == 3 && group) {
            int index;
            cout << "Enter student number to remove: ";
            cin >> index;
            group->removeStudent(index - 1);
        }
        else if (choice == 4 && group) {
            group->printStudents();
        }
    } while (choice != 0);

    if (group) delete group;
    return 0;
}
