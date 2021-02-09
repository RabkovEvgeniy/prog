// Сформировать двусвязный список, состоящий из структур, содержащих
// информацию: фамилия студента и 4 оценки. Найти и удалить из списка
// студентов, имеющих хотя бы одну неудовлетворительную оценку.
// Вывести список до и после удаления записей.
#include <iostream>
#include <string>

struct Note {
    std::string firstname;
    int arr[4];

    void show()
    {
        std::cout << firstname << " ";
        for (int i = 0; i < 4; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

struct Node {
    Note a;
    Node* previous;
    Node* next;
    void SetAll(std::string firstname, int* arr)
    {
        a.firstname = firstname;
        for (int i = 0; i < 4; i++)
            a.arr[i] = arr[i];
    }
};

class iterator {
    Node* it;

public:
    iterator(Node* First)
    {
        it = First;
    }
    void set_iterator(Node* First)
    {
        it = First;
    }
    iterator& operator++()
    {
        if (it != nullptr)
            it = it->next;
        return *this;
    }
    iterator& operator--()
    {
        if (it != nullptr)
            it = it->previous;
        return *this;
    }
    Node& operator*()
    {
        return *it;
    }
    iterator& operator=(Node* it)
    {
        this->it = it;
        return *this;
    }
};

int main()
{
    int n, size = 0;

    std::cin >> n;

    std::string firstname;
    int arr[4];

    std::cout << "input firstname and thour bal:" << std::endl;
    std::cin >> firstname;
    for (int i = 0; i < 4; i++) {
        std::cin >> arr[i];
    }

    Node* First = new Node;
    Node* Last = First;

    First->SetAll(firstname, arr);
    First->previous = nullptr;
    First->next = nullptr;
    size++;

    iterator it(First);

    for (int j = 0; j < n - 1; j++) {
        std::cout << "input firstname and thour bal:" << std::endl;
        std::cin >> firstname;
        for (int i = 0; i < 4; i++) {
            std::cin >> arr[i];
        }
        First = new Node;
        First->previous = nullptr;
        First->SetAll(firstname, arr);
        First->next = &(*it);
        (*it).previous = First;
        it = First;
        size++;
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++) {
        (*it).a.show();
        ++it;
    }

    std::cout << std::endl;

    it.set_iterator(First);

    iterator it1((*it).next);

    n = 0;
    for (int i = 0; i < size; i++) {
        if (((*it).a.arr[1] < 3) || ((*it).a.arr[2] < 3) || ((*it).a.arr[3] < 3)
            || ((*it).a.arr[0] < 3)) {
            if ((*it).previous != nullptr)
                (*it).previous->next = (*it).next;
            else
                First = (*it).next;
            if ((*it).next != nullptr)
                (*it).next->previous = (*it).previous;
            else
                Last = (*it).previous;
            delete (&(*it));
            it = it1;
            n++;
        } else
            ++it;
        ++it1;
    }
    size -= n;

    it.set_iterator(First);

    for (int i = 0; i < size; i++) {
        (*it).a.show();
        ++it;
    }

    it.set_iterator(First);
    it1.set_iterator((*it).next);
    n = 0;
    for (int i = 0; i < size; i++) {
        if ((*it).previous != nullptr)
            (*it).previous->next = (*it).next;
        else
            First = (*it).next;
        if ((*it).next != nullptr)
            (*it).next->previous = (*it).previous;
        else
            Last = (*it).previous;
        delete (&(*it));
        it = it1;
        n++;
        ++it1;
    }
}
