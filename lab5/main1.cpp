// 1. Сгенерировать одномерный динамический массив A из m элементов. Вводится
// число k (k<m). Получить из А матрицу B, по k элементов в строке.  Если m не
// кратно k,  недостающие элементы последней строки дополнить нулями.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

int main()
{
    try {
        srand(time(0));
        int m, k, s;
        cin >> m >> k;
        if (k > m)
            throw 1;
        cout << endl;

        s = m / k;
        if (m % k != 0)
            s++;
        int* A = new int[m];
        if (A == NULL)
            throw 2;

        for (int i = 0; i < m; i++)
            A[i] = rand() % 90 + 10;

        int** B = new int*[s];
        if (B == NULL)
            throw 2;

        for (int i = 0; i < s; i++) {
            B[i] = new int[k];
            if (B[i] == NULL)
                throw 3;
        }

        for (int i = 0, j = 0; i < s; i++)
            for (int l = 0; l < k; l++) {
                B[i][l] = (j < m) ? A[j] : 0;
                j++;
            }

        for (int i = 0; i < m; i++)
            cout << A[i] << " ";
        cout << endl << endl;

        for (int i = 0; i < s; i++) {
            for (int j = 0; j < k; j++)
                cout << B[i][j] << " ";
            cout << endl;
        }
    } catch (const int e) {
        cout << "Error " << e << endl;
        return e;
    }
    return 0;
}
