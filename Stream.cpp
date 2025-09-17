#include <iostream>
#include <fstream>
#include <random>
#include <Windows.h>

using namespace std;

class Matrix {
private:
    int rows, cols;
    int** data;

    void allocate() {
        data = new int* [rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

public:
    Matrix(int r = 0, int c = 0, bool randomFill = true) : rows(r), cols(c) {
        if (rows > 0 && cols > 0) {
            allocate();
            if (randomFill) {
                random_device rd;
                mt19937 gen(rd());
                uniform_int_distribution<> dist(1, 9);
                for (int i = 0; i < rows; i++)
                    for (int j = 0; j < cols; j++)
                        data[i][j] = dist(gen);
            }
        }
        else {
            data = nullptr;
        }
    }

    ~Matrix() {
        if (data) {
            for (int i = 0; i < rows; i++) {
                delete[] data[i];
            }
            delete[] data;
        }
    }

    friend istream& operator>>(istream& in, Matrix& m) {
        cout << "¬вед≥ть к≥льк≥сть р€дк≥в: ";
        in >> m.rows;
        cout << "¬вед≥ть к≥льк≥сть стовпц≥в: ";
        in >> m.cols;

        if (m.data) {
            for (int i = 0; i < m.rows; i++) delete[] m.data[i];
            delete[] m.data;
        }

        m.allocate();

        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 9);
        for (int i = 0; i < m.rows; i++)
            for (int j = 0; j < m.cols; j++)
                m.data[i][j] = dist(gen);

        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        out << "cols: " << m.cols << " rows: " << m.rows << "\n";
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                out << m.data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

    friend ifstream& operator>>(ifstream& fin, Matrix& m) {
        string tmp;
        fin >> tmp >> m.cols >> tmp >> m.rows;

        if (m.data) {
            for (int i = 0; i < m.rows; i++) delete[] m.data[i];
            delete[] m.data;
        }

        m.allocate();
        for (int i = 0; i < m.rows; i++)
            for (int j = 0; j < m.cols; j++)
                fin >> m.data[i][j];
        return fin;
    }

    friend ofstream& operator<<(ofstream& fout, const Matrix& m) {
        fout << "cols: " << m.cols << " rows: " << m.rows << "\n";
        for (int i = 0; i < m.rows; i++) {
            for (int j = 0; j < m.cols; j++) {
                fout << m.data[i][j] << " ";
            }
            fout << "\n";
        }
        return fout;
    }
};

int main() {

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    Matrix m1;

    cin >> m1;         
    cout << m1;        

    ofstream fout("matrix.txt");
    fout << m1;             
    fout.close();

    Matrix m2;
    ifstream fin("matrix.txt");
    fin >> m2;           
    fin.close();

    cout << "ћатриц€ з файлу:\n" << m2;
}
