// Имеется n итоговых оценок учащихся. Определите, является ли
// учащийся неуспевающим (имеются оценки ниже 4)

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    
    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "14. Имеется n итоговых оценок учащихся. Определите, является ли учащийся неуспевающим (имеются оценки ниже 4)" << endl;
        cout << "16. Сформировать и вывести на экран массив, элементы которого заданы датчиком случайных чисел на интервале [-56, 47] (размер произвольный). Найти произведение элементов с четными номерами, которые превосходят некоторое число t." << endl;
        cout << "3. Найдите сумму отрицательных элементов массива." << endl;
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
                cout << "\n--- Задача 14: Определить, является ли учащийся неуспевающим ---" << endl;
                
                int n;
                cout << "Введите количество итоговых оценок студента: ";
                cin >> n;

                int* grades = new int[n];
                cout << "Введите оценки:\n";
                for (int i = 0; i < n; i++) {
                    cin >> grades[i];
                }

                bool isUnsuccessful = false;
                for (int i = 0; i < n; i++) {
                    if (grades[i] < 4) {
                        isUnsuccessful = true;
                        break;
                    }
                }

                if (isUnsuccessful) {
                    cout << "Результат: Учащийся является неуспевающим (имеются оценки ниже 4)." << endl;
                } else {
                    cout << "Результат: Учащийся успевающий (нет оценок ниже 4)." << endl;
                }

                delete[] grades;
                break;
            }


            case 16: {
                cout << "\n--- Задача 16: Сформировать и вывести на экран массив ---" << endl;
                
               int n;
                cout << "Введите размер массива: ";
                cin >> n;

                int* arr = new int[n];
                cout << "Сгенерированный массив [-56, 47]: ";
                for (int i = 0; i < n; i++) {
                    
                    arr[i] = rand() % (47 - (-56) + 1) + (-56);
                    cout << arr[i] << " ";
                }
                cout << endl;

                int t;
                cout << "Введите число t: ";
                cin >> t;

                long long product = 1;
                bool found = false;

            
                for (int i = 0; i < n; i += 2) { 
                    if (arr[i] > t) {
                        product *= arr[i];
                        found = true;
                    }
                }

                if (found) {
                    cout << "Произведение элементов с четными индексами, превосходящих " << t << ": " << product << endl;
                } else {
                    cout << "Нет элементов с четными индексами, превосходящих заданное число " << t << "." << endl;
                }

                delete[] arr;
                break;
            }


            case 3: {
            int n;
                cout << "Введите размер массива: ";
                cin >> n;
                
                int* arr = new int[n];
                cout << "Введите элементы массива (" << n << " шт.):\n";
                for (int i = 0; i < n; i++) {
                    cin >> arr[i];
                }

                int sumNegative = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] < 0) {
                        sumNegative += arr[i];
                    }
                }

                cout << "Сумма отрицательных элементов: " << sumNegative << endl;
                delete[] arr;
                break;
            }

            default:
                cout << "Ошибка: задачи с таким номером нет в списке!" << endl;
                break;
        }
    }

    return 0;
}