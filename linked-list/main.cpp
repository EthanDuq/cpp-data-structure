#include <iostream>
#include "linked_list.hpp"

using namespace Linked_List;

int main() {
        Linked_List::LinkedList<char> list;
        // int x {1}, y {2}, z {x + y};
        char x {'a'}, y {'b'}, z {'c'};

        list.prettyPrint();
        list.insert(x);
        list.insert(y);
        list.insert(z);
        list.prettyPrint();
        std::cout << "Empty ?" << list.isEmpty() << "\n";
        std::cout << "size : " << list.size() << "\n";
        std::cout << "first : " << list.get_first() << "\n";
        std::cout << "last : " << list.get_last() << "\n";
        list.prettyPrint();
        x = 5;
        list.remove(y);
        list.prettyPrint();
        std::cout << "new size : " << list.size() << "\n";
}
