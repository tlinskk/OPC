#include <iostream>
#include <cstring>
#include <windows.h>

class Product {
private:
    char name[50];
    int amount;
    float price;

public:
    // Конструктор без параметрів
    Product() {
        strcpy_s(name, "Невідомий товар");
        amount = 0;
        price = 0.0f;
    }

    // Конструктор з параметрами
    Product(const char* n, int a, float p) {
        strcpy_s(name, n);
        amount = a;
        price = p;
    }

    // Конструктор копіювання
    Product(const Product& other) {
        strcpy_s(name, other.name);
        amount = other.amount;
        price = other.price;
    }

    void setName(const char* n) {
        strcpy_s(name, sizeof(name), n);
    }

    void setAmount(int a) {
        amount = a;
    }

    void setPrice(float p) {
        price = p;
    }

    void printInfo() const {
        std::cout << "Назва: " << name << ", Кількість: " << amount << ", Вартість: " << price << " грн" << std::endl;
    }

    void inputProduct() {
        std::cout << "Введіть назву товару: ";
        std::cin.getline(name, 50);

        std::cout << "Введіть кількість: ";
        std::cin >> amount;

        std::cout << "Введіть вартість: ";
        std::cin >> price;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Конструктор без параметрів
    Product item1;
    item1.printInfo();

    // Конструктор з параметрами
    Product item2("Телевізор", 10, 15000.5f);
    item2.printInfo();

    // Конструктор копіювання
    Product item3 = item2;
    item3.printInfo();

    Product item4;
    item4.inputProduct();
    item4.printInfo();

    return 0;
}

