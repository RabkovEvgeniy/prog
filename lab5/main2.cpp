// 2. Создать двумерный массив с переменной длиной строки, в который записать
// таблицу умножения следующего вида:
// 1
// 2   4
// 3   6   9
// 4   8  12 16
// 5  10 15 20 25
// 6  12 18 24 30 36
// 7  14 21 28 35 42 49
// 8  16 24 32 40 48 56 64
// 9  18 27 36 45 54 63 72 81
#include <iostream>

using namespace std;

int main()
{
    try {
        int** p = new int*[9];
        if (p == NULL)
            throw 1;
        for (int i = 0; i < 9; i++) {
            p[i] = new int[i + 1];
            if (p[i] == NULL)
                throw 2;
            for (int j = 0; j < i + 1; j++) {
                p[i][j] = (i + 1) * (j + 1);
                cout << p[i][j] << " ";
                if (p[i][j] < 10)
                    cout << " ";
            }
            cout << endl;
        }
    } catch (const int e) {
        cout << "Error " << e << endl;
        return e;
    }
    return 0;

    for (int i = 0; i < 9; i++) {
        delete[] p[i];
    }
    delete[] p;
    p = nullptr;
}
