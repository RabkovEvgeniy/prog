// 1. Дана информация о  школах города. Запись имеет вид: номер школы,
// количество выпускников школы, число поступивших в ВУЗ. • сформировать массив
// из записей. • отсортировать его с помощью индексного массива по проценту
// поступивших в ВУЗы. • вывести данные о количестве выпускников в каждой школе
// и проценту поступивших в ВУЗ.
#include <iostream>

using namespace std;

struct school {
    int nam;
    int vip;
    int post;
    double pr_post()
    {
        return (double)post / vip * 100;
    }
};

int main()
{
    int n;
    school temp_sc;

    cout << "count of school: ";
    cin >> n;

    school* arr = new school[n];

    for (int i = 0; i < n; i++) {
        cout << "input nam, vip , post:";
        cin >> arr[i].nam >> arr[i].vip >> arr[i].post;
    }

    cout << endl;

    int* index = new int[n];
    int temp_pr;

    for (int i = 0; i < n; i++) {
        index[i] = i;
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[index[j]].pr_post() < arr[index[j + 1]].pr_post()) {
                temp_pr = index[j];
                index[j] = index[j + 1];
                index[j + 1] = temp_pr;
            }

    for (int i = 0; i < n; i++)
        cout << "school №" << arr[index[i]].nam << ": " << arr[index[i]].vip
             << " " << arr[index[i]].pr_post() << "%" << endl;
    delete[] index;
    delete[] arr;
}
