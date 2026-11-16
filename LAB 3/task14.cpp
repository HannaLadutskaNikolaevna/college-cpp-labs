#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    int N;
    cout << "Введите количество чисел N: ";
    cin >> N;

    int zeros = 0, pos = 0, neg = 0;
    for (int i = 1; i <= N; i++) { 
        int num;
        cout << "Введите число " << i << " : ";
        cin >> num;
        
        if (num == 0) {
            zeros++;
        } else if (num > 0) {
            pos++;
        } else {
            neg++;
        }
    }

    cout << "Число нулей: " << zeros << endl;
    cout << "Число положительных чисел: " << pos << endl;
    cout << "Число отрицательных чисел: " << neg << endl;

    return 0;
}
