#include <iostream>
#include <memory>
#include <Windows.h>

using namespace std;

class DoubleLinkedList {
private:
    struct Node {
        int value;
        shared_ptr<Node> next;   
        weak_ptr<Node> prev;     

        Node(int v) : value(v) {}
    };

    shared_ptr<Node> head; 
    shared_ptr<Node> tail; 

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(int value) {
        auto newNode = make_shared<Node>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_front(int value) {
        auto newNode = make_shared<Node>(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void pop_back() {
        if (!tail) return;
        tail = tail->prev.lock();
        if (tail) {
            tail->next.reset();
        }
        else {
            head.reset();
        }
    }

    void pop_front() {
        if (!head) return;
        head = head->next;
        if (head) {
            head->prev.reset();
        }
        else {
            tail.reset();
        }
    }

    void print_forward() const {
        auto cur = head;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
        cout << "\n";
    }

    void print_backward() const {
        auto cur = tail;
        while (cur) {
            cout << cur->value << " ";
            cur = cur->prev.lock();
        }
        cout << "\n";
    }
};

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

    DoubleLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    list.push_front(5);

    cout << "Прямий обхід: ";
    list.print_forward();

    cout << "Зворотний обхід: ";
    list.print_backward();

    list.pop_front();
    list.pop_back();

    cout << "Після видалення:\n";
    list.print_forward();
}
