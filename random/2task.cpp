#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int t;

    cout << "Введите количество секунд: ";
    cin >> t;

    int hours = t / 3600;
    int minutes = (t % 3600) / 60;
    int seconds = t % 60;

    cout << "Часы: " << hours << endl;
    cout << "Минуты: " << minutes << endl;
    cout << "Секунды: " << seconds << endl;

    return 0;
}
