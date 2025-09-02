#include <iostream>
#include <Windows.h>

using namespace std;
//1
//template <typename T>
//void PrintTypeName(const T& value) {
//    cout << "Тип: " << typeid(value).name() << endl;
//}

//2
void IntToChar(int x) {
    char c = reinterpret_cast<char&>(x);
    cout << "Символ: " << c << endl;
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
//
    //int a = 42;
    //double b = 3.14;
    //char c = 'Z';

    //PrintTypeName(a);
    //PrintTypeName(b);
    //PrintTypeName(c);

    //2
    //IntToChar(65); 
    //IntToChar(66); 

}
