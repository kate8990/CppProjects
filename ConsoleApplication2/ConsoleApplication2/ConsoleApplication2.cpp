#include <iostream>
#include <string>
using namespace std;

// Клас Overcoat
class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat(string type = "", double price = 0.0) {
        this->type = type;
        this->price = price;
    }

    // Оператор ==
    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    // Оператор =
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            this->type = other.type;
            this->price = other.price;
        }
        return *this;
    }

    // Оператор >
    bool operator>(const Overcoat& other) const {
        if (*this == other)
            return this->price > other.price;
        else
            return false;
    }

    void Print() const {
        cout << "Тип: " << type << ", Ціна: " << price << " грн" << endl;
    }
};

// Клас Flat
class Flat {
private:
    double area;
    double price;

public:
    Flat(double area = 0.0, double price = 0.0) {
        this->area = area;
        this->price = price;
    }

    // Оператор ==
    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    // Оператор =
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // Оператор >
    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    void Print() const {
        cout << "Площа: " << area << " м?, Ціна: " << price << " грн" << endl;
    }
};

int main() {
    // Overcoat
    Overcoat coat1("Пальто", 2000);
    Overcoat coat2("Пальто", 2500);
    Overcoat coat3("Куртка", 1500);

    if (coat1 == coat2)
        cout << "coat1 і coat2 одного типу." << endl;

    if (coat2 > coat1)
        cout << "coat2 дорожче за coat1." << endl;

    coat3 = coat1;
    cout << "coat3 після присвоєння coat1: ";
    coat3.Print();

    cout << endl;

    // Flat
    Flat flat1(60.0, 50000);
    Flat flat2(60.0, 55000);
    Flat flat3(80.0, 70000);

    if (flat1 == flat2)
        cout << "flat1 і flat2 мають однакову площу." << endl;

    if (flat3 > flat2)
        cout << "flat3 дорожча за flat2." << endl;

    flat2 = flat3;
    cout << "flat2 після присвоєння flat3: ";
    flat2.Print();

    return 0;
}
