// 2. Используя оператор new, выделить память под одномерный динамический массив
// a[n] (n вводить с клавиатуры) и массив указателей b[n]. Заполнить массив a
// вещественными случайными числами,  а  массив b адресами элементов массива a.
// Отсортировать массив по возрастанию, используя массив указателей . Исходный
// массив измениться не должен. Вывести исходный  и отсортированный массив.
// Освободить память.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    int n;
    srand(time(0));
    cin >> n;

    bool flag = 0;
    double *temp, *a, **b;
    try {
        a = new double[n];
        if (a == NULL)
            throw 1;

        b = new double*[n];
        if (b == NULL)
            throw 2;
    } catch (const int& b) {
        cout << "Error " << b;
        return b;
    }
    for (int i = 0; i < n; i++) {
        a[i] = ((double)rand() / RAND_MAX) * 10 - 5;
        b[i] = &a[i];
    }
    for (int i = 0; i < n; i++) {
        flag = 0;
        for (int j = 0; j < n - i - 1; j++)
            if (*b[j] > *b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
                flag = 1;
            }
        if (!flag)
            break;
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl << endl;

    for (int i = 0; i < n; i++)
        cout << *b[i] << " ";
    cout << endl << endl;

    delete[] a;
    delete[] b;
    return 0;
}
