#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(1251);
//1
    //ifstream file1("file1.txt");
    //ifstream file2("file2.txt");

    //if (!file1.is_open() || !file2.is_open()) {
    //    cout << "�������" << endl;
    //    return 1;
    //}

    //string line1, line2;
    //int lineNumber = 1;
    //bool identical = true;

    //while (getline(file1, line1) && getline(file2, line2)) {
    //    if (line1 != line2) {
    //        cout << "����� " << lineNumber << " �����������:" << endl;
    //        cout << "���� 1: " << line1 << endl;
    //        cout << "���� 2: " << line2 << endl;
    //        identical = false;
    //    }
    //    lineNumber++;
    //}

    //while (getline(file1, line1)) {
    //    cout << "����� " << lineNumber << " (���� � ���� 1): " << line1 << endl;
    //    identical = false;
    //    lineNumber++;
    //}
    //while (getline(file2, line2)) {
    //    cout << "����� " << lineNumber << " (���� � ���� 2): " << line2 << endl;
    //    identical = false;
    //    lineNumber++;
    //}

    //if (identical)
    //    cout << "����� ��������!" << endl;

    //file1.close();
    //file2.close();
    //return 0;

//3
#include <iostream>
#include <cstdio>
    using namespace std;

    int main() {
        FILE* in = fopen("original.txt", "r");
        FILE* out = fopen("encrypted.txt", "w");

        if (!in || !out) {
            cout << "�������\n";
            return 1;
        }

        const char small[] = "��������賿��������������������";
        const char big[] = "���å�Ū��Ȳ���������������������";
        int sizeSmall = sizeof(small) - 1;
        int sizeBig = sizeof(big) - 1;
        int key = 3;

        int ch;
        while ((ch = fgetc(in)) != EOF) {
            int found = 0;
            for (int i = 0; i < sizeSmall; i++) {
                if (ch == small[i]) {
                    ch = small[(i + key) % sizeSmall];
                    found = 1;
                    break;
                }
            }
            if (!found) {
                for (int i = 0; i < sizeBig; i++) {
                    if (ch == big[i]) {
                        ch = big[(i + key) % sizeBig];
                        break;
                    }
                }
            }
            fputc(ch, out);
        }

        fclose(in);
        fclose(out);
        return 0;
    }

//�� ������ 2 ������� � �� ������

}
