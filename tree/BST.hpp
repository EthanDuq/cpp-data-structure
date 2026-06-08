#ifndef BINARY_SEARCH_TREE_H_
#define BINARY_SEARCH_TREE_H_

#include "AbstractTree.hpp"

using TreeAbstract::Node;
using TreeAbstract::AbstractTree;

namespace BinarySearchTree {
        template <typename T>
        class BST: public AbstractTree<T> {
                private:
                        bool insert(Node<T> *&_node, T &_value);
                        bool exist(Node<T> *_node, T &_value);
                        bool remove(Node<T> *&_node, T &_value);
                        Node<T> *detach_min(Node<T> *&_node);

                public:
                        virtual bool insert(T &_value) override { return insert(this->root, _value); }
                        virtual bool remove(T &_value) override { return remove(this->root, _value); }
                        virtual bool exist(T &_value) override { return exist(this->root, _value); }

        }; // class BST

        template <typename T>
        bool BST<T>::insert(Node<T> *&_node, T &_value) {
                if (!_node) {
                        _node = new Node<T>(_value);
                        return true;
                }

                if (_value < _node->value)
                        return insert(_node->left, _value);
                else if (_value > _node->value)
                        return insert(_node->right, _value);
                else return false;
        }

        template <typename T>
        Node<T> *BST<T>::detach_min(Node<T> *&_node) {
                if (!_node->left) {
                        Node<T> *min = _node;
                        _node = _node->right;
                        return min;
                }
                return detach_min(_node->left);
        }

        template <typename T>
        bool BST<T>::remove(Node<T> *&_node, T &_value) {
                if (!_node)
                        return false;

                if (_value < _node->value)
                        return remove(_node->left, _value);
                else if (_value > _node->value)
                        return remove(_node->right, _value);
                else {
                        if (!_node->left && !_node->right) {
                                delete _node;
                                _node = nullptr;
                        } else if (!_node->right) {
                                Node<T> *tmp = _node;
                                _node = _node->left;
                                tmp->left = nullptr;
                                delete tmp;
                        } else if (!_node->left) {
                                Node<T> *tmp = _node;
                                _node = _node->right;
                                tmp->right = nullptr;
                                delete tmp;
                        } else {
                                Node<T> *next = detach_min(_node->right);
                                _node->value = next->value;
                                next->left = next->right = nullptr;
                                delete next;
                        }
                        return true;
                }
        }

        template <typename T>
        bool BST<T>::exist(Node<T> *_node, T &_value) {
                if (!_node)
                        return false;

                if (_node->value == _value)
                        return true;
                else if (_value < _node->value)
                        return exist(_node->left, _value);
                else return exist(_node->right, _value);
        }


}; // namespace BinarySearchTree

#endif // BINARY_SEARCH_TREE_H_
