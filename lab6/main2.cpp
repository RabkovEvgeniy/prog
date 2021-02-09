// 2. Написать функцию, определяющую вероятность того, что среди n детей будет m
// девочек или m мальчиков. Предусмотреть контроль входных данных. Вероятность
// рождения девочки p=0.45, мальчика q=1-p. Вероятность того, что из n детей
// будет m девочек  равна: pd=cnm . pm.qn-m ,для мальчиков pm=cnm .qm.pn-m
// cnm=n!/(m! *(n-m)!)   Вероятности передать через параметры-ссылки.
#include <cmath>
#include <iostream>

using namespace std;

const double p = 0.45, q = 0.55;

long long int fact(long long int n);

long long int from_n_to_m(int n, int m);

bool foo(int n, int m, double& pd, double& pm);

int main()
{
    int m, n;
    double pm, pd;
    cout << "input n and m:" << endl;
    cin >> n >> m;

    cout << foo(n, m, pd, pm) << endl
         << "pd = " << pd << endl
         << "pm = " << pm << endl;
    return 0;
}

long long int fact(long long int n)
{
    if (n == 0)
        return 1;
    return fact(n - 1) * n;
}

long long int from_n_to_m(int n, int m)
{
    return fact(n) / (fact(m) * fact(n - m));
}

bool foo(int n, int m, double& pd, double& pm)
{
    if (m > n)
        return 0;

    pd = from_n_to_m(n, m) * pow(p, m) * pow(q, n - m);
    pm = from_n_to_m(n, m) * pow(q, m) * pow(p, n - m);
    return 1;
}
