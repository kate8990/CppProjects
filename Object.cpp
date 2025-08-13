#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct Node {
    string number;
    string violations;
    Node* left, * right;
};

Node* createNode(string num, string viol) {
    Node* p = new Node;
    p->number = num;
    p->violations = viol;
    p->left = p->right = nullptr;
    return p;
}

Node* add(Node* root, string num, string viol) {
    if (!root) return createNode(num, viol);
    if (num < root->number) root->left = add(root->left, num, viol);
    else if (num > root->number) root->right = add(root->right, num, viol);
    else root->violations += "; " + viol; // додаємо до існуючих
    return root;
}

void printAll(Node* root) {
    if (!root) return;
    printAll(root->left);
    cout << root->number << " -> " << root->violations << "\n";
    printAll(root->right);
}

void printByNumber(Node* root, string num) {
    if (!root) return;
    if (num < root->number) printByNumber(root->left, num);
    else if (num > root->number) printByNumber(root->right, num);
    else cout << root->number << " -> " << root->violations << "\n";
}

void printByRange(Node* root, string from, string to) {
    if (!root) return;
    if (from < root->number) printByRange(root->left, from, to);
    if (root->number >= from && root->number <= to)
        cout << root->number << " -> " << root->violations << "\n";
    if (to > root->number) printByRange(root->right, from, to);
}

int main() {

    SetConsoleOutputCP(1251);

    Node* root = nullptr;
    root = add(root, "AA1234BB", "Перевищення швидкості");
    root = add(root, "BC5678DD", "Неправильне паркування");
    root = add(root, "AA1234BB", "Проїзд на червоне");
    root = add(root, "AB4321CC", "Відсутність страхування");

    cout << "=== Вся база ===\n";
    printAll(root);

    cout << "\n=== Пошук AA1234BB ===\n";
    printByNumber(root, "AA1234BB");

    cout << "\n=== Діапазон AA0000AA - BC9999ZZ ===\n";
    printByRange(root, "AA0000AA", "BC9999ZZ");
}
