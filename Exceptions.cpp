#include <iostream>
#include <string>
#include <stdexcept>
#include <Windows.h>

using namespace std;

//1
int toInt(const string& s) {
    try {
        size_t pos;
        int value = stoi(s, &pos);
        if (pos != s.size()) { 
            throw invalid_argument("Рядок містить недопустимі символи");
        }
        return value;
    }
    catch (const invalid_argument&) {
        throw invalid_argument("Це не число!");
    }
    catch (const out_of_range&) {
        throw invalid_argument("Число занадто велике/мале!");
    }
}
////2
//void process() {
//    try {
//        throw runtime_error("Помилка в програмі!");
//    }
//    catch (const exception& e) {
//        ofstream file("errors.log", ios::app);
//        file << e.what() << endl;
//        file.close();
//        throw; //
//    }
//}
////3
//void checkPassword(const string& password) {
//    if (password.size() < 8) {
//        throw invalid_argument("Пароль повинен містити щонайменше 8 символів!");
//    }
//    bool hasDigit = false;
//    for (char c : password) {
//        if (isdigit(c)) {
//            hasDigit = true;
//            break;
//        }
//    }
//    if (!hasDigit) {
//        throw invalid_argument("Пароль повинен містити хоча б одну цифру!");
//    }
//}
////4
//class AgeException : public exception {
//    int age;
//    string message;
//public:
//    AgeException(int a) : age(a) {
//        message = "Вік " + to_string(age) + " занадто малий для голосування!";
//    }
//    const char* what() const noexcept override {
//        return message.c_str();
//    }
//};
//
//void vote(const string& candidate, int age) {
//    if (age < 18) {
//        throw AgeException(age);
//    }
//    cout << "Ви проголосували за: " << candidate << endl;
//}

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    try {
        cout << toInt("123") << endl;
        cout << toInt("12a") << endl; 
    }
    catch (const exception& e) {
        cout << "Помилка: " << e.what() << endl;
    }

    //try {
    //    process();
    //}
    //catch (const exception& e) {
    //    cout << "Знову перехопили: " << e.what() << endl;
    //}

    //try {
    //    checkPassword("pass123");
    //}
    //catch (const exception& e) {
    //    cout << "Помилка пароля: " << e.what() << endl;
    //}

    //try {
    //    vote("Іваненко", 16);
    //}
    //catch (const AgeException& e) {
    //    cout << "Помилка голосування: " << e.what() << endl;
    //}
}
