#include "intbst.h"
#include <iostream>
using namespace std;

int main() {
    IntBST t;

    // insert
    t.insert(64);
    t.insert(32);
    t.insert(96);
    t.insert(16);
    t.insert(48);
    t.insert(80);
    t.insert(112);

    // traversals
    cout << "Preorder: ";
    t.printPreOrder();

    cout << "Inorder: ";
    t.printInOrder();

    cout << "Postorder: ";
    t.printPostOrder();

    // sum & count
    cout << "Sum: " << t.sum() << endl;
    cout << "Count: " << t.count() << endl;

    // contains
    cout << "Contains 48? " << t.contains(48) << endl;
    cout << "Contains 99? " << t.contains(99) << endl;

    // predecessor / successor
    cout << "Predecessor of 64: " << t.getPredecessor(64) << endl;
    cout << "Successor of 64: " << t.getSuccessor(64) << endl;

    // remove
    t.remove(32);
    cout << "After removing 32 (inorder): ";
    t.printInOrder();

    return 0;
}
