#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    double a, b, S, G;

    cout << "Введите два числа: ";
    cin >> a >> b;

    S = (pow(a, 3) + pow(b, 3)) / 2.0;
    G = sqrt(fabs(a) * fabs(b));

    cout << "Среднее арифметическое кубов = " << S << endl;
    cout << "Среднее геометрическое модулей = " << G << endl;

    return 0;
}
