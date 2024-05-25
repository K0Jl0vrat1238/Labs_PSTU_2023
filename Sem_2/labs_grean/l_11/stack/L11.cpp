#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct StackElem
{
    int data;
    StackElem* next;
};
struct Stack
{
    StackElem* top;
    int size;
    void init()
    {
        top = nullptr;
        size = 0;
    }
    void push(int data)
    {
        StackElem* cur = new StackElem;
        cur->data = data;
        cur->next = top;
        top = cur;
        size++;
    }
    int pop()
    {
        int value = top->data;
        StackElem* tmp = top;
        top = top->next;
        size--;
        delete tmp;
        return value;
    }
    StackElem* topElem()
    {
        return top;
    }
};
Stack create_stack(int size)
{
    Stack stack{ };
    stack.init();
    int data, counter = 1;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите элемент №" << counter++ << " ";
        cin >> data;
        stack.push(data);
    }
    return stack;
}
void showStack(Stack& stack)
{
    if (stack.top == nullptr)
    {
        cout << "Стек пуст\n";
        return;
    }
    cout << "Стек: ";
    Stack tmpStack{ };
    tmpStack.init();
    while (stack.topElem() != nullptr)
    {
        int data = stack.pop();
        tmpStack.push(data);
    }
    while (tmpStack.topElem() != nullptr)
    {
        int data = tmpStack.pop();
        cout << data << " ";
        stack.push(data);
    }
    cout << endl;
}
void StackExtermination(Stack& stack)
{
    StackElem* current = stack.top;
    while (current != nullptr)
    {
        StackElem* temp = current;
        current = current->next;
        delete temp;
    }
    stack.top = nullptr;
    stack.size = 0;
    cout << "Стек удален\n";
}
void DelBeforeElem(Stack& stack, int position, int K) {
    if (position > stack.size || position <= K) {
        cout << "Ошибка: невозможно удалить элементы\n";
        return;
    }

    // Создаем временный стек для хранения элементов до позиции удаления
    Stack tempStack;
    tempStack.init();

    // Перемещаем элементы из основного стека во временный до элемента, перед которым нужно удалить K элементов
    int elementsToMove = stack.size - position + 1;
    while (elementsToMove--) {
        tempStack.push(stack.pop());
    }

    // Пропускаем K элементов, которые нужно удалить
    for (int i = 0; i < K; ++i) {
        if (tempStack.top == nullptr) {
            cout << "Ошибка: меньше элементов, чем ожидалось\n";
            return;
        }
        StackElem* toDelete = tempStack.top;
        tempStack.top = tempStack.top->next;
        delete toDelete;
    }

    // Возвращаем оставшиеся элементы из временного стека обратно в основной
    while (tempStack.top != nullptr) {
        stack.push(tempStack.pop());
    }
}
void addElem(Stack& stack, int numberNewElements)
{
    Stack tmpStack{ };
    tmpStack.init();
    int sizer = stack.size;
    for (int i = 0; i < sizer; i++)
    {
        int data = stack.pop();
        tmpStack.push(data);
    }
    for (int i = 0; i < numberNewElements; i++) {
        int newData;
        cout << "Введите значение нового: ";
        cin >> newData;
        stack.push(newData);
    }
        while (tmpStack.top != nullptr)
        {
            int data = tmpStack.pop();
            stack.push(data);
        }
        stack.size++;
    
}
void saver(Stack& stack)
{
    ofstream file("F.txt");
    while (stack.top != nullptr)
    {
        int data = stack.pop();
        file << data << endl;
    }
    file.close();
    cout << "Стек сохранен\n";
}
void RetuneStackToTheTrueGlory(Stack& stack)
{
    ifstream file("F.txt");
    Stack tmpStack{ };
    tmpStack.init();
    string tmpStr;
    while (getline(file, tmpStr))
    {
        int data = stoi(tmpStr);
        tmpStack.push(data);
    }
    while (tmpStack.top != nullptr)
    {
        int data = tmpStack.pop();
        stack.push(data);
    }
    file.close();
    cout << "Стек восстановлен\n";
}
int main()
{
    setlocale(LC_ALL, "ru_RU");
    int size;
    cout << "Введите количество элементов в стеке: ";
    cin >> size;
    Stack steck = create_stack(size);
    showStack(steck);
    if (steck.top != nullptr)
    {

        int num, k, numberElements;
        cout << "Введите номер элемента до котоого хотитек удалить: ";
        cin >> num;
        cout << "Введиете количество элементов подлежащих удалению: ";
        cin >> k;
        DelBeforeElem(steck, num, k);
        showStack(steck);
        
        cout << "Введите количество элеементов которые надо добавить: ";
        cin >> numberElements;
        addElem(steck,numberElements);
        showStack(steck);
        saver(steck);
  
    }
    return 0;
}