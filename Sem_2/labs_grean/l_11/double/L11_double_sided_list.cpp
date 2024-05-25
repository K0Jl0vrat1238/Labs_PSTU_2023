#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct ListElem
{
    int data;
    ListElem* next;
    ListElem* prev;
};
ListElem* createList(int n)
{
    if (n > 0)
    {
        ListElem* start = nullptr;
        ListElem* p, * r;
        start = new ListElem;
        int counter = 1;
        cout << "Введите элемент №" << counter << " ";
        counter++;
        cin >> start->data;
        start->next = nullptr;
        start->prev = nullptr;
        p = start;
        for (int i = 0; i < n - 1; i++)
        {
            cout << "Введите элемент №" << counter << " ";
            counter++;
            r = new ListElem;
            cin >> r->data;
            r->next = nullptr;
            r->prev = p;
            p->next = r;
            p = r;
        }
        return start;
    }
    return nullptr;
}
void showList(ListElem* start)
{
    if (start != nullptr)
    {
        ListElem* p = start;
        cout << "Список: ";
        while (p != nullptr)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Список пуст " << endl;
    }
    return;
}
void delElem(ListElem*& start, int pos, int K)
{
    if (start == nullptr || pos <= 0 || K < 0 || pos - K <= 0)
    {
        cout << "Ошибка: неверный ввод.\n";
        return;
    }

    // Если нужно удалить элементы до начала списка
    if (pos - K <= 1)
    {
        while (K-- > 0 && start != nullptr)
        {
            ListElem* toDelete = start;
            start = start->next;
            if (start != nullptr) start->prev = nullptr;
            delete toDelete;
        }
    }
    else
    {
        ListElem* temp = start;
        // Перемещаемся к элементу, который предшествует первому удаляемому элементу
        for (int i = 1; temp != nullptr && i < pos - K; ++i)
        {
            temp = temp->next;
        }

        // Удаляем K элементов
        for (int i = 0; i < K; ++i)
        {
            if (temp->next == nullptr) break;

            ListElem* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next != nullptr) toDelete->next->prev = temp;
            delete toDelete;
        }
    }
}
void addElementsToEnd(ListElem*& start, int N)
{
    cout << "Добавление " << N << " элементов в конец списка.\n";
    for (int i = 0; i < N; i++)
    {
        int data;
        cout << "Введите значение нового элемента: ";
        cin >> data;

        ListElem* newElem = new ListElem;
        newElem->data = data;
        newElem->next = nullptr;

        // Если список пуст, новый элемент становится началом списка
        if (start == nullptr)
        {
            start = newElem;
            newElem->prev = nullptr;
        }
        else
        {
            // Иначе, находим последний элемент и добавляем новый элемент в конец
            ListElem* temp = start;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newElem;
            newElem->prev = temp;
        }
    }
}
void saver(ListElem* start)
{
    ofstream file("F1.txt");
    if (file.is_open())
    {
        ListElem* p = start;
        while (p != nullptr)
        {
            file << p->data << endl;
            p = p->next;
        }
        cout << "Список сохранен в файл " << endl;
    }
    else
    {
        cout << "error";
    }
    file.close();
}
void cleaner(ListElem*& start)
{
    ListElem* ext = start;
    ListElem* save;
    while (ext != nullptr)
    {
        save = ext->next;
        delete ext;
        ext = save;
    }
    start = nullptr;
    cout << "Список удален " << endl;
}
void recovery(ListElem* start)
{
    ifstream file("F1.txt");
    if (file.is_open())
    {
        ListElem* p, * r;
        start->next = nullptr;
        start->prev = nullptr;
        string tmp;
        getline(file, tmp);
        int numb = stoi(tmp);
        start->data = numb;
        p = start;
        while (getline(file, tmp))
        {
            int num = stoi(tmp);
            r = new ListElem;
            r->data = num;
            r->next = nullptr;
            r->prev = p;
            p->next = r;
            p = r;
        }
        cout << "Список восстановлен " << endl;
    }
    else
    {
        cout << "error";
    }
    file.close();
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int n;
    cout << "Введите количество элементов списка ";
    cin >> n;
    ListElem* start = createList(n);
    cout << endl;
    showList(start);
    if (start->next != nullptr)
    {
        int del, k;
        cout << "Введите номер элемента до которого хотите удалить ";
        cin >> del;
        cout << "Сколько элементов хотите удалить";
        cin >> k;
        delElem(start, del, k);
        showList(start);
        int numbers;
        cout << "Сколько элементов хотите добавить ";
        cin >> numbers;
        addElementsToEnd(start, numbers);
        showList(start);
        saver(start);
        cleaner(start);
        start = new ListElem;
        recovery(start);
        showList(start);
    }
    return 0;
}