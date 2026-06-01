#include "linked_list.h"
#include <iostream>

namespace Linked_List {

        // Node implementation
        Node::Node() {
                data = 0;
                next = nullptr;
        }

        Node::Node(int &value, Node *n) {
                data = value;
                next = n;
        }

        LinkedList::LinkedList() { root = nullptr; }

        LinkedList::~LinkedList() {
                Node *current { nullptr };
                while (root) {
                        current = root;
                        root = root->next;
                        delete current;
                }
        }

        bool LinkedList::insert(int &value) {
                if (!root) {
                        root = new Node(value, nullptr);
                        return true;
                }

                Node *current { root };
                while (current->next) {
                        current = current->next;
                }
                current->next = new Node(value, nullptr);
                return true;
        }

        bool LinkedList::remove(int &value) {
                bool isDelete { false };
                Node *previous { nullptr }, *current { root };
                while (current && (current->data != value)) {
                        previous = current;
                        current = current->next;
                }

                if (current->data == value) {
                        if (previous) {
                                previous->next = current->next;
                        } else {
                                root = current->next;
                        }
                        delete current;
                        isDelete = true;
                }
                return isDelete;
        }

        int LinkedList::get_first() {
                if (root) {
                        return root->data;
                } else {
                        std::cout << "Empty linked list, return \n";
                        return -1;
                }
        }

        int LinkedList::get_last() {
                if (root) {
                        Node *current { root };
                        while (current->next) {
                                current = current->next;
                        }
                        return current->data;
                } else {
                        std::cout << "Empty linked list, return -1\n";
                        return -1;
                }
        }

        int LinkedList::size() {
                if (root) {
                        int size {};
                        Node *current { root };
                        while (current) {
                                current = current->next;
                                size += 1;
                        }
                        return size;
                } else {
                        return 0;
                }
        }

        bool LinkedList::isEmpty() {
                if (root) {
                        return false;
                } else {
                        return true;
                }
        }

        void LinkedList::prettyPrint() {
                if (root) {
                        Node *current{root};
                        std::cout << "{ ";
                        while (current->next) {
                                std::cout << current->data << " -> ";
                                current = current->next;
                        }
                        std::cout << current->data << " }\n";
                } else {
                        std::cout << "This linked list is empty\n";
                }
        }
}
