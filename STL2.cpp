#include <iostream>
#include <string>
#include <vector>
#include <windows.h>  // для роботи з консоллю

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
        cout << "Студент: " << name << "\nОцінки: ";
        if (grades.empty()) {
            cout << "немає";
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
                cout << "Студента \"" << name << "\" видалено.\n";
                return;
            }
        }
        cout << "Студента \"" << name << "\" не знайдено.\n";
    }

    void printGroup() const {
        cout << "Інформація про групу: " << (groupName.empty() ? "Не створена" : groupName) << "\n";
        if (students.empty()) {
            cout << "Студенти відсутні.\n";
        }
        else {
            for (const auto& s : students) {
                s.printInfo();
            }
        }
    }
};

int main() {
    // Кодування консолі для українських символів
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Колір консолі
    system("color 0A"); // чорний фон, зелений текст

    Group group;
    int choice;
    const int maxGrades = 5;

    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Створити групу\n";
        cout << "2. Додати студента\n";
        cout << "3. Видалити студента\n";
        cout << "4. Показати інформацію про групу\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;
        cin.ignore(); // очищуємо буфер після вводу числа

        if (choice == 1) {
            string name;
            cout << "Введіть назву групи: ";
            getline(cin, name);
            group.setName(name);
            cout << "Групу створено!\n";
        }
        else if (choice == 2) {
            string name;
            cout << "Введіть ім'я студента: ";
            getline(cin, name);

            Student s(name);
            int grade;
            cout << "Введіть оцінки (максимум " << maxGrades << "):\n";
            for (int i = 0; i < maxGrades; ++i) {
                cout << "Оцінка " << (i + 1) << ": ";
                cin >> grade;
                if (grade == 0) break;
                s.addGrade(grade);
            }
            cin.ignore(); // очищаємо буфер після оцінок
            group.addStudent(s);
            cout << "Студента додано!\n";
        }
        else if (choice == 3) {
            string name;
            cout << "Введіть ім'я студента для видалення: ";
            getline(cin, name);
            group.removeStudent(name);
        }
        else if (choice == 4) {
            group.printGroup();
        }
        else if (choice != 0) {
            cout << "Невірний вибір, спробуйте ще раз.\n";
        }
    } while (choice != 0);

    return 0;
}
