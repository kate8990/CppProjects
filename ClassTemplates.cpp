#include <iostream>
using namespace std;

template <typename T>
class Array {
private:
    T* data;
    int size; 
    int count;
    int grow;

public:
    Array(int s = 0, int g = 1) {
        size = s;
        grow = g;
        count = 0;
        if (size > 0) data = new T[size];
        else data = NULL;
    }

    ~Array() {
        if (data) delete[] data;
    }

    int GetSize() { return size; }

    void SetSize(int newSize, int newGrow = -1) {
        if (newGrow > 0) grow = newGrow;
        T* newData = new T[newSize];
        int m = (newSize < count) ? newSize : count;
        for (int i = 0; i < m; i++) {
            newData[i] = data[i];
        }
        if (data) delete[] data;
        data = newData;
        size = newSize;
        if (count > size) count = size;
    }

    int GetUpperBound() { return count - 1; }

    bool IsEmpty() { return count == 0; }

    void FreeExtra() {
        if (count < size) SetSize(count);
    }

    void RemoveAll() { count = 0; }

    T GetAt(int index) { return data[index]; }

    void SetAt(int index, T value) { data[index] = value; }

    T& operator[](int index) { return data[index]; }

    void Add(T value) {
        if (count >= size) {
            SetSize(size + grow);
        }
        data[count] = value;
        count++;
    }

    void Append(Array& other) {
        for (int i = 0; i <= other.GetUpperBound(); i++) {
            Add(other[i]);
        }
    }

    T* GetData() { return data; }

    void InsertAt(int index, T value, int num = 1) {
        while (count + num > size) {
            SetSize(size + grow);
        }
        for (int i = count - 1; i >= index; i--) {
            data[i + num] = data[i];
        }
        for (int i = 0; i < num; i++) {
            data[index + i] = value;
        }
        count += num;
    }

    void RemoveAt(int index, int num = 1) {
        for (int i = index; i < count - num; i++) {
            data[i] = data[i + num];
        }
        count -= num;
    }
};

// пример
int main() {
    Array<int> arr(2, 2);

    arr.Add(10);
    arr.Add(20);
    arr.Add(30);

    arr.InsertAt(1, 99);

    for (int i = 0; i <= arr.GetUpperBound(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.RemoveAt(2);

    for (int i = 0; i <= arr.GetUpperBound(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
