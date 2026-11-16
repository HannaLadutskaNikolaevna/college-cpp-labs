#include <iostream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    while (true) {
        cout << "\n------------------------------------------------------------" << endl;
        cout << "Выберите номер задачи:" << endl;
        cout << "=== ЧАСТЬ 1 ===" << endl;
        cout << "1. Задание 3: Заменить точки многоточием, а многоточия — восклицательным знаком" << endl;
        cout << "2. Задание 14: Вставить символ '*' после каждого гласного символа" << endl;
        cout << "3. Задание 16: Подсчитать 4-буквенные слова, каждое четное заменить на 'SsSs'" << endl;
        cout << "=== ЧАСТЬ 2 ===" << endl;
        cout << "4. Задание 3: Проверить баланс открывающих и закрывающих скобок" << endl;
        cout << "5. Задание 14: Подсчитать 5-буквенные слова и каждое из них заменить на 'SsSs'" << endl;
        cout << "6. Задание 16: Найти слово с максимальной долей прописных «А»" << endl;
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
            cout << "\n--- Часть 1, Задача 3 ---" << endl;
            string text;
            cout << "Введите предложение – ";
            getline(cin, text);

            size_t pos = 0;
            while ((pos = text.find("...", pos)) != string::npos) {
                text.replace(pos, 3, "!");
                pos += 1;
            }
            pos = 0;
            while ((pos = text.find('.', pos)) != string::npos) {
                text.replace(pos, 1, "...");
                pos += 3;
            }

            cout << "Результат – " << text << endl;
            break;
        }
        case 2:
        {
            cout << "\n--- Часть 1, Задача 14 ---" << endl;
            string text;
            cout << "Введите текст на английском языке – ";
            getline(cin, text);

            string result = "";
            for (size_t i = 0; i < text.length(); i++) {
                char ch = text[i];
                result += ch;
                char lower_ch = tolower(ch);
                if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || 
                    lower_ch == 'o' || lower_ch == 'u' || lower_ch == 'y') {
                    result += '*';
                }
            }

            cout << "Результат – " << result << endl;
            break;
        }
        case 3:
        {
            cout << "\n--- Часть 1, Задача 16 ---" << endl;
            string text, word;
            int count = 0;
            string result = "";
            bool is_first = true;

            cout << "Введите текст – ";
            getline(cin, text);

            stringstream ss(text);
            while (ss >> word) {
                string leading_punct = "";
                string trailing_punct = "";

                while (!word.empty() && ispunct(word.back())) {
                    trailing_punct = word.back() + trailing_punct;
                    word.pop_back();
                }
                while (!word.empty() && ispunct(word.front())) {
                    leading_punct += word.front();
                    word.erase(0, 1);
                }

                if (word.length() == 4) {
                    count++;
                    if (count % 2 == 0) {
                        word = "SsSs";
                    }
                }

                word = leading_punct + word + trailing_punct;

                if (!is_first) {
                    result += " ";
                }
                result += word;
                is_first = false;
            }

            cout << "Количество четырехбуквенных слов – " << count << endl;
            cout << "Новая строка – " << result << endl;
            break;
        }
        case 4:
        {
            cout << "\n--- Часть 2, Задача 3 ---" << endl;
            string text;
            cout << "Введите текст со скобками – ";
            getline(cin, text);

            int balance = 0;
            bool correct = true;

            for (size_t i = 0; i < text.length(); i++) {
                if (text[i] == '(') {
                    balance++;
                }
                else if (text[i] == ')') {
                    balance--;
                }
                if (balance < 0) {
                    correct = false;
                    break;
                }
            }

            if (correct && balance == 0) {
                cout << "Результат: Баланс скобок соблюден (корректно)." << endl;
            } else {
                cout << "Результат: Баланс скобок нарушен (некорректно)." << endl;
            }
            break;
        }
        case 5:
        {
            cout << "\n--- Часть 2, Задача 14 ---" << endl;
            string text, word;
            int count = 0;
            string result = "";
            bool is_first = true;

            cout << "Введите текст – ";
            getline(cin, text);

            stringstream ss(text);
            while (ss >> word) {
                string leading_punct = "";
                string trailing_punct = "";

                while (!word.empty() && ispunct(word.back())) {
                    trailing_punct = word.back() + trailing_punct;
                    word.pop_back();
                }
                while (!word.empty() && ispunct(word.front())) {
                    leading_punct += word.front();
                    word.erase(0, 1);
                }

                if (word.length() == 5) {
                    count++;
                    word = "SsSs";
                }

                word = leading_punct + word + trailing_punct;

                if (!is_first) {
                    result += " ";
                }
                result += word;
                is_first = false;
            }

            cout << "Количество пятибуквенных слов – " << count << endl;
            cout << "Новая строка – " << result << endl;
            break;
        }
        case 6:
        {
            cout << "\n--- Часть 2, Задача 16 ---" << endl;
            string text, word, max_word = "";
            double max_percent = -1;

            cout << "Введите предложение – ";
            getline(cin, text);

            stringstream ss(text);
            while (ss >> word) {
                while (!word.empty() && ispunct(word.back())) word.pop_back();
                while (!word.empty() && ispunct(word.front())) word.erase(0, 1);

                int count_A = 0;
                for (size_t i = 0; i < word.length(); i++) {
                    if (word[i] == 'A') {
                        count_A++;
                    }
                }

                if (!word.empty()) {
                    double percent = (double)count_A / word.length();
                    if (percent > max_percent) {
                        max_percent = percent;
                        max_word = word;
                    }
                }
            }

            if (!max_word.empty()) {
                cout << "Слово с максимальной долей прописных «A» – " << max_word << endl;
            } else {
                cout << "В предложении нет слов." << endl;
            }
            break;
        }
        default:
            cout << "Такой задачи нет. Пожалуйста, введите число от 0 до 6." << endl;
            break;
        }
    }

    return 0;
}
