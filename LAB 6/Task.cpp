#include <iostream>
#include <cmath> 

using namespace std;

int countFives(int arr[], int size);
double averageNegative(int arr[], int size);
double geometricMean(double arr[], int size);

int main() {
    setlocale(LC_ALL, "Russian");
    
    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "3. Функция поиска количества элементов, равных 5 (ввод 3 массивов)" << endl;
        cout << "14. Функция поиска среднего арифметического отрицательных элементов (ввод 3 массивов)" << endl;
        cout << "16. Функция поиска среднего геометрического элементов массива (ввод 3 массивов)" << endl;
        cout << "0.  Выход из программы" << endl;
        
        int choice;
        cout << "Введите номер задачи (или 0 для выхода): ";
        cin >> choice;

        if (choice == 0) {
            cout << "Программа завершена." << endl;
            break;
        }


        switch (choice) {
            case 3: {
                cout << "\n--- Задание 3: Поиск количества элементов, равных 5 ---" << endl;
                

                int n1;
                cout << "Введите размер первого массива (p): ";
                cin >> n1;
                int* p = new int[n1];
                cout << "Введите элементы массива p:\n";
                for (int i = 0; i < n1; i++) {
                    cin >> p[i];
                }


                int n2;
                cout << "Введите размер второго массива (q): ";
                cin >> n2;
                int* q = new int[n2];
                cout << "Введите элементы массива q:\n";
                for (int i = 0; i < n2; i++) {
                    cin >> q[i];
                }


                int n3;
                cout << "Введите размер третьего массива (r): ";
                cin >> n3;
                int* r = new int[n3];
                cout << "Введите элементы массива r:\n";
                for (int i = 0; i < n3; i++) {
                    cin >> r[i];
                }


                cout << "\n--- Результаты ---" << endl;
                cout << "В массиве p элементов, равных 5: " << countFives(p, n1) << endl;
                cout << "В массиве q элементов, равных 5: " << countFives(q, n2) << endl;
                cout << "В массиве r элементов, равных 5: " << countFives(r, n3) << endl;


                delete[] p;
                delete[] q;
                delete[] r;
                break;
            }

            case 14: {
                cout << "\n--- Задание 14: Среднее арифметическое отрицательных элементов ---" << endl;
                

                int n1;
                cout << "Введите размер массива a: ";
                cin >> n1;
                int* a = new int[n1];
                cout << "Введите элементы массива a:\n";
                for (int i = 0; i < n1; i++) {
                    cin >> a[i];
                }


                int n2;
                cout << "Введите размер массива b: ";
                cin >> n2;
                int* b = new int[n2];
                cout << "Введите элементы массива b:\n";
                for (int i = 0; i < n2; i++) {
                    cin >> b[i];
                }


                int n3;
                cout << "Введите размер массива c: ";
                cin >> n3;
                int* c = new int[n3];
                cout << "Введите элементы массива c:\n";
                for (int i = 0; i < n3; i++) {
                    cin >> c[i];
                }

                cout << "\n--- Результаты ---" << endl;
                cout << "Среднее арифметическое отрицательных в массиве a: " << averageNegative(a, n1) << endl;
                cout << "Среднее арифметическое отрицательных в массиве b: " << averageNegative(b, n2) << endl;
                cout << "Среднее арифметическое отрицательных в массиве c: " << averageNegative(c, n3) << endl;


                delete[] a;
                delete[] b;
                delete[] c;
                break;
            }

            case 16: {
                cout << "\n--- Задание 16: Среднее геометрическое элементов массива ---" << endl;
                

                int n1;
                cout << "Введите размер массива a: ";
                cin >> n1;
                double* a = new double[n1];
                cout << "Введите элементы массива a (положительные числа):\n";
                for (int i = 0; i < n1; i++) {
                    cin >> a[i];
                }

                int n2;
                cout << "Введите размер массива b: ";
                cin >> n2;
                double* b = new double[n2];
                cout << "Введите элементы массива b (положительные числа):\n";
                for (int i = 0; i < n2; i++) {
                    cin >> b[i];
                }


                int n3;
                cout << "Введите размер массива c: ";
                cin >> n3;
                double* c = new double[n3];
                cout << "Введите элементы массива c (положительные числа):\n";
                for (int i = 0; i < n3; i++) {
                    cin >> c[i];
                }


                cout << "\n--- Результаты ---" << endl;
                cout << "Среднее геометрическое в массиве a: " << geometricMean(a, n1) << endl;
                cout << "Среднее геометрическое в массиве b: " << geometricMean(b, n2) << endl;
                cout << "Среднее геометрическое в массиве c: " << geometricMean(c, n3) << endl;


                delete[] a;
                delete[] b;
                delete[] c;
                break;
            }

            default:
                cout << "Ошибка: задачи с таким номером нет в списке!" << endl;
                break;
        }
    }

    return 0;
}



// Функция для задания 3
int countFives(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 5) {
            count++;
        }
    }
    return count;
}

// Функция для задания 14
double averageNegative(int arr[], int size) {
    double sum = 0;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < 0) {
            sum += arr[i];
            count++;
        }
    }
    if (count == 0) {
        return 0; // Защита от деления на ноль
    }
    return sum / count;
}

// Функция для задания 16 
double geometricMean(double arr[], int size) {
    double product = 1.0;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return pow(product, 1.0 / size);
}