#include "arrlib.h"

namespace mine {
template <typename T>
time_t timer(void (*foo)(T*, int), T* arr, int n)
{
    time_t begin, end;

    time(&begin);
    foo(arr, n);
    time(&end);

    return difftime(end, begin);
}
}
int main()
{
    int arr[90000];
    float arr1[90000];
    FillRand(arr, 90000);
    FillRand(arr1, 90000);

    time_t time;
    time = mine::timer(BubbleSort, arr, 90000);
    std::cout << time << endl;
    time = mine::timer(SelectSort, arr1, 90000);
    std::cout << time << endl;
    return 0;
}
