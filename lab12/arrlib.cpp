#include "arrlib.h"

void FillRand(int* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void FillRand(float* arr, int size)
{
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
}

void SelectSort(float* arr, int size)
{
    int k;
    for (int i = 0; i < size - 1; i++) {
        k = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] > arr[k])
                k = j;
        }
        Swap(arr[k], arr[i]);
    }
}

template <typename T>
void Swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
void PrintMas(T* arr, int size)
{
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
        if (i % 20 == 0 && i != 0)
            cout << endl;
    }
    cout << endl;
}

template <typename T>
T CheckSum(T* arr, int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum;
}

template <typename T>
int RunNumb(T* arr, int size)
{
    int res = 0;

    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[i - 1])
            res++;
    }
    return res + 1;
}

void BubbleSort(int* arr, int size)
{
    for (int i = 0; i < size - 1; i++)
        for (int j = size - 1; j > i; j--)
            if (arr[j] < arr[j - 1]) {
                Swap(arr[j], arr[j - 1]);
            }
}
