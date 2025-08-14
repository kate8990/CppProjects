#include <iostream>
using namespace std;

class MyString {
private:
    char* str;
    size_t length;

    size_t my_strlen(const char* s) const {
        size_t len = 0;
        while (s && s[len] != '\0') len++;
        return len;
    }

    void my_strcpy(char* dest, const char* src) const {
        size_t i = 0;
        while (src && src[i] != '\0') {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    void my_strcat(char* dest, const char* src) const {
        size_t i = 0;
        while (dest[i] != '\0') i++;
        size_t j = 0;
        while (src && src[j] != '\0') {
            dest[i] = src[j];
            i++;
            j++;
        }
        dest[i] = '\0';
    }

public:
    MyString() : str(nullptr), length(0) {}

    MyString(size_t size) {
        length = size;
        str = new char[length + 1];
        str[0] = '\0';
    }

    MyString(const char* s) {
        if (s) {
            length = my_strlen(s);
            str = new char[length + 1];
            my_strcpy(str, s);
        }
        else {
            str = nullptr;
            length = 0;
        }
    }

    MyString(const MyString& other) {
        length = other.length;
        if (other.str) {
            str = new char[length + 1];
            my_strcpy(str, other.str);
        }
        else {
            str = nullptr;
        }
    }

    MyString(MyString&& other) noexcept {
        str = other.str;
        length = other.length;
        other.str = nullptr;
        other.length = 0;
    }

    ~MyString() {
        delete[] str;
    }

    MyString& operator=(const MyString& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            if (other.str) {
                str = new char[length + 1];
                my_strcpy(str, other.str);
            }
            else {
                str = nullptr;
            }
        }
        return *this;
    }

    MyString& operator=(MyString&& other) noexcept {
        if (this != &other) {
            delete[] str;
            str = other.str;
            length = other.length;
            other.str = nullptr;
            other.length = 0;
        }
        return *this;
    }

    MyString operator+(const MyString& other) const {
        MyString temp;
        temp.length = length + other.length;
        temp.str = new char[temp.length + 1];
        my_strcpy(temp.str, str ? str : "");
        my_strcat(temp.str, other.str ? other.str : "");
        return temp;
    }

    char& operator[](size_t index) {
        return str[index];
    }

    const char& operator[](size_t index) const {
        return str[index];
    }

    size_t getLength() const {
        return length;
    }

    friend ostream& operator<<(ostream& os, const MyString& s) {
        if (s.str) os << s.str;
        return os;
    }

    friend istream& operator>>(istream& is, MyString& s) {
        char buffer[1024];
        is >> buffer;
        s = MyString(buffer);
        return is;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3 = s1 + MyString(" ") + s2;

    cout << "s3: " << s3 << endl;
    cout << "Length: " << s3.getLength() << endl;

    MyString s4 = move(s3);
    cout << "s4 (after move): " << s4 << endl;
    cout << "s3 (moved-from): " << s3 << endl;

    MyString s5;
    cout << "Enter string: ";
    cin >> s5;
    cout << "You entered: " << s5 << endl;

    s5[0] = 'X';
    cout << "Modified: " << s5 << endl;

    return 0;
}
