#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct QueueElem
{
    int data;
    QueueElem* next;
};
struct Queue
{
    QueueElem* front;
    QueueElem* back;
    int size;
    void init()
    {
        front = nullptr;
        back = front;
        size = 0;
    }
    void push(int data)
    {
        QueueElem* tmp = new QueueElem;
        tmp->data = data;
        tmp->next = nullptr;
        if (size == 0)
        {
            front = tmp;
            back = tmp;
        }
        else
        {
            back->next = tmp;
            back = tmp;
        }
        size++;
    }
    int pop()
    {
        int value = front->data;
        QueueElem* tmp = front;
        if (size == 1) { back = nullptr; }
        front = front->next;
        size--;
        delete tmp;
        return value;
    }
    QueueElem* frontEl() { return front; }
    QueueElem* backEl() { return back; }

};
Queue create_queue(int size)
{
    Queue queue{ };
    queue.init();
    int data, counter = 1;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите элемент №" << counter++ << " ";
        cin >> data;
        queue.push(data);
    }
    return queue;
}
void show_queue(Queue& queue)
{
    if (queue.front == nullptr and queue.back == nullptr)
    {
        cout << "Пустая очередь\n";
        return;
    }
    cout << "Очередь: ";
    for (int i = 0; i < queue.size; i++)
    {
        int data = queue.pop();
        cout << data << " ";
        queue.push(data);
    }
    cout << endl;
}
void delQueue(Queue& queue)
{
    while (queue.frontEl() != nullptr)
    {
        QueueElem* tmp = queue.frontEl();
        queue.front = queue.front->next;
        delete tmp;
        queue.size--;
    }
    queue.back = nullptr;
    cout << "Очередь удалена\n";
}
void delElem(Queue& queue, int del, int K)
{
    if (del > queue.size || del <= 0 || K < 0 || del - K <= 0)
    {
        cout << "Ошибка\n";
        return;
    }
    Queue tmpQ{};
    tmpQ.init();
    // Сохраняем элементы до позиции del - K во временной очереди
    for (int i = 1; i < del - K; i++)
    {
        tmpQ.push(queue.pop());
    }
    // Удаляем K элементов
    for (int i = 0; i < K; i++)
    {
        queue.pop();
    }
    // Перемещаем элементы из временной очереди обратно, сохраняя порядок
    while (tmpQ.size > 0)
    {
        queue.push(tmpQ.pop());
    }
    // Перемещаем оставшиеся элементы в конец очереди, сохраняя порядок
    int remaining = queue.size - del + K + 1;
    for (int i = 0; i < remaining; i++)
    {
        tmpQ.push(queue.pop());
    }
    while (tmpQ.size > 0)
    {
        queue.push(tmpQ.pop());
    }
}
void addElements(Queue& queue, int N)
{
    cout << "Добавление " << N << " элементов в конец очереди.\n";
    for (int i = 0; i < N; i++)
    {
        int data;
        cout << "Введите элемент №" << i + 1 << ": ";
        cin >> data;
        queue.push(data);
    }
}
void saver(Queue& queue)
{
    ofstream file("F.txt");
    while (queue.front != nullptr)
    {
        int data = queue.pop();
        file << data << endl;
    }
    file.close();
    cout << "Очередь сохранена\n";
}
void resurrection(Queue& queue)
{
    ifstream file("F.txt");
    string tmp;
    while (getline(file, tmp))
    {
        int data = stoi(tmp);
        queue.push(data);
    }
    file.close();
    cout << "Очередь восстановлена\n";
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int size;
    cout << "Введите количество элементов в очереди: ";
    cin >> size;
    Queue ququ = create_queue(size);
    show_queue(ququ);
    if (ququ.frontEl() != nullptr)
    {
        int del,k;
        cout << "Введите номер элемента до которого хотите удалить элементы: ";
        cin >> del;
        cout << "Сколько элементов хотите удалить: ";
        cin >> k;
        delElem(ququ, del, k);
        show_queue(ququ);

        int numbers;
        cout << "Сколько элементов хотите добавить: ";
        cin >> numbers;
        addElements(ququ, numbers);
        show_queue(ququ);
        saver(ququ);
        delQueue(ququ); //необязательно т.к. после saver очередь уже пустая, но пусть будет
        resurrection(ququ);
        show_queue(ququ);
    }
    return 0;
}