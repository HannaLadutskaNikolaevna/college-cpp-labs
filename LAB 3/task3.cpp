#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int boxes = 15;
    int car = 1;

    cout << "На складе имеется " << boxes << " ящиков с яблоками." << endl;

    while (boxes > 0) {
        int count;
        cout << "Сколько ящиков загрузить в машину " << car << "?: ";
        cin >> count;

        if (count > boxes) {
            cout << "Ошибка! На складе осталось только " << boxes << " ящиков." << endl;
        } else {
            boxes -= count; // Исправлено: уменьшаем количество ящиков
            cout << "Загружено " << count << " ящиков. Осталось на складе: " << boxes << endl;
            car++;
        }
    }

    cout << "Все ящики со склада погружены!" << endl;
    return 0;
}
