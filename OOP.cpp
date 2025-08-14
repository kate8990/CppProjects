#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        int a = numerator, b = denominator;
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        numerator /= a;
        denominator /= a;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }

public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int n, int d) : numerator(n), denominator(d) {
        if (d == 0) {
            cout << "Denominator cannot be zero! Set to 1." << endl;
            denominator = 1;
        }
        simplify();
    }

    void input() {
        cout << "Enter numerator: ";
        cin >> numerator;
        cout << "Enter denominator: ";
        cin >> denominator;
        if (denominator == 0) {
            cout << "Denominator cannot be zero! Set to 1." << endl;
            denominator = 1;
        }
        simplify();
    }

    void print() const {
        cout << numerator << "/" << denominator << endl;
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }
};

int main() {
    Fraction a, b;
    cout << "Enter first fraction:\n";
    a.input();
    cout << "Enter second fraction:\n";
    b.input();

    cout << "Sum: ";
    (a + b).print();
    cout << "Difference: ";
    (a - b).print();
    cout << "Product: ";
    (a * b).print();
    cout << "Quotient: ";
    (a / b).print();

    return 0;
}
