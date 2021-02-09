// 1.Используя функцию malloc(), выделить память под одномерный динамический
// массив b[n] (n вводить с клавиатуры). Заполнить его целыми случайными числами
// в диапазоне -50 … 50. Получить  динамический массив c[m], содержащий
// положительные числа массива b, и  динамический массив d[k], содержащий
// отрицательные числа. m и k должны быть равны количеству положительных и
// отрицательных чисел. Вывести исходный массив и полученные массивы. Освободить
// память.
#include <cmath>
#include <ctime>
#include <exception>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    srand(time(0));
    int n, m = 0, k = 0;
    int *b, *c, *d;
    cin >> n;

    try {
        b = (int*)malloc(n * sizeof(int));
        if (b == NULL)
            throw 1;
        for (int i = 0; i < n; i++) {
            b[i] = rand() % 101 - 50;
            if (b[i] > 0)
                m++;
            if (b[i] < 0)
                k++;
        }

        if (m != 0)
            c = (int*)malloc(m * sizeof(int));
        if (c == NULL)
            throw 2;

        if (k != 0)
            d = (int*)malloc(k * sizeof(int));
        if (d == NULL)
            throw 3;
    } catch (const int& err) {
        cout << "Error" << err;
        return err;
    }

    for (int i = 0, j = 0, l = 0; i < n; i++) {
        if (b[i] > 0) {
            c[j] = b[i];
            j++;
        }
        if (b[i] < 0) {
            d[l] = b[i];
            l++;
        }
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    free(b);

    for (int i = 0; i < m; i++)
        cout << c[i] << " ";
    cout << endl;
    free(c);

    for (int i = 0; i < k; i++)
        cout << d[i] << " ";
    cout << endl;
    free(d);

    return 0;
}
