#include <iostream>
#include <Windows.h> 

using namespace std;

class Figure {
public:
    virtual double GetArea() = 0;
    virtual ~Figure() {}
};

class MyRectangle : public Figure {
    double width, height;
public:
    MyRectangle(double w, double h) {
        width = w;
        height = h;
    }
    double GetArea() {
        return width * height;
    }
};

class Circle : public Figure {
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double GetArea() {
        return 3.14 * radius * radius;
    }
};

class Triangle : public Figure {
    double base, height;
public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }
    double GetArea() {
        return 0.5 * base * height;
    }
};

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int choice;
    Figure* f = nullptr;

    cout << "ваша фігура:\n";
    cout << "1. прямокутник\n";
    cout << "2. коло\n";
    cout << "3. трикутник\n";
    cin >> choice;

    if (choice == 1) {
        double w, h;
        cout << "ваша ширина: ";
        cin >> w;
        cout << "ваша висота: ";
        cin >> h;
        f = new MyRectangle(w, h);
    }
    else if (choice == 2) {
        double r;
        cout << "ваш радіус: ";
        cin >> r;
        f = new Circle(r);
    }
    else if (choice == 3) {
        double b, h;
        cout << "ваша основа: ";
        cin >> b;
        cout << "ваша висота: ";
        cin >> h;
        f = new Triangle(b, h);
    }
    else {
        cout << "помилка\n";
    }

    if (f != nullptr) {
        cout << "площа: " << f->GetArea() << endl;
        delete f;
    }

    return 0;
}
