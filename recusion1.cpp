#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
//1

// --- ініціалізація ---
void InitMatrix(int a[10][10], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 100;
}
void InitMatrix(double a[10][10], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 100 / 10.0;
}
void InitMatrix(char a[10][10], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 'A' + rand() % 26;
}

// --- вивід ---
void PrintMatrix(int a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void PrintMatrix(double a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
void PrintMatrix(char a[10][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// --- мін/макс на діагоналі ---
void MinMaxDiagonal(int a[10][10], int n) {
    int mn = a[0][0], mx = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] < mn) mn = a[i][i];
        if (a[i][i] > mx) mx = a[i][i];
    }
    cout << "min=" << mn << " max=" << mx << endl;
}
void MinMaxDiagonal(double a[10][10], int n) {
    double mn = a[0][0], mx = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] < mn) mn = a[i][i];
        if (a[i][i] > mx) mx = a[i][i];
    }
    cout << "min=" << mn << " max=" << mx << endl;
}
void MinMaxDiagonal(char a[10][10], int n) {
    char mn = a[0][0], mx = a[0][0];
    for (int i = 0; i < n; i++) {
        if (a[i][i] < mn) mn = a[i][i];
        if (a[i][i] > mx) mx = a[i][i];
    }
    cout << "min=" << mn << " max=" << mx << endl;
}

// --- сортування рядків ---
void SortRows(int a[10][10], int n) {
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + n);
}
void SortRows(double a[10][10], int n) {
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + n);
}
void SortRows(char a[10][10], int n) {
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + n);
}


//2
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
//3

string makeSecret() {
    string s = "";
    bool used[10] = { 0 };
    srand(time(0));
    while (s.size() < 4) {
        int d = rand() % 10;
        if (s.empty() && d == 0) continue;
        if (!used[d]) {
            s += char('0' + d);
            used[d] = 1;
        }
    }
    return s;
}

int play(string secret, int step = 1) {
    string g;
    cout << "try " << step << ": ";
    cin >> g;
    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; i++) {
        if (g[i] == secret[i]) bulls++;
        else if (secret.find(g[i]) != string::npos) cows++;
    }
    cout << "bulls=" << bulls << " cows=" << cows << endl;
    if (bulls == 4) {
        cout << "win in " << step << " steps" << endl;
        return step;
    }
    return play(secret, step + 1);
}

int main() {
    //1
    int n = 4;
    int a[10][10];
    InitMatrix(a, n);
    PrintMatrix(a, n);
    MinMaxDiagonal(a, n);
    SortRows(a, n);
    PrintMatrix(a, n);

    //2
    int x, y;
    cin >> x >> y;
    cout << "gcd=" << gcd(x, y) << endl;
    return 0;

    //3
    string secret = makeSecret();
    play(secret);
}
