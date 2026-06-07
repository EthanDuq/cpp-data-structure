#ifndef ABSTRACTTREE_H_
#define ABSTRACTTREE_H_

#include <iostream>
#include "TreeInterface.hpp"

namespace TreeAbstract {
        template <typename T>
        struct Node {
                T value;
                Node *left;
                Node *right;

                Node();
                Node(T &_value);
                Node(T &_value, Node<T> *_left, Node<T> *_right);
                ~Node();
        }; // struct Node

        template <typename T>
        class AbstractTree : public TreeInterface<T> {
                private:
                        void print_prefix(Node<T> *_node);

                protected:
                        Node<T> *root;

                public:
                        AbstractTree() { root = nullptr; }
                        AbstractTree(Node<T> *_root) { root = _root; }
                        virtual ~AbstractTree() { delete root; };
                        virtual bool insert(T &_value) = 0;
                        virtual bool remove(T &_value) = 0;
                        virtual bool exist(T &_value) = 0;
                        void print_prefix();
        }; // class AbstractTree

        // NODE IMPLEMENTATION

        template <typename T>
        Node<T>::Node() {
                value = T();
                left = nullptr;
                right = nullptr;
        }

        template <typename T>
        Node<T>::Node(T &_value) {
                value = _value;
                left = nullptr;
                right = nullptr;
        }

        template <typename T>
        Node<T>::Node(T &_value, Node<T> *_left, Node<T> *_right) {
                value = _value;
                left = _left;
                right = _right;
        }

        template <typename T>
        Node<T>::~Node() {
                delete left;
                left = nullptr;
                delete right;
                right = nullptr;
                value = T();
        }

        // PUBLIC FUNCTION

        template <typename T>
        void AbstractTree<T>::print_prefix() {
                std::cout << "[ ";
                print_prefix(root);
                std::cout << "]\n";
        }

        template <typename T>
        void AbstractTree<T>::print_prefix(Node<T> *_node) {
                if (!_node) return;
                if (_node->left)
                        print_prefix(_node->left);
                std::cout << _node->value << " ";
                if (_node->right)
                        print_prefix(_node->right);
        }
}; // namespace

#endif // ABSTRACTTREE_H_
