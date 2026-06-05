#include <iostream>

namespace BinarySearchTree {

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
        class Tree {
                private:
                        Node<T> *root;
                        bool insert(Node<T> *&_node, T &_value);
                        bool exist(Node<T> *_node, T &_value);
                        bool remove(Node<T> *&_node, T &_value);
                        Node<T> *detach_min(Node<T> *&_node);
                        void print_prefix(Node<T> *_node);
                public:
                        Tree();
                        Tree(Node<T> *_root);
                        ~Tree();
                        bool insert(T &_value);
                        bool remove(T &_value);
                        bool exist(T &_value);
                        void print_prefix();
        }; // class Tree

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

        template <typename T> Tree<T>::Tree() { root = nullptr; }
        template <typename T> Tree<T>::Tree(Node<T> *_root) { root = _root; }

        template <typename T>
        Tree<T>::~Tree() {
                delete root;
                root = nullptr;
        }

        template <typename T> bool Tree<T>::insert(T &_value) { return insert(root, _value); }

        template <typename T>
        bool Tree<T>::insert(Node<T> *&_node, T &_value) {
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
        Node<T> *Tree<T>::detach_min(Node<T> *&_node) {
                if (!_node->left) {
                        Node<T> *min = _node;
                        _node = _node->right;
                        return min;
                }
                return detach_min(_node->left);
        }

        template <typename T>
        bool Tree<T>::remove(T &_value) {
                return remove(root, _value);
        }

        template <typename T>
        bool Tree<T>::remove(Node<T> *&_node, T &_value) {
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
        bool Tree<T>::exist(T &_value) {
                return exist(root, _value);
        }

        template <typename T>
        bool Tree<T>::exist(Node<T> *_node, T &_value) {
                if (!_node)
                        return false;

                if (_node->value == _value)
                        return true;
                else if (_value < _node->value)
                        return exist(_node->left, _value);
                else return exist(_node->right, _value);
        }

        template <typename T>
        void Tree<T>::print_prefix() {
                std::cout << "[ ";
                print_prefix(root);
                std::cout << "]\n";
        }

        template <typename T>
        void Tree<T>::print_prefix(Node<T> *_node) {
                if (!_node) return;
                if (_node->left)
                        print_prefix(_node->left);
                std::cout << _node->value << " ";
                if (_node->right)
                        print_prefix(_node->right);
        }
} // namespace BinaryTree
