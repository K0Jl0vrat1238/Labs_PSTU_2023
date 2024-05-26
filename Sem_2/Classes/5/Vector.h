#pragma once
#include <vector>
#include "Object.h"

class Vector {
private:
    vector<Object*> items;

public:
    Vector() {}
    ~Vector() {
        for (auto item : items) {
            delete item;
        }
    }

    void Add(Object* item) {
        items.push_back(item);
    }

    friend ostream& operator<<(ostream& out, const Vector& v) {
        if (v.items.empty()) {
            out << "Пусто :(" << endl;
        }
        else {
            for (const auto& item : v.items) {
                item->Show();
            }
        }
        return out;
    }
};