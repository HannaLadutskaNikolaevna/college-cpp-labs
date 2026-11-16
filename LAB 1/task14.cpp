// 14 Даны три числа. Найти среднее арифметическое этих чисел и
// среднее геометрическое модулей этих чисел.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, c;
    cout << "Введите три числа через пробел: "; 
    cin >> a >> b >> c;

    double arithmetic = (a + b + c) / 3.0;
    double module = abs(a) * abs(b) * abs(c);
    double geometric = pow(module, 1.0 / 3.0);

    cout <<"Среднее арифметическое: "<< arithmetic<< endl;
    cout <<"Среднее геометрическое модулей: " << geometric << endl;
    return 0;

} 
