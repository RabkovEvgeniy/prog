// 1.Задан двумерный динамический массив B  размерности m x n. (n=5, m вводить с
// клавиатуры). Заполнить её случайными числами. Получить новую динамическую
// матрицу С[m-1][n-1]  путем удаления из В строки и столбца, в которых
// содержится максимальный элемент исходной матрицы.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

typedef int ggg[5];

int main()
{
    try {
        srand(time(0));
        int m, n = 5, c = 0, l = 0;

        cin >> m;
        cout << endl;

        ggg* B = new ggg[m]; //создаю массив указателей на m
        if (B == NULL)
            throw 1;

        int** Temp = new int*[m - 1]; //создаю массив указателей на m - 1
        if (Temp == NULL)
            throw 2;

        // for (int i = 0; i < m; i++) { // инициализирую массив указателей
        //     B[i] = new int[n];
        //     if (B[i] == NULL)
        //         throw 3;
        // }

        for (int i = 0; i < m - 1; i++) { // инициализирую массив указателей
            Temp[i] = new int[n - 1];
            if (Temp[i] == NULL)
                throw 4;
        }

        for (int i = 0; i < m; i++) //заполняю массив случайными числами
            for (int j = 0; j < n; j++)
                B[i][j] = rand() % 100;

        for (int i = 0; i < m; i++) { //вывод исходного массива
            for (int j = 0; j < n; j++) {
                cout << B[i][j] << " ";
                if (B[i][j] < 10)
                    cout << " ";
            }
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < m; i++) // ищу строку и столбец мах элемента
            for (int j = 0; j < n; j++)
                if (B[i][j] >= B[l][c]) {
                    l = i;
                    c = j;
                }
        for (int i = 0; i < m - 1;
             i++) //копирую все нужные элементы в новый массив
            for (int j = 0; j < n - 1; j++)
                Temp[i][j] = B[(i >= l) ? (i + 1) : i][(j >= c) ? (j + 1) : j];

        for (int i = 0; i < m - 1; i++) { //вывод полученного массива массива
            for (int j = 0; j < n - 1; j++) {
                cout << Temp[i][j] << " ";
                if (Temp[i][j] < 10)
                    cout << " ";
            }
            cout << endl;
        }

        delete[] B;
        B = nullptr;

        for (int i = 0; i < m - 1; i++) //освобождаю память полученного массива
            delete[] Temp[i];
        delete[] Temp;
        Temp = nullptr;

    } catch (const int e) {
        cout << "error " << e;
        return e;
    }
    return 0;
}
