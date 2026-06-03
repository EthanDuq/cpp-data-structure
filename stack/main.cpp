#include <iostream>
#include "stack.hpp"

int main() {
        Stack::Stack<int> stack;
        int x{1}, y{2}, z{3};

        stack.prettyPrint();
        stack.push(x);
        stack.prettyPrint();
        stack.push(y);
        stack.push(z);
        stack.prettyPrint();

        int u;
        stack.peek(u);
        std::cout << "peek : " << u << "\n";
        std::cout << "size : " << stack.size() << "\n";
        stack.prettyPrint();
        stack.pop(u);
        std::cout << "pop : " << u << "\n";
        stack.prettyPrint();
        stack.pop(u);
        std::cout << "pop : " << u << "\n";
        stack.prettyPrint();
        stack.pop(u);
        std::cout << "pop : " << u << "\n";
        stack.prettyPrint();
        stack.pop(u);
        stack.prettyPrint();
}
