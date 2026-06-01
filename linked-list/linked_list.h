#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

namespace Linked_List {
        struct Node {
                int data;
                Node *next;

                Node(); // empty list
                Node(int &value, Node *n);
        };

        class LinkedList {
        private:
                Node *root;
        public:
                LinkedList();
                ~LinkedList();
                bool insert(int &value);
                bool remove(int &value);
                int get_first();
                int get_last();
                int size();
                bool isEmpty();
                void prettyPrint();
        };
} // namespace LinkedList

#endif // LINKED_LIST_H_
