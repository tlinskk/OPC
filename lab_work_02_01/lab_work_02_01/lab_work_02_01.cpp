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
	double a1, a2, a3, a4, a5, a;
	cout << " Введiть значення трьох дiйсних змiнних:\n ";
	cin >> x >> y >> z;
	
	a1 = 1.7 + log(4 + x*x) + atan(z) - 2.1 + x * y;
	a2 = sqrt(fabs(x - y) + 1) + 3 * x * y * z;
	a3 = cos(y / (x * x + y * y + 1));
	a4 = pi + sin(x + z) + pow(a3, 2);
	a5 = 2 + a2 / a4;
	a = a1 / a5;
    cout << fixed << setprecision(4); // Форматування виводу до 4 знаків після коми
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
    cout << "\n a1 = " << a1;
    cout << "\n a2 = " << a2;
    cout << "\n a3 = " << a3;
    cout << "\n a4 = " << a4;
    cout << "\n a5 = " << a5;
    cout << "\n---------------------------------";
    cout << "\n Остаточне значення:";
    cout << "\n a = " << a;
    cout << "\n---------------------------------\n";
	_getch();
	return 0;
}

