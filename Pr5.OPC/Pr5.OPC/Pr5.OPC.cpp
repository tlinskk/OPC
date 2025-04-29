#include <iostream>
#include <windows.h>
#include <cmath>    
using namespace std;


template <typename T>
class ArrayProcessor {
private:
    T* data;
    int size;

public:
    ArrayProcessor(T* arr, int n) {
        size = n;
        data = new T[size];
        for (int i = 0; i < size; ++i)
            data[i] = arr[i];
    }

    ~ArrayProcessor() {
        delete[] data;
    }

   
    int indexMaxAbs() {
        int index = 0;
        T maxAbs = abs(data[0]);

        for (int i = 1; i < size; ++i) {
            if (abs(data[i]) > maxAbs) {
                maxAbs = abs(data[i]);
                index = i;
            }
        }

        return index;
    }

    
    T sumAfterFirstPositive() {
        bool found = false;
        T sum = 0;

        for (int i = 0; i < size; ++i) {
            if (!found && data[i] > 0) {
                found = true;
                continue;
            }
            if (found)
                sum += abs(data[i]);
        }

        return sum;
    }

    
    void transform(double a, double b) {
        T* temp = new T[size];
        int idx = 0;

        
        for (int i = 0; i < size; ++i) {
            double integerPart = floor(data[i]);
            if (integerPart >= a && integerPart <= b)
                temp[idx++] = data[i];
        }

        
        for (int i = 0; i < size; ++i) {
            double integerPart = floor(data[i]);
            if (integerPart < a || integerPart > b)
                temp[idx++] = data[i];
        }

        for (int i = 0; i < size; ++i)
            data[i] = temp[i];

        delete[] temp;
    }

    void printArray() {
        for (int i = 0; i < size; ++i)
            cout << data[i] << " ";
        cout << endl;
    }
};


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int size;
    cout << "Введіть розмір масиву: ";
    cin >> size;

    float* arr = new float[size];
    cout << "Введіть " << size << " елементів масиву:\n";
    for (int i = 0; i < size; ++i) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    ArrayProcessor<float> processor(arr, size);

    cout << "\nНомер максимального за модулем елемента: ";
    cout << processor.indexMaxAbs() << endl;

    cout << "Сума модулів після першого додатного елемента: ";
    cout << processor.sumAfterFirstPositive() << endl;

    cout << "\nМасив до перетворення:\n";
    processor.printArray();

    float a, b;
    cout << "\nВведіть інтервал [a, b] для перетворення: ";
    cin >> a >> b;
    processor.transform(a, b);

    cout << "Масив після перетворення:\n";
    processor.printArray();

    delete[] arr;
    return 0;
}

