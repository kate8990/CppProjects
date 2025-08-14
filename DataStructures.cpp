#include <iostream>
using namespace std;

class DoublyLinkedList {
private:
    class Node {
    public:
        int value;
        Node* prev;
        Node* next;
        Node(int val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int count; 

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), count(0) {}

    ~DoublyLinkedList() {
        clear();
    }

    void push_front(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        count++;
    }

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        count++;
    }

    void pop_front() {
        if (!head) return;
        Node* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        count--;
    }

    void pop_back() {
        if (!tail) return;
        Node* temp = tail;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        count--;
    }

    void insert(int position, int value) {
        if (position < 0 || position > count) return;
        if (position == 0) {
            push_front(value);
            return;
        }
        if (position == count) {
            push_back(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        newNode->prev = curr->prev;
        newNode->next = curr;
        curr->prev->next = newNode;
        curr->prev = newNode;
        count++;
    }

    void erase(int position) {
        if (position < 0 || position >= count) return;
        if (position == 0) {
            pop_front();
            return;
        }
        if (position == count - 1) {
            pop_back();
            return;
        }

        Node* curr = head;
        for (int i = 0; i < position; i++) {
            curr = curr->next;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr;
        count--;
    }

    int find(int value) {
        Node* curr = head;
        int index = 0;
        while (curr) {
            if (curr->value == value) return index;
            curr = curr->next;
            index++;
        }
        return -1;
    }

    void clear() {
        while (head) {
            pop_front();
        }
    }

    int size() const {
        return count;
    }

    bool empty() const {
        return count == 0;
    }

    void print_forward() const {
        Node* curr = head;
        while (curr) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void print_backward() const {
        Node* curr = tail;
        while (curr) {
            cout << curr->value << " ";
            curr = curr->prev;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.push_back(10);
    list.push_back(20);
    list.push_front(5);
    list.insert(1, 15);

    cout << "Forward: ";
    list.print_forward();

    cout << "Backward: ";
    list.print_backward();

    cout << "Size: " << list.size() << endl;
    cout << "Find 15: " << list.find(15) << endl;

    list.erase(1);
    list.pop_back();
    list.pop_front();

    cout << "After removals: ";
    list.print_forward();

    list.clear();
    cout << "Empty? " << (list.empty() ? "Yes" : "No") << endl;

    return 0;
}
