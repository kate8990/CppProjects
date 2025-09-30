#include <iostream>
#include <string>
using namespace std;


//1
class Pet {
protected:
    string name;
    string characteristic;
public:
    Pet(string n, string c) {
        name = n;
        characteristic = c;
    }
    void show() {
        cout << "Name: " << name << ", Characteristic: " << characteristic << endl;
    }
};

class Dog : public Pet {
public:
    Dog(string n, string c) : Pet(n, c) {}
};

class Cat : public Pet {
public:
    Cat(string n, string c) : Pet(n, c) {}
};

class Parrot : public Pet {
public:
    Parrot(string n, string c) : Pet(n, c) {}
};

//2
#include <iostream>
#include <string>
using namespace std;

class Pet {
protected:
    string name;
    string characteristic;
public:
    Pet(string n, string c) {
        name = n;
        characteristic = c;
    }
    void show() {
        cout << "Name: " << name << ", Characteristic: " << characteristic << endl;
    }
};

class Dog : public Pet {
public:
    Dog(string n, string c) : Pet(n, c) {}
};

class Cat : public Pet {
public:
    Cat(string n, string c) : Pet(n, c) {}
};

class Parrot : public Pet {
public:
    Parrot(string n, string c) : Pet(n, c) {}
};

int main() {
    Dog d("Rex", "big and friendly");
    Cat c("Murka", "lazy and fluffy");
    Parrot p("Kesha", "talkative");

    d.show();
    c.show();
    p.show();

    return 0;
}


int main() {//1
    Dog d("Rex", "big and friendly");
    Cat c("Murka", "lazy and fluffy");
    Parrot p("Kesha", "talkative");

    d.show();
    c.show();
    p.show();

    //2
    MyString s1("Hello");
    MyString s2(" World");
    MyString s3 = s1 + s2;
    s3.print();

    BitString b1("1010");
    BitString b2("0011");
    b1.print();
    b2.print();
    b1.changeSign();
    b1.print();
}
