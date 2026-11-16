// 14. Пользователь вводит порядковый номер пальца руки. Необходимо
// показать его название на экран.

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int finger;
    cout << "Введите порядковый номер пальца руки: ";
    cin >> finger;

    switch(finger) {
        case 1:
        cout << "Большой палец" << endl;
        break;

        case 2:
        cout << "Указательный палец" << endl;
        break;

        case 3:
        cout << "Средний палец" << endl;
        break;

        case 4:
        cout << "Безымянный палец" << endl;
        break;

        case 5:
        cout << "Мизинец" << endl;
        break;

        default:
        cout << "Некорректно введен номер" << endl;
    }
 
    return 0;

}
