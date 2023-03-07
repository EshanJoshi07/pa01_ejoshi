// cards.cpp
// NAME: ESHAN JOSHI
// Implementation of the classes defined in cards.h

#include <iostream>
#include <fstream>
#include <string>

#include "cards.h"

using namespace std;

//constructor --> set the root as null
Cards::Cards() {
    root = nullptr;
}

// // // destructor deletes all nodes
Cards::~Cards() {
    clear(root);
}

// // //destructor helper --> recrusive 
void Cards::clear(Node *n) {
    if (n) {
	    clear(n->left);
	    clear(n->right);
	    delete n;
    }
}

//insert value in tree; return false if duplicate
bool Cards::insert(int value) {

    //check if tree is empty
    if (!root) {
	    root = new Node(value);
	    return true;
    }

    return insert(value, root);
}

// //insert helper (assumes n is never 0) --> recrusive 
bool Cards::insert(int value, Node *n) {
    //check if value = n->info
    if (value == n->info)
	    return false;

    //check if value <n->info --> if value is less also check the left node
    if (value < n->info) {
	    if (n->left) {
	        return insert(value, n->left);
        }
	    else {
	        n->left = new Node(value);
	        n->left->parent = n;
	        return true;
	    }
    }

    //check if value>n->info --> if value is greater also check the left node
    else {
	    if (n->right) {
	        return insert(value, n->right);
        }
	    else {
	        n->right = new Node(value);
	        n->right->parent = n;
	        return true;
	    }
    }
}

//printPreOrder
void Cards::printPreOrder() const {
    Node *n = root;
    printPreOrder(n);
}

//printPreOrder helper --> recursive 
void Cards::printPreOrder(Node *n) const {
    if (n) {
	    cout << n->info << " ";
	    printPreOrder(n->left);
	    printPreOrder(n->right);
    }
}

//printInOrder
void Cards::printInOrder() const {
    Node *n = root;
    printInOrder(n);
}

// //printInOrder helper --> recursive
void Cards::printInOrder(Node *n) const {
    if (n == NULL){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);
}

//printPostOrder
void Cards::printPostOrder() const {
    Node *n = root;
    printPostOrder(n);
}

//printPostOrder helper --> recursive
void Cards::printPostOrder(Node *n) const {
    if (n == NULL){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

int Cards::sum() const {
    Node *n = root;
    return sum(n);
}

// //sum helper --> recursive
int Cards::sum(Node *n) const {
    if (n == NULL){
        return 0;
    }
    return (n->info + sum(n->left) + sum(n->right));
}

// //counter
int Cards::count() const {
    Node *n = root;
    return count(n);
}

//counter hlper --> recurvsive
int Cards::count(Node *n) const {
    if (n == NULL){
        return 0;
    }
    return (1 + count(n->left) + count(n->right));
}

// // Parameters:
// // int value: the value to be found
// // Node* n: the node to start with (for a recursive call)
// // Whenever you call this method from somewhere else, pass it
// // the root node as "n"
Cards::Node* Cards::getNodeFor(int value, Node* n) const{
    if(n==NULL){
        return NULL;
    }
    else if(n->info==value){
        return n;
    }
    else if(n->left==NULL && n->right==NULL){
        return NULL;
    }
    else{
        if(n->info>value){
            return getNodeFor(value,n->left);
        }
        else{
            return getNodeFor(value,n->right);
        }
    }
    // REPLACE THIS NON-SOLUTION
}

// // returns true if value is in the tree; false if not
bool Cards::contains(int value) const {
    
    return getNodeFor(value,root)!= NULL;//IS THIS ALLOWED?

     // REPLACE THIS NON-SOLUTION
}

// // returns the Node containing the predecessor of the given value
Cards::Node* Cards::getPredecessorNode(int value) const{
    Node* temp = getNodeFor(value,root);
    Node* min = root;
    while (min->left){
        min = min->left;
    }
    if (temp == min){
        return 0;
    }
    else {
        if (temp->left){
            temp = temp->left;
            while (temp->right) {
                temp = temp->right;
            }
        }
        else {
            while (temp->parent) {
                if (temp->parent->right == temp){
                    return temp->parent;
                }
                temp = temp->parent;
            }
        }
        return temp;
    }
    
}

// // returns the predecessor value of the given value or 0 if there is none
int Cards::getPredecessor(int value) const{
    if (getPredecessorNode(value) == NULL) {
        return 0;
    }
    else {
        return (getPredecessorNode(value))->info;
    }
}

// // returns the Node containing the successor of the given value
Cards::Node* Cards::getSuccessorNode(int value) const{
    
    Node* temp = getNodeFor(value,root);
    Node* max = root;
    while (max->right) {
        max = max->right;
    }
    if (temp == max) {
        return 0;
    }
    else {
        if (temp->right) {
            temp = temp->right;
            while (temp->left) {
                temp = temp->left;
            }
        }
        else {
            while (temp->parent) {
                if (temp->parent->left == temp) {
                    return temp->parent;
                }
                temp = temp->parent;
            }
            
        }
        return temp;
    }
    // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int Cards::getSuccessor(int value) const{
    if (getSuccessorNode(value) == NULL) {
        return 0;
    }
    else {
        return (getSuccessorNode(value))->info;
    }
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool Cards::remove(int value){
    Node* temp = getNodeFor(value,root);
    if (temp == NULL) {
        return false;
    }
    if ((temp->left == NULL) && (temp->right == NULL)) {
        if (temp == root) {
            root = NULL;
        }
        else if (temp->parent->left == temp) {
            temp->parent->left = NULL;
        }
        else {
            temp->parent->right = NULL;
        }
        delete temp;
        return true;
    }
    else if (temp->left && temp->right) {
        int num = getPredecessor(temp->info);
        remove(getPredecessor(temp->info));
        temp->info = num;

        return true;
    }
    else{
        Node* c;
        if (temp->left) {
            c = temp->left;
        }
        else {
            c = temp->right;
        }
        if (temp != root) {
            if (temp->parent->left == temp) {
                temp->parent->left = c;
            }
            else {
                temp->parent->right = c;
            }
            c->parent = temp->parent;
        }
        else {
            root = c;
        }
        delete temp;
        return true;
    }
}

//left side has larger values
int Cards::minVal() const{
    Node *min = root;
    while (min->left) {
        min = min->left;
    }
    return (min->info);
}

// //right side has larger values
int Cards::maxVal() const {
    Node *max = root;
    while (max->right) {
        max = max->right;
    }
    return (max->info);
}



















// int Cards::maxVal() const {
//     Node* val=root;
//     while(val->right){
//         val=val->right;
//     }
//     return val->info;
// }