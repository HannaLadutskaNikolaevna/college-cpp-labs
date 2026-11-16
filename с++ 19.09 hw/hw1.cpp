#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Введите размер массива N: ";
    cin >> N;

    vector<int> A(N);
    cout << "Введите элементы массива A: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sum = 0;
    // Начинаем с 1-го индекса (2-я позиция) и идем с шагом 2
    for (int i = 1; i < N; i += 2) {
        sum += A[i];
    }

    cout << "Сумма элементов на четных позициях: " << sum << endl;

    return 0;
}
