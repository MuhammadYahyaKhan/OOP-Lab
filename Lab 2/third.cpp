#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int size = 5;
    int* arr = new int[size];
    int elements = 0;

    for (int i = 1; i < argc; i++) {
        if (elements == size) {
            size *= 2;
            int* newarr = new int[size];
            for (int j = 0; j < elements; j++) {
                newarr[j] = arr[j];
            }
            delete[] arr;
            arr = newarr;
        }
        arr[elements] = atoi(argv[i]);
        elements++;
    }

    int* result = new int[elements];
    for (int i = 0; i < elements; i++) {
        result[i] = arr[i];
    }

    delete[] arr;
    arr = result;

    

    delete[] arr;

    return 0;
}
