// 2. Написать функцию, которая вычисляет для двумерного массива с переменной
// длинной строк (длина строк случайна в диапазоне от 2 до 10) сумму элементов
// каждой строки. Длина каждой строки хранится в 0 элементе соответствующей
// строки. Массив сформировать с помощью случайных чисел, и вывести на экран в
// главной программе.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

void foo(int** arr, int n);

int main()
{
    srand(time(0));
    int t, n, **arr;
    cin >> n;

    arr = new int*[n];

    for (int i = 0; i < n; i++) {
        t = rand() % 9 + 2;
        arr[i] = new int[t];
        arr[i][0] = t;
        cout << t << " ";
        for (int j = 1; j < t; j++) {
            arr[i][j] = rand() % 90 + 10;
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    foo(arr, n);
}

void foo(int** arr, int n)
{
    int sum;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = 0; j < arr[i][0]; j++)
            sum += arr[i][j];
        cout << "sum line №" << i << " = " << sum << endl;
    }

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
}
