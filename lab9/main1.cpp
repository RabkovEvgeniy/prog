// Сформировать односвязный список, состоящий из структур, содержащих
// информацию: фамилия студента и 4 оценки. Отсортировать список  по
// возрастанию (по фамилии).  Вывести полученный список.
#include <iostream>
#include <string>

using namespace std;

struct Note {
    string firstname;
    int arr[4];

    void show()
    {
        cout << firstname << " ";
        for (int i = 0; i < 4; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void SetAll(string firstname, int* arr)
    {
        this->firstname = firstname;
        for (int i = 0; i < 4; i++)
            this->arr[i] = arr[i];
    }
};

bool sr_str(string str1, string str2)
{
    for (int i = 0; i < str1.size() && i < str2.size(); i++) {
        if ((int)str1[i] > (int)str2[i])
            return 1;
        if ((int)str1[i] < (int)str2[i])
            return 0;
        if ((i + 1) == str1.size())
            return 1;
    }
    return 0;
}

struct Node {
    Note a;
    Node* next;
};

int main()
{
    int n, size;
    cin >> n;
    size = n;
    string input, st;
    int arr[4];

    cout << "input firstname and thour bal:" << endl;
    cin >> input;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }

    Node* First = new Node;
    First->next = nullptr;
    First->a.SetAll(input, arr);

    Node* iterator1 = First;
    Node* iterator2 = nullptr;
    Node* min;
    Note temp;

    for (int j = 0; j < n - 1; j++) {
        cout << "input firstname and thour bal:" << endl;
        cin >> input;
        for (int i = 0; i < 4; i++) {
            cin >> arr[i];
        }
        First = new Node;
        First->a.SetAll(input, arr);
        First->next = iterator1;
        iterator1 = First;
    }

    cout << endl;

    for (int i = 0; i < size; i++) {
        iterator1->a.show();
        iterator1 = iterator1->next;
    }

    iterator1 = First;

    for (int i = 0; i < size; i++) {
        min = iterator1;
        iterator2 = iterator1;
        for (int j = i + 1; j < size; j++) {
            iterator2 = iterator2->next;
            st = min->a.firstname;
            input = iterator2->a.firstname;
            if (sr_str(st, input)) {
                min = iterator2;
            }
        }

        temp = iterator1->a;   // swap
        iterator1->a = min->a; //
        min->a = temp;         //

        iterator1 = iterator1->next;
    }
    cout << endl;
    iterator1 = First;

    for (int i = 0; i < size; i++) {
        iterator1->a.show();
        iterator1 = iterator1->next;
    }

    for (int i = 0; i < size; i++) {
        iterator1 = First->next;
        delete First;
        First = iterator1;
    }
}
