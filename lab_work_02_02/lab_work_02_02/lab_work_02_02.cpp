#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include <math.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const double pi = 3.14159;
    double x, y, z;
    double b1, b2, b;
    cout << " Введiть значення трьох дiйсних змiнних:\n ";
    cin >> x >> y >> z;

    b1 = log(1 + x * x + y * y + z * z) + exp(-2.1 + x + y);
    b2 = (3.0 / 4.0) * (1 + (x * x / 2 )+( y * y / 4) + (z * z / 8)) * (0.1 + pow(cos(x - y), 2));
    b = pow(fabs(b1 / b2),3);
    cout << fixed << setprecision(4);
    cout << "\nРезультати обчислень:";
    cout << "\n---------------------------------";
    cout << "\nВхідні значення:";
    cout << "\n---------------------------------";
    cout << "\n x = " << x;
    cout << "\n y = " << y;
    cout << "\n z = " << z;
    cout << "\n---------------------------------";
    cout << "\nПроміжні значення:";
    cout << "\n---------------------------------";
    cout << "\n b1 = " << b1;
    cout << "\n b2 = " << b2;
    cout << "\n---------------------------------";
    cout << "\n Остаточне значення:";
    cout << "\n b = " << b;
    cout << "\n---------------------------------\n";
    _getch();
    return 0;
}