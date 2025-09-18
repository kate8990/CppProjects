#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <Windows.h>

using namespace std;

long long toDecimal(const string& num, int base) {
    long long result = 0;
    int power = 0;

    for (int i = num.size() - 1; i >= 0; i--) {
        char c = toupper(num[i]);
        int digit;
        if (isdigit(c)) digit = c - '0';
        else digit = c - 'A' + 10;

        if (digit >= base) {
            throw invalid_argument("Некоректне число для цієї системи!");
        }

        result += digit * pow(base, power);
        power++;
    }
    return result;
}

string fromDecimal(long long num, int base) {
    if (num == 0) return "0";

    string result;
    while (num > 0) {
        int digit = num % base;
        if (digit < 10) result += char('0' + digit);
        else result += char('A' + (digit - 10));
        num /= base;
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {

    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    setlocale(0, ""); 
    int fromChoice, toChoice;
    string number;

    cout << "Системи числення:\n";
    cout << "1 - Двійкова (2)\n";
    cout << "2 - Вісімкова (8)\n";
    cout << "3 - Десяткова (10)\n";
    cout << "4 - Шістнадцяткова (16)\n";

    cout << "\nОберіть з якої системи (1-4): ";
    cin >> fromChoice;
    cout << "Оберіть у яку систему (1-4): ";
    cin >> toChoice;

    cout << "Введіть число: " << endl;
    cin >> number;

    int bases[] = { 2, 8, 10, 16 };
    int fromBase = bases[fromChoice - 1];
    int toBase = bases[toChoice - 1];

    try {
        long long decimal = toDecimal(number, fromBase);
        string result = fromDecimal(decimal, toBase);
        cout << "Результат: " << result << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Помилка: " << e.what() << endl;
    }
}
