// intbst.cpp
// Implements class IntBST
// Satvik Balakrishnan, 01/30/2026

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
    root = nullptr;
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n == nullptr) return;

    clear(n->left);
    clear(n->right);
    delete n;

}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    if(root == nullptr){
        root = new Node(value);
        root->parent = nullptr;
        return true;
    }

    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if(n->info == value) return false;

    if(value < n->info){
        if(n->left == nullptr){
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
        return insert(value, n->left);
    }

    else{
        if(n->right == nullptr){
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
        return insert(value, n->right);
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
    cout << endl;
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(n==nullptr) return;

    cout<<n->info<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
    cout << endl;
}

void IntBST::printInOrder(Node *n) const {
    if(n==nullptr) return;

    printInOrder(n->left);
    cout<<n->info<< " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
    cout << endl;
}

void IntBST::printPostOrder(Node *n) const {
    if(n==nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);

    cout<<n->info<<" ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n==nullptr) return 0;
    return sum(n->left) + n->info + sum(n->right);
}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n==nullptr) return 0;
    return 1 + count(n->left) + count(n->right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n==nullptr) return nullptr;
    if(n->info == value) return n;

    if(value<n->info) return getNodeFor(value, n->left);
    else return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root)==nullptr) return false;
    else return true;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* curr = getNodeFor(value, root);
    if(curr == nullptr) return nullptr;

    if(curr->left != nullptr){
        curr=curr->left;

        while(curr->right!=nullptr){
            curr=curr->right;
        }
        return curr;
    }

    Node* p = curr->parent;
    while(p != nullptr && curr==p->left){
        curr=p;
        p = p->parent;
    }

    return p;

}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node* temp = getPredecessorNode(value);
    if(temp == nullptr) return 0;
    else return temp->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* curr = getNodeFor(value, root);
    if(curr == nullptr) return nullptr;

    if(curr->right != nullptr){
        curr = curr->right;
        while(curr->left != nullptr){
            curr = curr->left;
        }

        return curr;
    }

    Node* p = curr->parent;

    while(p != nullptr && curr == p->right){
        curr = p;
        p = p->parent;
    }

    return p;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node* temp = getSuccessorNode(value);
    if (temp == nullptr) return 0;
    else return temp->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if(n==nullptr) return false;

    if(n->left!=nullptr && n->right!=nullptr){
        Node* s = getSuccessorNode(n->info);
        n->info = s->info;
        n = s;
    }

    Node* child = (n->left != nullptr) ? n->left : n->right;

    if (child != nullptr) {
        child->parent = n->parent;
    }

    if (n->parent == nullptr) {
        root = child;
    }
   
    else if (n == n->parent->left) {
        n->parent->left = child;
    }

    else {
        n->parent->right = child;
    }

    delete n;
    return true;

}
