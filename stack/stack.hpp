#ifndef STACK_H_
#define STACK_H_

#include <iostream>

namespace Stack {
        template <typename T>
        class Stack {
                private:
                        T *stack;
                        int index;
                        int capacity;

                public:
                        Stack(int _capacity = 50);
                        ~Stack();
                        bool push(const T &value);
                        bool pop(T &out);
                        bool peek(T &out);
                        int size();
                        bool isEmpty();
                        void prettyPrint();
        }; // class Stack

        template <typename T>
        Stack<T>::Stack(int _capacity) {
                capacity = _capacity;
                index = -1;
                stack = new T[capacity];
        }

        template <typename T>
        Stack<T>::~Stack() {
                delete[] stack;
                stack = nullptr;
                index = -1;
                capacity = 0;
        }

        template <typename T>
        bool Stack<T>::push(const T &value) {
                bool isPush = false;
                if ((index + 1) < capacity) {
                        index++;
                        stack[index] = value;
                        isPush = true;
                }
                return isPush;
        }

        template <typename T>
        bool Stack<T>::pop(T &out) {
                bool isPop = false;
                if (index >= 0) {
                        out = stack[index];
                        index--;
                        isPop = true;
                }
                return isPop;
        }

        template <typename T>
        bool Stack<T>::peek(T &out) {
                bool isPeek = false;
                if (index >= 0) {
                        out = stack[index];
                        isPeek = true;
                }
                return isPeek;
        }

        template <typename T> int Stack<T>::size() { return index + 1; }
        template <typename T> bool Stack<T>::isEmpty() { return index == -1; }

        template <typename T>
        void Stack<T>::prettyPrint() {
                if (index >= 0) {
                        int current = {index};
                        std::cout << "{ ";
                        while (current > 0) {
                                std::cout << stack[current] << ", ";
                                current--;
                        }
                        std::cout << stack[current] << " }\n";
                } else {
                        std::cout << "Empty stack\n";
                }

        }
} // namespace stack

#endif // STACK_H_
