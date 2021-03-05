#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

template <typename T>
void FillInc(T* arr, int size);
template <typename T>
void FillDec(T* arr, int size);
void FillRand(float* arr, int size);
void FillRand(int* arr, int size);
template <typename T>
void Swap(T& a, T& b);
template <typename T>
void PrintMas(T* arr, int size);
template <typename T>
T CheckSum(T* arr, int size);
template <typename T>
int RunNumb(T* arr, int size);
void SelectSort(float* arr, int size);
void BubbleSort(int* arr, int size);
