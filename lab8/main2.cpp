// 2. Дана информация о комнатах в общежитии. Запись имеет вид: номер комнаты,
// площадь комнаты, факультет, количество проживающих.
// • сформировать массив из записей.
// • вычислить количество различных факультетов и занести их в отдельный массив.
// • вывести данные о  количестве комнат, количестве студентов и средней площади
//  на одного студента по каждому факультету.
#include <iostream>
#include <string>

using namespace std;

struct fac {
    string name;
    int st = 0;
    int room = 0;
    double mid_s = 0;
};

struct room {
    int nam;
    int S;
    string fac;
    int people;
};

int main()
{
    bool flag;
    int n, l = 0;
    cin >> n;

    fac* res = new fac[n];

    room* arr = new room[n];

    for (int i = 0; i < n; i++) {
        cout << "input num, S, fac, people";
        cin >> arr[i].nam >> arr[i].S >> arr[i].fac >> arr[i].people;
        cout << "------------------------------------------" << endl;
    }

    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n; j++)
            flag = (arr[i].fac == res[j].name) || flag;
        if (!flag)
            res[l++].name = arr[i].fac;
    }
    fac* Res = new fac[l];

    for (int i = 0; i < l; i++)
        Res[i] = res[i];

    delete[] res;
    res = nullptr;

    for (int i = 0; i < l; i++)
        for (int j = 0; j < n; j++)
            if (Res[i].name == arr[j].fac) {
                Res[i].room++;
                Res[i].st += arr[j].people;
                Res[i].mid_s += arr[j].S;
            }

    for (int i = 0; i < l; i++)
        Res[i].mid_s /= Res[i].st;

    cout << "facult: " << endl;
    for (int i = 0; i < l; i++)
        cout << Res[i].name << "\t room:" << Res[i].room
             << "\t student:" << Res[i].st
             << "\t middle squere:" << Res[i].mid_s << endl;
    cout << endl;

    delete[] Res;
    delete[] arr;
}
