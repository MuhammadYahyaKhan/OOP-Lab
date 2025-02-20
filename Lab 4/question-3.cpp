#include <iostream>
using namespace std;

class DynamicArray {
    int* arr;
    int size;

public:
    // Default Constructor
    DynamicArray() {
        size = 0;
        arr = nullptr;
    }

    // Parameterized Constructor
    DynamicArray(int n) {
        size = n;
        arr = new int[size]{};
    }

    // Copy Constructor
    DynamicArray(const DynamicArray& obj) {
        size = obj.size;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = obj.arr[i];
        }
    }

    // Move Constructor
    DynamicArray(DynamicArray&& obj) noexcept {
        size = obj.size;
        arr = obj.arr;
        obj.arr = nullptr;
        obj.size = 0;
    }

    // Copy Assignment Operator
    DynamicArray& operator=(const DynamicArray& obj) {
        if (this != &obj) {
            delete[] arr;
            size = obj.size;
            arr = new int[size];
            for (int i = 0; i < size; i++) {
                arr[i] = obj.arr[i];
            }
        }
        return *this;
    }

    // Move Assignment Operator
    DynamicArray& operator=(DynamicArray&& obj) noexcept {
        if (this != &obj) {
            delete[] arr;
            size = obj.size;
            arr = obj.arr;
            obj.arr = nullptr;
            obj.size = 0;
        }
        return *this;
    }

    // Destructor
    ~DynamicArray() {
        delete[] arr;
    }

    // Get the size of the array
    int getSize() const {
        return size;
    }

    // Access element at index
    int& at(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of bounds");
        }
        return arr[index];
    }

    // Resize the array
    void resize(int newSize) {
        int* newArr = new int[newSize]{};
        for (int i = 0; i < (newSize < size ? newSize : size); i++) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        size = newSize;
    }

    // Print array contents
    void print() const {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    DynamicArray arr1(5);
    for (int i = 0; i < arr1.getSize(); i++) {
        arr1.at(i) = i * 2;
    }

    cout << "Array 1: ";
    arr1.print();

    DynamicArray arr2 = arr1;
    cout << "Copied Array 2: ";
    arr2.print();

    DynamicArray arr3 = move(arr1);
    cout << "Moved Array 3: ";
    arr3.print();

    arr2.resize(7);
    cout << "Resized Array 2: ";
    arr2.print();

    return 0;
}
