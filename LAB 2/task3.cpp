// 3. В каждой больничной палате четыре койки. Введите количество
// палат, количество больных мужчин и количество больных женщин. Сколько
// больных мужского пола можно еще положить в больницу?

#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    int wards, men, women;
    cout << "Введите количество палат, мужчин и женщин через пробел: ";
    cin >> wards >> men >> women;

    int men_wards = (men + 3) / 4;
    int women_wards = (women + 3) / 4;
    int used_wards = men_wards + women_wards;

    if (used_wards > wards) {
        cout << "Палат не хватает" << endl;
    } else {
        int free_wards = wards - used_wards;
        int extra_men_beds = (4 - (men % 4)) % 4;
        int free_men_beds = free_wards * 4 + extra_men_beds;

        cout << "Ещё можно положить мужчин: " << free_men_beds << endl;
    }

    return 0;
}
