#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b, c, d;
    cout << "Уравнение вида ax^3 + bx^2 + cx + d = 0." << endl;
    cout << "Введите a: ";
    cin >> a;
    cout << "Введите b: ";
    cin >> b;
    cout << "Введите c: ";
    cin >> c;
    cout << "Введите d: ";
    cin >> d;

    int j = 1;
    for (int i = 0; i <= 1000; i++) {
        if (a * i * i * i + b * i * i + c * i + d == 0) {
            cout << "x" << j << " = " << i << endl;
            j++;
        }
    }

    return 0;
}
