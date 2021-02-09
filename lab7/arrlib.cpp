#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

template <typename T>
void FillInc(T* arr, int n) 
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

}

template <typename T>
void FillDec(T* arr, int n) 
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = n - i;
	}

}

template <typename T>
void FillRand(T* arr, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % n;
	}

}

template <typename T>
T CheckSum(T* arr, int n)
{

	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	return sum;
}

template <typename T>
int RunNumb(T* arr, int n)
{
	int res = 0;

	for (int i = 1; i < n; i++)
	{
		if(arr[i]< arr[i-1]) res++;
	}
	return res+1;
}

template <typename T>
void PrintMas(T* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << arr[i] << " ";
	}

	cout << endl;
}

int main()
{
	srand(time(0));

	const int n = 10;
	int A[n]{};
	
	FillInc(A,n);
	PrintMas(A, n);
	std::cout << CheckSum(A, n) << endl;
	std::cout << RunNumb(A, n) << endl;
	
	FillDec(A,n);
	PrintMas(A, n);
	std::cout << CheckSum(A, n) << endl;
	std::cout << RunNumb(A, n) << endl;
	

	FillRand(A, n);
	PrintMas(A, n);
	std::cout << CheckSum(A, n) << endl;
	std::cout << RunNumb(A, n) << endl;

	//-----------------------На 5 с +;
	double med=0;

	for (int i = 0; i < 1000; i++)
	{
		FillRand(A, n);
		med += RunNumb(A, n);
	}
	med /= 1000.0;
	cout <<endl << med;
};