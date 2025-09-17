#include <iostream>
#include <string>
#include <vector>
#include <windows.h>  // ��� ������ � ��������

using namespace std;

class Student {
private:
    string name;
    vector<int> grades;

public:
    Student(const string& name = "") : name(name) {}

    void addGrade(int grade) {
        grades.push_back(grade);
    }

    string getName() const {
        return name;
    }

    void printInfo() const {
        cout << "�������: " << name << "\n������: ";
        if (grades.empty()) {
            cout << "����";
        }
        else {
            for (int g : grades) cout << g << " ";
        }
        cout << "\n";
    }
};

class Group {
private:
    string groupName;
    vector<Student> students;

public:
    Group(const string& name = "") : groupName(name) {}

    void setName(const string& name) {
        groupName = name;
    }

    string getName() const {
        return groupName;
    }

    void addStudent(const Student& s) {
        students.push_back(s);
    }

    void removeStudent(const string& name) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->getName() == name) {
                students.erase(it);
                cout << "�������� \"" << name << "\" ��������.\n";
                return;
            }
        }
        cout << "�������� \"" << name << "\" �� ��������.\n";
    }

    void printGroup() const {
        cout << "���������� ��� �����: " << (groupName.empty() ? "�� ��������" : groupName) << "\n";
        if (students.empty()) {
            cout << "�������� ������.\n";
        }
        else {
            for (const auto& s : students) {
                s.printInfo();
            }
        }
    }
};

int main() {
    // ��������� ������ ��� ���������� �������
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // ���� ������
    system("color 0A"); // ������ ���, ������� �����

    Group group;
    int choice;
    const int maxGrades = 5;

    do {
        cout << "\n--- ���� ---\n";
        cout << "1. �������� �����\n";
        cout << "2. ������ ��������\n";
        cout << "3. �������� ��������\n";
        cout << "4. �������� ���������� ��� �����\n";
        cout << "0. �����\n";
        cout << "��� ����: ";
        cin >> choice;
        cin.ignore(); // ������� ����� ���� ����� �����

        if (choice == 1) {
            string name;
            cout << "������ ����� �����: ";
            getline(cin, name);
            group.setName(name);
            cout << "����� ��������!\n";
        }
        else if (choice == 2) {
            string name;
            cout << "������ ��'� ��������: ";
            getline(cin, name);

            Student s(name);
            int grade;
            cout << "������ ������ (�������� " << maxGrades << "):\n";
            for (int i = 0; i < maxGrades; ++i) {
                cout << "������ " << (i + 1) << ": ";
                cin >> grade;
                if (grade == 0) break;
                s.addGrade(grade);
            }
            cin.ignore(); // ������� ����� ���� ������
            group.addStudent(s);
            cout << "�������� ������!\n";
        }
        else if (choice == 3) {
            string name;
            cout << "������ ��'� �������� ��� ���������: ";
            getline(cin, name);
            group.removeStudent(name);
        }
        else if (choice == 4) {
            group.printGroup();
        }
        else if (choice != 0) {
            cout << "������� ����, ��������� �� ���.\n";
        }
    } while (choice != 0);

    return 0;
}
