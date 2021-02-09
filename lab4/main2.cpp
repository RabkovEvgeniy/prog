// 2. Задан двумерный динамический массив А  размерности   m x n. ( m и n
// вводить с клавиатуры).    Заполнить его случайными числами.  Создать массив D
// размером m+1 на  n+1, в который записать элементы массива А и суммы элементов
// соответствующих строк и столбцов исходного массива А.  В элемент D[m+1][n+1]
// поместить сумму всех элементов исходного массива.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    try {
        srand(time(0));
        int m, n, sum;

        cin >> m >> n;
        cout << endl;

        int** A = new int*[m]; //создаю массив указателей на m
        if (A == NULL)
            throw 1;

        int** D = new int*[m + 1]; //создаю массив указателей на m + 1
        if (D == NULL)
            throw 2;

        for (int i = 0; i < m; i++) { // инициализирую массив указателей
            A[i] = new int[n];
            if (A[i] == NULL)
                throw 3;
        }

        for (int i = 0; i < m + 1; i++) { // инициализирую массив указателей
            D[i] = new int[n + 1];
            if (D[i] == NULL)
                throw 4;
        }

        for (int i = 0; i < m; i++) //заполняю массив случайными числами
            for (int j = 0; j < n; j++)
                A[i][j] = rand() % 100;

        for (int i = 0; i < m; i++) //заполняю массив D эллементами A
            for (int j = 0; j < n; j++)
                D[i][j] = A[i][j];
        //---------------------------------------------------------------------
        for (int i = 0; i < m; i++) { //сумма по строкам
            sum = 0;
            for (int j = 0; j < n; j++)
                sum += D[i][j];
            D[i][n] = sum;
        }
        for (int i = 0; i <= n; i++) { //сумма по всем столбцам
            sum = 0;
            for (int j = 0; j < m; j++)
                sum += D[j][i];
            D[m][i] = sum;
        }
        //---------------------------------------------------------------------
        for (int i = 0; i < m; i++) { //вывод исходного массива
            for (int j = 0; j < n; j++)
                cout << A[i][j] << "\t";
            cout << endl;
        }

        cout << endl;

        for (int i = 0; i < m + 1; i++) { //вывод полученного массива массива
            for (int j = 0; j < n + 1; j++)
                cout << D[i][j] << "\t";
            cout << endl;
        }

        for (int i = 0; i < m; i++) // освобождаю память исходного массива
            delete[] A[i];
        delete[] A;
        A = nullptr;

        for (int i = 0; i < m + 1; i++) //освобождаю память полученного массива
            delete[] D[i];
        delete[] D;
        D = nullptr;

    } catch (const int e) {
        cout << "error " << e;
        return e;
    }
    return 0;
}
