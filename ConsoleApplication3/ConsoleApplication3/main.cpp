#include "Group.h"

int main() {
    Group* group = nullptr;
    int choice;

    do {
        cout << "\n1. Create group\n2. Add student\n3. Remove student\n4. Show students\n0. Exit\n> ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name;
            cout << "Enter group name: ";
            cin.ignore();
            getline(cin, name);
            delete group;
            group = new Group(name);
            break;
        }
        case 2: {
            if (!group) {
                cout << "Create a group first.\n";
                break;
            }
            string name;
            int age;
            cout << "Enter student name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter age: ";
            cin >> age;
            group->addStudent(Student(name, age));
            break;
        }
        case 3: {
            if (!group) {
                cout << "No group.\n";
                break;
            }
            int index;
            cout << "Enter index to remove: ";
            cin >> index;
            group->removeStudent(index);
            break;
        }
        case 4: {
            if (group)
                group->showStudents();
            else
                cout << "No group.\n";
            break;
        }
        }
    } while (choice != 0);

    delete group;
    return 0;
}
