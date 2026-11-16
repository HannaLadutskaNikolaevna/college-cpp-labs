#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

const int N = 8;  

// --- Часть 1 ---

//фамилия часть строки до первого пробела
string get_surname(const string& line) {
    size_t pos = line.find(' ');
    if (pos == string::npos) {
        return line;
    }
    return line.substr(0, pos);
}

//заполнение массива
void fill_array(string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Учащийся " << i + 1 << " (фамилия и имя) – ";
        getline(cin, arr[i]);
    }
}

//сортировка массива по фамилии 
void sort_array(string arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (get_surname(arr[j]) > get_surname(arr[j + 1])) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

//вывод массива на экран
void print_array(const string arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << arr[i] << endl;
    }
}

//--- Часть 2 ---

// Заполнение массива случайными числами от 10 до 99
void fill_random(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 90 + 10;
    }
}

// Копирование массива
void copy_array(const int src[], int dst[], int n) {
    for (int i = 0; i < n; i++) {
        dst[i] = src[i];
    }
}

// Вывод чисел массива в одну строку
void print_numbers(const int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// Сортировка Шелла
void shell_sort(int a[], int n) {
    int comparisons = 0, swaps = 0, step = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int j = i;
            while (j >= gap) {
                comparisons++;
                if (a[j - gap] > a[j]) {
                    swap(a[j - gap], a[j]);
                    swaps++;
                    j -= gap;
                }
                else {
                    break;
                }
            }
        }
        step++;
        cout << "Итерация " << step << " (шаг " << gap << "): ";
        print_numbers(a, n);
    }
    cout << "Сравнений: " << comparisons << ", обменов: " << swaps << endl;
}

// Сортировка вставками
void insertion_sort(int a[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            comparisons++;
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                swaps++;
                j--;
            }
            else {
                break;
            }
        }
        cout << "Итерация " << i << ": ";
        print_numbers(a, n);
    }
    cout << "Сравнений: " << comparisons << ", обменов: " << swaps << endl;
}

// Сортировка выбором
void selection_sort(int a[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            swap(a[i], a[min_index]);
            swaps++;
        }
        cout << "Итерация " << i + 1 << ": ";
        print_numbers(a, n);
    }
    cout << "Сравнений: " << comparisons << ", обменов: " << swaps << endl;
}

// Сортировка пузырьком
void bubble_sort(int a[], int n) {
    int comparisons = 0, swaps = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparisons++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
        cout << "Итерация " << i + 1 << ": ";
        print_numbers(a, n);
    }
    cout << "Сравнений: " << comparisons << ", обменов: " << swaps << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(0));

    int original[N];   
    int work[N];       
    fill_random(original, N);

    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "=== ЧАСТЬ 1 ===" << endl;
        cout << "1. Сортировка списка учащихся по фамилии" << endl;
        cout << "=== ЧАСТЬ 2 ===" << endl;
        cout << "2. Сортировка Шелла" << endl;
        cout << "3. Сортировка вставками" << endl;
        cout << "4. Сортировка выбором" << endl;
        cout << "5. Сортировка пузырьком" << endl;
        cout << "6. Задать новый случайный массив" << endl;
        cout << "0. Выход из программы" << endl;

        int num_task;
        cout << "Напишите номер – ";
        cin >> num_task;

        if (num_task == 0) {
            cout << "Программа завершена." << endl;
            break;
        }

        cin.ignore();


        if (num_task >= 2 && num_task <= 5) {
            copy_array(original, work, N);
            cout << "\nИсходный массив: ";
            print_numbers(work, N);
        }

        switch (num_task) {
        case 1:
        {
            cout << "\n--- Часть 1 ---" << endl;
            int n;
            cout << "Введите количество учащихся – ";
            cin >> n;
            cin.ignore();
            if (n <= 0) {
                cout << "Количество должно быть положительным." << endl;
                break;
            }

            string* students = new string[n];  

            fill_array(students, n);
            cout << "\nИсходный список:" << endl;
            print_array(students, n);

            sort_array(students, n);
            cout << "\nСписок после сортировки по фамилии (с учётом регистра):" << endl;
            print_array(students, n);

            delete[] students;
            break;
        }
        case 2:
            cout << "Сортировка Шелла:" << endl;
            shell_sort(work, N);
            cout << "Результат: ";
            print_numbers(work, N);
            break;
        case 3:
            cout << "Сортировка вставками:" << endl;
            insertion_sort(work, N);
            cout << "Результат: ";
            print_numbers(work, N);
            break;
        case 4:
            cout << "Сортировка выбором:" << endl;
            selection_sort(work, N);
            cout << "Результат: ";
            print_numbers(work, N);
            break;
        case 5:
            cout << "Сортировка пузырьком:" << endl;
            bubble_sort(work, N);
            cout << "Результат: ";
            print_numbers(work, N);
            break;
        case 6:
            fill_random(original, N);
            cout << "Новый массив: ";
            print_numbers(original, N);
            break;
        default:
            cout << "Такой задачи нет. Пожалуйста, введите число от 0 до 6." << endl;
            break;
        }
    }

    return 0;
}