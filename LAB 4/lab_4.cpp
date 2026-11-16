#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "14. Определить наибольший элемент последовательности" << endl;
        cout << "16. Определить наименьший элемент последовательности" << endl;
        cout << "3.  Вывести таблицу кубов первых 10 целых нечётных положительных чисел" << endl;
        cout << "0.  Выход из программы" << endl;
        
        int choice;
        cout << "Введите номер задачи (или 0 для выхода): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Программа завершена." << endl;
            break;
        }

        switch (choice) {
            case 14: {
                cout << "\n--- Задача 14: Поиск наибольшего элемента ---" << endl;
                
                int N;
                double num, max_val;
                
                cout << "Введите количество чисел N: ";
                cin >> N;
                
                if (N <= 0) {
                    cout << "Ошибка: количество чисел должно быть больше 0!" << endl;
                    break;
                }
                
                cout << "Введите число 1: ";
                cin >> num;
                max_val = num;
                
                for (int i = 2; i <= N; i++) {
                    cout << "Введите число " << i << ": ";
                    cin >> num;
                    
                    if (num > max_val) {
                        max_val = num;
                    }
                }
                
                cout << "Наибольший элемент последовательности: " << max_val << endl;
                break;
            }
            case 16: {
                cout << "\n--- Задача 16: Поиск наименьшего элемента ---" << endl;
                
                int N;
                double num, min_val;
                
                cout << "Введите количество чисел N: ";
                cin >> N;
                
                if (N <= 0) {
                    cout << "Ошибка: количество чисел должно быть больше 0!" << endl;
                    break;
                }
                
                cout << "Введите число 1: ";
                cin >> num;
                min_val = num;
                
                for (int i = 2; i <= N; i++) {
                    cout << "Введите число " << i << ": ";
                    cin >> num;
                    
                    if (num < min_val) {
                        min_val = num;
                    }
                }
                
                cout << "Наименьший элемент последовательности: " << min_val << endl;
                break;
            }
            case 3: {
                cout << "\n--- Задача 3 ---" << endl;
                
                int number = 1;
                
                for (int i = 1; i <= 10; i++) {
                    int cube = number * number * number;
                    cout << "Число: " << number << ", куб: " << cube << endl;
                    number += 2;
                }
                break;
            }
            default:
                cout << "Ошибка: задачи с таким номером нет в списке!" << endl;
                break;
        }
    }

    return 0;
}