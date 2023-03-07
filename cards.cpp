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
// void Cards::printInOrder(Node *n) const {
//     if (n == NULL){
//         return;
//     }
//     printInOrder(n->left);
//     cout << n->info << " ";
//     printInOrder(n->right);
// }

// //printPostOrder
// void Cards::printPostOrder() const {
//     Node *n = root;
//     printPostOrder(n);
// }

// //printPostOrder helper --> recursive
// void Cards::printPostOrder(Node *n) const {
//     if (n == NULL){
//         return;
//     }
//     printPostOrder(n->left);
//     printPostOrder(n->right);
//     cout << n->info << " ";
//     // IMPLEMENT HERE
// }

// int Cards::sum() const {
//     Node *n = root;
//     return sum(n);
// }

// //sum helper --> recursive
// int Cards::sum(Node *n) const {
//     if (n == NULL){
//         return 0;
//     }
//     return (n->info + sum(n->left) + sum(n->right));
// }

// //counter
// int Cards::count() const {
//     Node *n = root;
//     return count(n);
// }

// //counter hlper --> recurvsive
// int Cards::count(Node *n) const {
//     if (n == NULL){
//         return 0;
//     }
//     return (1 + count(n->left) + count(n->right));
// }

// // Parameters:
// // int value: the value to be found
// // Node* n: the node to start with (for a recursive call)
// // Whenever you call this method from somewhere else, pass it
// // the root node as "n"
// Cards::Node* Cards::getNodeFor(int value, Node* n) const{
//     if(n==NULL){
//         return NULL;
//     }
//     else if(n->info==value){
//         return n;
//     }
//     else if(n->left==NULL && n->right==NULL){
//         return NULL;
//     }
//     else{
//         if(n->info>value){
//             return getNodeFor(value,n->left);
//         }
//         else{
//             return getNodeFor(value,n->right);
//         }
//     }
//     // REPLACE THIS NON-SOLUTION
// }

// // returns true if value is in the tree; false if not
// bool Cards::contains(int value) const {
    
//     return getNodeFor(value,root)!= NULL;//IS THIS ALLOWED?

//      // REPLACE THIS NON-SOLUTION
// }

// // returns the Node containing the predecessor of the given value
// Cards::Node* Cards::getPredecessorNode(int value) const{
//     Node* loc = getNodeFor(value,root);
//     Node* smallest = root;
//     while(smallest->left){
//         smallest = smallest->left;
//     }
//     if(loc==smallest){
//         return 0;
//     }
//     else{
//         if(loc->left){
//             loc=loc->left;
//             while(loc->right){
//                 loc=loc->right;
//             }
//         }
//         /*else if(loc->right){
//             loc=loc->right;
//             while(loc->left){
//                 loc=loc->left;
//             }
//         }*/
//         else{
//             while(loc->parent){
//                 if(loc->parent->right==loc){
//                     return loc->parent;
//                 }
//                 loc=loc->parent;
//             }
//         }
//         return loc;
//         //return loc;
        
//     }
    
// }

// // returns the predecessor value of the given value or 0 if there is none
// int Cards::getPredecessor(int value) const{
//     if(getPredecessorNode(value)==NULL){
//         return 0;
//     }
//     else{
//         return getPredecessorNode(value)->info; //IS THIS ALLOWED?
//     }
// }

// // returns the Node containing the successor of the given value
// Cards::Node* Cards::getSuccessorNode(int value) const{
    
//     Node* loc = getNodeFor(value,root);
//     Node* largest = root;
//     while(largest->right){
//         largest = largest->right;
//     }
//     if(loc==largest){
//         return 0;
//     }
//     else{
//         if(loc->right){
//             loc=loc->right;
//             while(loc->left){
//                 loc=loc->left;
//             }
//         }
//         else{
//             while(loc->parent){
//                 if(loc->parent->left==loc){
//                     return loc->parent;
//                 }
//                 loc=loc->parent;
//             }
//             /*loc=loc->parent;
//             while(loc->left==NULL){
//                 loc=loc->parent;
//             }*/
            
