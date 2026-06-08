#ifndef HEAPMIN_H_
#define HEAPMIN_H_

#include "AbstractTree.hpp"

using TreeAbstract::Node;
using TreeAbstract::AbstractTree;

namespace MinHeap {
        template <typename T>
        class HeapMin: public AbstractTree<T> {
                private:
                        bool insert(Node<T> *&_node, T &_value);
                        bool exist(Node<T> *_node, T &_value);
                        bool remove(Node<T> *&_node, T &_value);

                public:
                        bool insert(T &_value) override { return insert(this->root, _value); }
                        bool remove(T &_value) override { return remove(this->root, _value); }
                        bool exist(T &_value) override { return exist(this->root, _value); }

        }; // class BST

        template <typename T> bool insert(Node<T> *&_node, T &_value) {}

        template <typename T> bool exist(Node<T> *_node, T &_value) {}

        template <typename T> bool remove(Node<T> *&_node, T &_value) {}


}; // namespace MinHeap

#endif // HEAPMIN_H_
