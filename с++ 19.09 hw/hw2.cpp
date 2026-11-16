#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Введите размер массива N: ";
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);

    cout << "Введите элементы массива A: ";
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        B[i] = A[i] + i;
    }

    cout << "Массив B: ";
    for (int i = 0; i < N; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
