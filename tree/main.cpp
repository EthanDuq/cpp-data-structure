#include <iostream>
#include "binary_search_tree.hpp"

using namespace BinarySearchTree;

int main() {
        BST<int> t;
        /*
         *            50
         *           /  \
         *         30    70
         *        /  \   / \
         *       20  40 60  80
         *      /        \
         *     10        65
         *
         */

        int vals[] = {50, 30, 70, 20, 40, 60, 80, 10, 65};
        for (int v : vals) { t.insert(v); }
        t.print_prefix();
        std::cout << "suppression de 60 puis 30\n";
        int x = 60;
        t.remove(x);
         /*
         *            50
         *           /  \
         *         30    70
         *        /  \   / \
         *       20  40 65  80
         *      /
         *     10
         *
         */
        t.print_prefix();
        x = 30;
        t.remove(x);

        /*
         *            50
         *           /  \
         *         40    70
         *        /      / \
         *       20     65  80
         *      /
         *     10
         *
         */

        t.print_prefix();

        std::cout << "suppression de 50\n";

        x = 50;
        t.remove(x);
        /*
         *            65
         *           /  \
         *         40    70
         *        /        \
         *       20        80
         *      /
         *     10
         *
         */

        t.print_prefix();

        std::cout << "ajout 68\n";

        x = 68;
        t.insert(x);
        t.print_prefix();

        return 0;
}
