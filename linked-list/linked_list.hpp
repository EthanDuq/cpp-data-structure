#ifndef LINKED_LIST_HPP_
#define LINKED_LIST_HPP_

#include <iostream>

namespace Linked_List {
        template <typename T>
        struct Node {
                T data;
                Node *next;

                Node(); // empty list
                Node(const T &value, Node *n = nullptr);
        }; // struct Node

        template <typename T>
        class LinkedList {
        private:
                Node<T> *root;
        public:
                LinkedList();
                ~LinkedList();
                bool insert(const T &value);
                bool remove(const T &value);
                T get_first();
                T get_last();
                int size();
                bool isEmpty();
                void prettyPrint();
        }; // class LinkedList


        // Node implementation
        template <typename T>
        Node<T>::Node() {
                data = T(); // T() default constructor
                next = nullptr;
        }

        template <typename T>
        Node<T>::Node(const T &value, Node *n) {
                data = value;
                next = n;
        }

        // LinkedList implementation
        template <typename T>
        LinkedList<T>::LinkedList() { root = nullptr; }

        template <typename T>
        LinkedList<T>::~LinkedList() {
                Node<T> *current { nullptr };
                while (root) {
                        current = root;
                        root = root->next;
                        delete current;
                }
        }

        template <typename T>
        bool LinkedList<T>::insert(const T &value) {
                if (!root) {
                        root = new Node<T>(value, nullptr);
                        return true;
                }

                Node<T> *current { root };
                while (current->next) {
                        current = current->next;
                }
                current->next = new Node<T>(value, nullptr);
                return true;
        }

        template <typename T>
        bool LinkedList<T>::remove(const T &value) {
                bool isDelete { false };
                Node<T> *previous { nullptr }, *current { root };
                while (current && (current->data != value)) {
                        previous = current;
                        current = current->next;
                }

                if (current && current->data == value) {
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

        template <typename T>
        T LinkedList<T>::get_first() {
                if (root) {
                        return root->data;
                } else {
                        std::cout << "Empty linked list, return \n";
                        return -1;
                }
        }

        template <typename T>
        T LinkedList<T>::get_last() {
                if (root) {
                        Node<T> *current { root };
                        while (current->next) {
                                current = current->next;
                        }
                        return current->data;
                } else {
                        std::cout << "Empty linked list, return -1\n";
                        return -1;
                }
        }

        template <typename T>
        int LinkedList<T>::size() {
                if (root) {
                        int size {};
                        Node<T> *current { root };
                        while (current) {
                                current = current->next;
                                size += 1;
                        }
                        return size;
                } else {
                        return 0;
                }
        }

        template <typename T>
        bool LinkedList<T>::isEmpty() {
                if (root) {
                        return false;
                } else {
                        return true;
                }
        }

        template <typename T>
        void LinkedList<T>::prettyPrint() {
                if (root) {
                        Node<T> *current{root};
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
} // namespace LinkedList

#endif // LINKED_LIST_HPP_
