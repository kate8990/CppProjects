#include <iostream>
using namespace std;

class Overcoat {
public:
    string type;
    double price;

    Overcoat() { type = ""; price = 0; }
    Overcoat(string t, double p) { type = t; price = p; }

    bool operator==(Overcoat& other) { return type == other.type; }
    Overcoat& operator=(Overcoat& other) { type = other.type; price = other.price; return *this; }
    bool operator>(Overcoat& other) { return type == other.type && price > other.price; }
};

class Flat {
public:
    double area;
    double price;

    Flat() { area = 0; price = 0; }
    Flat(double a, double p) { area = a; price = p; }

    bool operator==(Flat& other) { return area == other.area; }
    Flat& operator=(Flat& other) { area = other.area; price = other.price; return *this; }
    bool operator>(Flat& other) { return price > other.price; }
};

int main() {
    Overcoat c1("Trench", 120), c2("Trench", 150);
    cout << "c1 == c2? " << (c1 == c2) << endl;
    cout << "c1 > c2? " << (c1 > c2) << endl;

    Flat f1(50, 50000), f2(50, 60000);
    cout << "f1 == f2? " << (f1 == f2) << endl;
    cout << "f1 > f2? " << (f1 > f2) << endl;

    return 0;
}
