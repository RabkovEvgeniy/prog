// 1. Написать функцию, которая вычисляет периметр и площадь треугольника.
// В функцию передаётся длина его сторон. Результаты возвращаются через
// параметры-указатели. В функции также предусмотреть ошибку в введённых данных
// (если такой треугольник может существовать, функция возвращает 1, иначе 0
// через своё имя).
#include <cmath>
#include <iostream>

using namespace std;

bool info_about_triengl(double s1, double s2, double s3, double* p, double* s);

int main()
{
    double s, p, s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    cout << info_about_triengl(s1, s2, s3, &p, &s) << " " << p << " " << s
         << endl;
}

bool info_about_triengl(
        const double s1, const double s2, const double s3, double* p, double* s)
{
    if ((s1 + s2 < s3) || (s1 + s3 < s2) || (s2 + s3 < s1)) {
        *p = 0;
        *s = 0;
        return 0;
    }
    *p = s1 + s2 + s3;
    *s
            = sqrt(((*p) / 2) * (((*p) / 2) - s1) * (((*p) / 2) - s2)
                   * (((*p) / 2) - s3));
    return 1;
}
