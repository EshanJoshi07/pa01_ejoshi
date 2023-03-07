// cards.h
//NAME: ESHAN JOSHI
// All class declarations go here


#ifndef CARDS_H
#define CARDS_H

class Cards {
    public:
        Cards();
        ~Cards();
        bool insert(int value);
        void printPreOrder() const;
        void printInOrder() const;
        void printPostOrder() const;
        int sum() const;
        int count() const;
        bool contains(int value) const;
        int getPredecessor(int value) const;
        int getSuccessor(int value) const;
        bool remove(int value);
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
        void clear(Node *n);
        bool insert(int value, Node *n);
        void printPreOrder(Node *n) const;
        void printInOrder(Node *n) const;
        void printPostOrder(Node *n) const;
        int sum(Node *n) const;
        int count(Node *n) const;
        Node* getSuccessorNode(int value) const;
        Node* getPredecessorNode(int value) const;

};

#endif
