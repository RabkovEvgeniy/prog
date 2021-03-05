// 1. Написать функцию, сортирующую в порядке убывания элементы одномерного
// массива. В главной программе вызвать функцию для двух разных по количеству
// элементов массивов N=100 и  N=1000.
// Написать две функции поиска заданных элементов в каждом из отсортированных
// массивов – перебором и бинарным поиском. Вывести количество операций
// сравнения в каждой функции.
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

template <typename T>
void FillRand(T* arr, int size);

template <typename T>
void booble(T* arr, int size);

template <typename T>
int find(T* arr, int size, T found);

template <typename T>
int bin_find(T* arr, int size, T found);

int main()
{
    srand(time(0));

    int arr1[100];
    int arr2[1000];

    FillRand(arr1, 100);
    FillRand(arr2, 1000);

    booble(arr1, 100);
    booble(arr2, 1000);

    for (int i = 0; i < 100; i++) {
        if (i % 20 == 0 && i != 0)
            cout << endl;
        cout << arr1[i] << " ";
    }
    cout << endl << endl;

    for (int i = 0; i < 1000; i++) {
        if (i % 20 == 0 && i != 0)
            cout << endl;
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    cout << find(arr1, 100, 5) << endl << bin_find(arr1, 100, 5) << endl;
    cout << find(arr2, 1000, 10) << endl << bin_find(arr2, 1000, 10) << endl;
    return 0;
}

template <typename T>
void booble(T* arr, int size)
{
    int count = 0;
    T temp;
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            count++;
        }
    cout << "sr: " << count << endl;
}

template <typename T>
void FillRand(T* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

template <typename T>
int find(T* arr, int size, T found)
{
    int count = 0;
    for (int i = 0; i < size; i++) {
        count++;
        if (arr[i] == found) {
            cout << "sr: " << count << endl;
            return i;
        }
    }
    cout << "sr: " << count << endl;
    return -1;
}

template <typename T>
int bin_find(T* arr, int size, T found)
{
    int count = 0;
    int d = size / 2;
    int i = size / 2;
    while (true) {
        count++;
        if (arr[i] == found) {
            cout << "sr: " << count << endl;
            return i;
        }
        d /= 2;
        if (arr[i] > found)
            i += d;
        else
            i -= d;
        count += 3;
        if (d == 0)
            break;
    }
    if (arr[i] > found)
        i++;
    else
        i--;
    count += 3;
    if (arr[i] == found) {
        cout << "sr: " << count << endl;
        return i;
    }
    cout << "sr: " << count << endl;
    return -1;
}
