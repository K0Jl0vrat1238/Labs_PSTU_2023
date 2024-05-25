#include <iostream>
#include <string>
#include <ctime>

using namespace std;

const int TABLE_SIZE = 50;
const int NAME_COUNT = 30;

string rand_name[NAME_COUNT] = { "Александр", "Мария", "Иван", "Екатерина", "Максим",
        "Дарья", "Артём", "Анастасия", "Дмитрий", "Софья",
        "Михаил", "Ксения", "Владимир", "Елизавета", "Андрей",
        "Марина", "Игорь", "Юлия", "Алексей", "Яна",
        "Тимофей", "Полина", "Роман", "Валерия", "Никита",
        "Татьяна", "Арсений", "Вероника", "Евгений", "Кристина" };

int get_hash(string str) {
    unsigned key = 0;
    for (char ch : str) {
        key += ch;
    }
    return static_cast<int>(key * 0.2) % TABLE_SIZE;
}

struct Node {
    string name;
    int series;
    int number;
    Node* next;

    Node() : name(" "), series(0), number(0), next(nullptr) {}
    Node(string n, int s, int num) : name(n), series(s), number(num), next(nullptr) {}
};

class HashTable {
private:
    Node** table;

public:
    HashTable() {
        table = new Node * [TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* entry = table[i];
            while (entry != nullptr) {
                Node* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] table;
    }

    void set_node(string name, int series, int number) {
        int hash = get_hash(name);
        Node* prev = nullptr;
        Node* entry = table[hash];

        while (entry != nullptr && entry->name != " ") {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new Node(name, series, number);
            if (prev == nullptr) {
             
                table[hash] = entry;
            }
            else {
                prev->next = entry;
            }
        }
        else {
           
            entry->name = name;
            entry->series = series;
            entry->number = number;
        }
    }

    void print_table() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            Node* entry = table[i];
            while (entry != nullptr) {
                cout << "Name: " << entry->name << endl;
                cout << "Series: " << entry->series << endl;
                cout << "Number: " << entry->number << endl;
                cout << "=======================\n";
                entry = entry->next;
            }
        }
    }

    void set_table(int count) {
        srand(static_cast<unsigned int>(time(nullptr)));
        for (int i = 0; i < count; ++i) {
            int r = rand() % NAME_COUNT;
            int series = rand() % 8999 + 1000;
            int number = rand() % 899999 + 100000;
            set_node(rand_name[r], series, number);
        }
    }
};

int main() {
    system("chcp 1251>0");
    HashTable* people = new HashTable;
    people->set_table(80);
    people->print_table();
    delete people;

    return 0;
}