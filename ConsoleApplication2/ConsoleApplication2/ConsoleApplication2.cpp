#include <iostream>
#include <string>
using namespace std;

// ���� Overcoat
class Overcoat {
private:
    string type;
    double price;

public:
    Overcoat(string type = "", double price = 0.0) {
        this->type = type;
        this->price = price;
    }

    // �������� ==
    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    // �������� =
    Overcoat& operator=(const Overcoat& other) {
        if (this != &other) {
            this->type = other.type;
            this->price = other.price;
        }
        return *this;
    }

    // �������� >
    bool operator>(const Overcoat& other) const {
        if (*this == other)
            return this->price > other.price;
        else
            return false;
    }

    void Print() const {
        cout << "���: " << type << ", ֳ��: " << price << " ���" << endl;
    }
};

// ���� Flat
class Flat {
private:
    double area;
    double price;

public:
    Flat(double area = 0.0, double price = 0.0) {
        this->area = area;
        this->price = price;
    }

    // �������� ==
    bool operator==(const Flat& other) const {
        return this->area == other.area;
    }

    // �������� =
    Flat& operator=(const Flat& other) {
        if (this != &other) {
            this->area = other.area;
            this->price = other.price;
        }
        return *this;
    }

    // �������� >
    bool operator>(const Flat& other) const {
        return this->price > other.price;
    }

    void Print() const {
        cout << "�����: " << area << " �?, ֳ��: " << price << " ���" << endl;
    }
};

int main() {
    // Overcoat
    Overcoat coat1("������", 2000);
    Overcoat coat2("������", 2500);
    Overcoat coat3("������", 1500);

    if (coat1 == coat2)
        cout << "coat1 � coat2 ������ ����." << endl;

    if (coat2 > coat1)
        cout << "coat2 ������� �� coat1." << endl;

    coat3 = coat1;
    cout << "coat3 ���� ��������� coat1: ";
    coat3.Print();

    cout << endl;

    // Flat
    Flat flat1(60.0, 50000);
    Flat flat2(60.0, 55000);
    Flat flat3(80.0, 70000);

    if (flat1 == flat2)
        cout << "flat1 � flat2 ����� �������� �����." << endl;

    if (flat3 > flat2)
        cout << "flat3 ������� �� flat2." << endl;

    flat2 = flat3;
    cout << "flat2 ���� ��������� flat3: ";
    flat2.Print();

    return 0;
}
