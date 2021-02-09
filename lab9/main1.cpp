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
};

struct Node {
    Node(string firstname, int arr[4])
    {
        a.firstname = firstname;
        for (int i = 0; i < 4; i++) {
            a.arr[i] = arr[i];
        }
        this->next = nullptr;
    }
    Note a;
    Node* next;
};

int main()
{
    int n, size = 0;
    cin >> n;
    string firstname;
    int arr[4];

    cout << "input firstname and thour bal:" << endl;
    cin >> firstname;
    for (int i = 0; i < 4; i++) {
        cin >> arr[i];
    }
    size++;
    Node* First = new Node(firstname, arr);
    Node* iterator1 = First;
    Node* iterator2 = nullptr;
    Node* min;
    Note temp;

    for (int j = 0; j < n - 1; j++) {
        cout << "input firstname and thour bal:" << endl;
        cin >> firstname;
        for (int i = 0; i < 4; i++) {
            cin >> arr[i];
        }
        iterator1->next = new Node(firstname, arr);
        iterator1 = iterator1->next;
        size++;
    }

    iterator1 = First;
    for (int i = 0; i < size; i++) {
        min = iterator1;
        iterator2 = iterator1;
        for (int j = i + 1; j < size; j++) {
            iterator2 = iterator2->next;
            if (min->a.firstname > iterator2->a.firstname)
                min = iterator2;
        }
        temp = iterator1->a;
        iterator1->a = iterator2->a;
        iterator2->a = temp;
        iterator1 = iterator1->next;
    }

    iterator1 = First;
    for (int i = 0; i < size; i++) {
        iterator1->a.show();
        iterator1 = iterator1->next;
    }
}