//         }
//         return loc;
        
//     }
//      // REPLACE THIS NON-SOLUTION
// }

// // returns the successor value of the given value or 0 if there is none
// int Cards::getSuccessor(int value) const{
//     if(getSuccessorNode(value)==NULL){
//         return 0;
//     }
//     else{
//         return getSuccessorNode(value)->info;
//     }
//     //IS THIS ALLOWED?
// }

// // deletes the Node containing the given value from the tree
// // returns true if the node exist and was deleted or false if the node does not exist
// bool Cards::remove(int value){
//     Node* loc = getNodeFor(value,root);
//     if(loc==NULL){
//         return false;
//     }
//     if(loc->left==NULL && loc->right==NULL){
//         if(loc==root){
//             root = NULL;
//         }
//         else if(loc->parent->left==loc){
//             loc->parent->left=NULL;
//         }
//         else{
//             loc->parent->right=NULL;
//         }
//         delete loc;
//         return true;
//     }
//     else if(loc->left && loc->right){
//         int val = getPredecessor(loc->info);//getSuccessor
//         remove(getPredecessor(loc->info));
//         loc->info=val;

//         return true; // REPLACE THIS NON-SOLUTION
//     }
//     else{
//         Node* child;
//         if(loc->left){
//             child = loc->left;
//         }
//         else{
//             child = loc->right;
//         }
//         if(loc!=root){
//             if(loc->parent->left==loc){
//                 loc->parent->left=child;
//             }
//             else{
//                 loc->parent->right=child;
//             }
//             child->parent=loc->parent;
//         }
//         else{
//             root=child;
//         }
//         delete loc;
//         return true;
//     }

// }

// //left side has larger values
// int Cards::minValue() const{
//     Node *min = root;
//     while(min->left){
//         min = min->left;
//     }
//     return min->info;
// }

// //right side has larger values
// int Cards::maxValue() const {
//     Node *max = root;
//     while(max->right){
//         max = max->right;
//     }
//     return max->info;
// }








// Cards::Cards() : root(nullptr) { }

// destructor deletes all nodes
// Cards::~Cards() {
//     clear(root);
// }

// recursive helper for destructor
// void Cards::clear(Node *n) {
//     if (n) {
// 	clear(n->left);
// 	clear(n->right);
// 	delete n;
//     }
// }


// insert value in tree; return false if duplicate
// bool Cards::insert(int value) {
//     // handle special case of empty tree first
//     if (!root) {
// 	root = new Node(value);
// 	return true;
//     }
//     // otherwise use recursive helper
//     return insert(value, root);
// }

// recursive helper for insert (assumes n is never 0)
// bool Cards::insert(int value, Node *n) {
//     if (value == n->info)
// 	return false;
//     if (value < n->info) {
// 	if (n->left)
// 	    return insert(value, n->left);
// 	else {
// 	    n->left = new Node(value);
// 	    n->left->parent = n;
// 	    return true;
// 	}
//     }
//     else {
// 	if (n->right)
// 	    return insert(value, n->right);
// 	else {
// 	    n->right = new Node(value);
// 	    n->right->parent = n;
// 	    return true;
// 	}
//     }
// }

// // print tree data pre-order
// void Cards::printPreOrder() const {
//     printPreOrder(root);
// }

// recursive helper for printPreOrder()
// void Cards::printPreOrder(Node *n) const {
//     if (n) {
// 	cout << n->info << " ";
// 	printPreOrder(n->left);
// 	printPreOrder(n->right);
//     }
// }

// print tree data in-order, with helper
// void Cards::printInOrder() const {
//     printInOrder(root);
// }
void Cards::printInOrder(Node *n) const {
    if(n==NULL){
        return;
    }
    printInOrder(n->left);
    cout << n->info << " ";
    printInOrder(n->right);

    // IMPLEMENT HERE
}

// prints tree data post-order, with helper
void Cards::printPostOrder() const {
    printPostOrder(root);
}

