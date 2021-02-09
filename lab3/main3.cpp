// 3. Ввести с клавиатуры число n, вычислить и вывести с помощью алгоритма
// “решето Эратосфена”(изучить  алгоритм самостоятельно) простые числа в
// диапазон от 2 до n. Использовать динамический массив размера n.
#include <iostream>

using namespace std;

int main()
{
    int n, *ptr;
    cin >> n;

    try {
        ptr = new int[n];
        if (ptr == NULL)
            throw 1;
    } catch (const int e) {
        cout << "error " << e;
        return e;
    }
    for (int i = 0; i < n; i++)
        ptr[i] = i;
    for (int i = 2; i < n; i++) {
        if (ptr[i] != -1)
            for (int j = i + 1; j < n; j++)
                if (ptr[j] % i == 0)
                    ptr[j] = -1;
    }
    for (int i = 2; i < n; i++)
        if (ptr[i] != -1)
            cout << ptr[i] << " ";

    delete[] ptr;

    cout << endl;
}
