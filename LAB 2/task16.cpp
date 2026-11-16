// 16. Напишите программу, печатающую корни квадратного уравнения
// ax2 + bx + c = 0. Если уравнение не имеет корней, то выведите
// соответствующее сообщение.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    cout << "Введите три числа через пробел: ";
    cin >> a >> b >> c;

    double d = b * b - 4 * a * c;

    if (d > 0) {
        double x1 = (-b + sqrt(d)) / (2 * a);
        double x2 = (-b - sqrt(d)) / (2 * a);
        cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
    } 
    else if (d == 0) {
        double x = -b / (2 * a);
        cout << "Уравнение имеет один корень: x = " << x << endl;
    } 
    else {
        cout << "Уравнение не имеет действительных корней" << endl;
    }

    return 0;

}
