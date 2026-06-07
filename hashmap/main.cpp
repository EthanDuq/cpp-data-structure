/**
 * THIS HASHMAP AS ONLY PURPOSE TO UNDERSTAND HOW HASHMAP WORKS WITH SIMPLE
 * LINKEDLIST, IT DOESN'T HAVE TEMPLATE ECT ONLY STRING FOR KEY AND INT FOR VALUE
 */

#include <iostream>
#include <string>
#include "../linked-list/linked_list.hpp"

using namespace std;
using namespace Linked_List;

struct Item {
        string key;
        int value;

        Item();
        Item(const string &_key, int _value);
        // operator to compare Item together
        bool operator==(const Item &other){return key == other.key;};
        bool operator!=(const Item &other){return key != other.key;};
};
// permit to print an item
ostream& operator<<(ostream &out, const Item &item) {
        out << "[key: " << item.key << ", value: " << item.value << " ]";
        return out;
}

struct MyHashMap {
        int capacity;
        Linked_List::LinkedList<Item> *items;

        MyHashMap(int _capacity);
        ~MyHashMap();
        bool insert(const string &_key, int _value);
        bool remove(const string &_key);
        bool get(const string &_key, int &out);
        void prettyprint();
};

int hash_string(const string &_key, int _capacity) {
        return hash<string>() (_key) % _capacity;
}

Item::Item() {
        key = "";
        value = 0;
}

Item::Item(const string &_key, int _value) {
        key = _key;
        value = _value;
}

MyHashMap::MyHashMap(int _capacity) {
        capacity = _capacity;
        items = new LinkedList<Item>[_capacity];
}

MyHashMap::~MyHashMap() {
        capacity = 0;
        delete[] items;
        items = nullptr;
}

bool MyHashMap::insert(const string &_key, int _value) {
        int hash_value{hash_string(_key, capacity)};
        Item data(_key, _value);
        if (items[hash_value].exist(data)) {
                // data, data because they compare KEY and not VALUE
                return items[hash_value].replace(data, data);
        }
        return items[hash_value].insert(data);
}

bool MyHashMap::remove(const string &_key) {
        int hash_value{hash_string(_key, capacity)};
        Item data(_key, 0); // ghost item, just needed to compare key to remove
        return items[hash_value].remove(data);
}

bool MyHashMap::get(const string &_key, int &out) {
        int hash_value{hash_string(_key, capacity)};
        auto value {
        items[hash_value].find_if([&](Item i) { return i.key == _key; })};

        if (value.has_value()) {
                out = value.value().value;
                return true;
        }
        return false;
}

void MyHashMap::prettyprint() {
        cout << "[\n";
        for (int i = 0; i < capacity; i++) {
                if (!items[i].isEmpty())
                        items[i].prettyPrint();
        }
        cout << "]\n";
}

int main() {
        MyHashMap map(50);
        map.insert("age", 25);
        map.insert("test", 30);
        map.insert("abc", 1);
        map.insert("cba", 2);
        map.insert("bonjour", 439);
        map.insert("salut", 3120);
        map.prettyprint();
        map.insert("age", 30);
        map.prettyprint();
        int x;
        map.get("age", x);
        cout << "value of x : " << x << "\n";
        return 0;
}
