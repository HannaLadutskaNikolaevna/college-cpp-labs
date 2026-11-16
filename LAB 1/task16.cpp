// 16 Имеется A яблок, которые нужно поделить между тремя подружками следующим образом:
// не менее половины первой, не менее 25% второй, остальные третьей.
// Сколько получит третья подружка?

#include <iostream>
using namespace std;

int main() { 
    setlocale(LC_ALL, "Russian");
    int A; 
    cout << "Введите общее количество яблок: "; 
    cin >> A;

    int friend1 = A / 2;
    int friend2 = A / 4;
    int friend3 = A - (friend1 + friend2);

    cout << "Первая подружка получит: " << friend1 << endl;
    cout << "Вторая подружка получит: " << friend2 << endl;
    cout << "Третья подружка получит: " << friend3 << endl;

    return 0;
}
