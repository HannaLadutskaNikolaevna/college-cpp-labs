#include <iostream>
#include <string>
#include <set>
#include <map>
#include <cctype>
#include <clocale>
 
using namespace std;

// Задание 3
bool is_anagram(const string& word1, const string& word2) {
    multiset<char> letters1(word1.begin(), word1.end());
    multiset<char> letters2(word2.begin(), word2.end());
    return letters1 == letters2;
}

// Задание 14
bool is_balanced(const string& text) {
    int balance = 0;
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == '(') {
            balance++;
        }
        else if (text[i] == ')') {
            balance--;
        }
        if (balance < 0) {
            return false;
        }
    }
    return balance == 0;
}

// Задание 16.1
map<string, int> count_pairs(const string& text) {
    map<string, int> pairs;
    for (size_t i = 0; i + 1 < text.length(); i++) {
        unsigned char a = (unsigned char)text[i];
        unsigned char b = (unsigned char)text[i + 1];
        if (isalpha(a) && isalpha(b)) {
            string pair = "";
            pair += (char)a;
            pair += (char)b;
            pairs[pair]++;
        }
    }
    return pairs;
}

// Задание 16.2
void print_pairs(const map<string, int>& pairs) {
    for (map<string, int>::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
        cout << "  " << it->first << " – " << it->second << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "1. Задание 3: Проверить, являются ли два слова анаграммами" << endl;
        cout << "2. Задание 14: Проверить баланс открывающих и закрывающих круглых скобок" << endl;
        cout << "3. Задание 16: Подсчитать количество каждой пары рядом расположенных букв" << endl;
        cout << "0. Выход из программы" << endl;

        int num_task;
        cout << "Напишите номер – ";
        cin >> num_task;

        if (num_task == 0) {
            cout << "Программа завершена." << endl;
            break;
        }

        cin.ignore();

        switch (num_task) {
        case 1:
        {
            cout << "\n--- Задача 3 ---" << endl;
            string word1, word2;
            cout << "Введите первое слово – ";
            getline(cin, word1);
            cout << "Введите второе слово – ";
            getline(cin, word2);

            if (word1.empty() || word2.empty()) {
                cout << "Результат: слова не введены." << endl;
            }
            else if (is_anagram(word1, word2)) {
                cout << "Результат: слова являются анаграммами." << endl;
            }
            else {
                cout << "Результат: слова не являются анаграммами." << endl;
            }
            break;
        }
        case 2:
        {
            cout << "\n--- Задача 14 ---" << endl;
            string text;
            cout << "Введите текст со скобками – ";
            getline(cin, text);

            if (is_balanced(text)) {
                cout << "Результат: баланс скобок соблюден (корректно)." << endl;
            }
            else {
                cout << "Результат: баланс скобок нарушен (некорректно)." << endl;
            }
            break;
        }
        case 3:
        {
            cout << "\n--- Задача 16 ---" << endl;
            string text;
            cout << "Введите текст – ";
            getline(cin, text);

            map<string, int> pairs = count_pairs(text);

            if (pairs.empty()) {
                cout << "В тексте нет рядом расположенных букв." << endl;
            }
            else {
                cout << "Двухбуквенные сочетания:" << endl;
                print_pairs(pairs);
            }
            break;
        }
        default:
            cout << "Такой задачи нет. Пожалуйста, введите число от 0 до 3." << endl;
            break;
        }
    }

    return 0;
}