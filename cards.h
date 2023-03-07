// cards.h
//NAME: ESHAN JOSHI
// All class declarations go here


#ifndef CARDS_H
#define CARDS_H

class Cards {
    public:
    //constructor
    Cards();
    ~Cards();
    bool insert(int value);
    void printPreOrder() const; // prints tree data pre-order to cout

    // 8 METHODS YOU MUST IMPLEMENT in Cards.cpp:
    void printInOrder() const;       // print tree data in-order to cout
    void printPostOrder() const;     // print tree data post-order to cout
    int sum() const;                 // sum of all values
    int count() const;               // count of values
    bool contains(int value) const;  // true if value is in tree

    // THESE ARE HARDER! DO THESE LAST
    int getPredecessor(int value) const;       // returns the predecessor value of the given value or 0 if there is none
    int getSuccessor(int value) const;         // returns the successor value of the given value or 0 if there is none
    bool remove(int value);                    // deletes the Node containing the given value from the tree

    int minVal() const;
    int maxVal() const;
    
    private:
        struct Node {
            int info;
            Node *left, *right, *parent;
            Node (int v = 0) : info(v), left(0), right(0), parent(0) {}
        };

        Node *root;
        Node* getNodeFor(int value, Node* n) const;

        void clear(Node *n); //destructor helper
        bool insert(int value, Node *n); //insert helper function
        void printPreOrder(Node *n) const;
        void printInOrder(Node *n) const;
        void printPostOrder(Node *n) const;
        int sum(Node *n) const;
        int count(Node *n) const;

        Node* getSuccessorNode(int value) const;
        Node* getPredecessorNode(int value) const;

};

#endif
