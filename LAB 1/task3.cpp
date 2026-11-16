// 3 Написать программу вычисления стоимости покупки нескольких
// тетрадей и карандашей. Стоимость одной тетради и карандаша, и
// фактического количества покупок вводится с клавиатуры.

#include <iostream> 
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    double note_price, pencil_price;
    int note_count, pencil_count;

    cout << "Введите цену одной тетради: ";
    cin >> note_price;
    
    cout << "Введите количество тетрадей: ";
    cin >> note_count;

    cout << "Введите цену одного карандаша: ";
    cin >> pencil_price;

    cout << "Введите количество карандашей: ";
    cin >> pencil_count;

    double total_price = ((note_price * note_count) + (pencil_price * pencil_count)); 
    cout << "Общая суммма покупки: " << total_price << " руб." << endl;
  
 return 0;   

}