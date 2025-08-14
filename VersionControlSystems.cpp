#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int age;
    string group;
};

class Book {
public:
    string title;
    string author;
    int year;
};

class Firm {
public:
    string name;
    string address;
    int employees;
};

class Phone {
public:
    string brand;
    string model;
    double price;
};

class Car {
public:
    string brand;
    string model;
    int year;
    double price;
};

int main() {
    Student s;
    s.name = "Alice";
    s.age = 20;
    s.group = "1";

    Book b;
    b.title = "C++ Programming";
    b.author = "Bjarne Stroustrup";
    b.year = 2013;

    Firm f;
    f.name = "TechCorp";
    f.address = "123 Main St";
    f.employees = 50;

    Phone p;
    p.brand = "Samsung";
    p.model = "Galaxy S23";
    p.price = 799.99;

    Car c;
    c.brand = "Toyota";
    c.model = "Corolla";
    c.year = 2022;
    c.price = 20000;

    cout << "Student: " << s.name << ", Age: " << s.age << ", Group: " << s.group << endl;
    cout << "Book: " << b.title << ", Author: " << b.author << ", Year: " << b.year << endl;
    cout << "Firm: " << f.name << ", Address: " << f.address << ", Employees: " << f.employees << endl;
    cout << "Phone: " << p.brand << " " << p.model << ", Price: $" << p.price << endl;
    cout << "Car: " << c.brand << " " << c.model << ", Year: " << c.year << ", Price: $" << c.price << endl;

    return 0;
}