void Cards::printPostOrder(Node *n) const {
    if(n==NULL){
        return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
    // IMPLEMENT HERE
}

// return sum of values in tree
int Cards::sum() const {
    return sum(root);
}

// recursive helper for sum
int Cards::sum(Node *n) const {
    if(n==NULL){
        return 0;
    }
    else{
        return n->info+sum(n->left)+sum(n->right);
    }
    // REPLACE THIS NON-SOLUTION
}

// return count of values
int Cards::count() const {
    return count(root);
}

// recursive helper for count
int Cards::count(Node *n) const {
    if(n==NULL){
        return 0;
    }
    else{
        return 1+count(n->left)+count(n->right);
    }
    // REPLACE THIS NON-SOLUTION
}

// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
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

// returns true if value is in the tree; false if not
bool Cards::contains(int value) const {
    
    return getNodeFor(value,root)!=NULL;//IS THIS ALLOWED?

     // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
Cards::Node* Cards::getPredecessorNode(int value) const{
    Node* loc = getNodeFor(value,root);
    Node* smallest = root;
    while(smallest->left){
        smallest = smallest->left;
    }
    if(loc==smallest){
        return 0;
    }
    else{
        if(loc->left){
            loc=loc->left;
            while(loc->right){
                loc=loc->right;
            }
        }
        /*else if(loc->right){
            loc=loc->right;
            while(loc->left){
                loc=loc->left;
            }
        }*/
        else{
            while(loc->parent){
                if(loc->parent->right==loc){
                    return loc->parent;
                }
                loc=loc->parent;
            }
        }
        return loc;
        //return loc;
        
    }
    
}

// returns the predecessor value of the given value or 0 if there is none
int Cards::getPredecessor(int value) const{
    if(getPredecessorNode(value)==NULL){
        return 0;
    }
    else{
        return getPredecessorNode(value)->info; //IS THIS ALLOWED?
    }
}

// returns the Node containing the successor of the given value
Cards::Node* Cards::getSuccessorNode(int value) const{
    
    Node* loc = getNodeFor(value,root);
    Node* largest = root;
    while(largest->right){
        largest = largest->right;
    }
    if(loc==largest){
        return 0;
    }
    else{
        if(loc->right){
            loc=loc->right;
            while(loc->left){
                loc=loc->left;
            }
        }
        else{
            while(loc->parent){
                if(loc->parent->left==loc){
                    return loc->parent;
                }
                loc=loc->parent;
            }
            /*loc=loc->parent;
            while(loc->left==NULL){
                loc=loc->parent;
            }*/
            
        }
        return loc;
        
    }
     // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int Cards::getSuccessor(int value) const{
    if(getSuccessorNode(value)==NULL){
        return 0;
    }
    else{
        return getSuccessorNode(value)->info;
    }
    //IS THIS ALLOWED?
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool Cards::remove(int value){
    Node* loc = getNodeFor(value,root);
    if(loc==NULL){
        return false;
    }
    if(loc->left==NULL && loc->right==NULL){
        if(loc==root){
            root = NULL;
        }
        else if(loc->parent->left==loc){
            loc->parent->left=NULL;
        }
        else{
            loc->parent->right=NULL;
        }
        delete loc;
        return true;
    }
    else if(loc->left && loc->right){
        int val = getPredecessor(loc->info);//getSuccessor
        remove(getPredecessor(loc->info));
        loc->info=val;

        return true; // REPLACE THIS NON-SOLUTION
    }
    else{
        Node* child;
        if(loc->left){
            child = loc->left;
        }
        else{
            child = loc->right;
        }
        if(loc!=root){
            if(loc->parent->left==loc){
                loc->parent->left=child;
            }
            else{
                loc->parent->right=child;
            }
            child->parent=loc->parent;
        }
        else{
            root=child;
        }
        delete loc;
        return true;
    }

}

int Cards::minValue() const{
    Node* val=root;
    while(val->left){
        val=val->left;
    }
    return val->info;
}
int Cards::maxValue() const {
    Node* val=root;
    while(val->right){
        val=val->right;
    }
    return val->info;
}