// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Binary Search Tree
// Last update: 16/11/2024
// -------------------------------------------------------------

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

template <class T> class BSTree
{
private:
    struct Node
    {
        T value;            // The value stored on the node
        Node* left, * right; // Pointers to left and right child
    };

    Node* root;

public:

    // Constructor: initially the tree is empty
    BSTree() {
        root = nullptr;
    }

    // Destructor: delete all nodes (garbage collection)
    ~BSTree() {
        destroy(root);
    }

    // Recursively delete left and right subtrees and then current node
    void destroy(Node* n) {
        if (n == nullptr) return;
        destroy(n->left);
        destroy(n->right);
        delete n;
    }

    // ---------------------------------------------------------
    // Count the number of nodes
    // ---------------------------------------------------------

    int numberNodes() {
        return numberNodes(root);
    }

    int numberNodes(Node* n) {
        if (n == nullptr) return 0;
        return 1 + numberNodes(n->left) + numberNodes(n->right);
    }

    // ---------------------------------------------------------
    // Height of the tree
    // ---------------------------------------------------------

    int height() {
        return height(root);
    }

    int height(Node* n) {
        if (n == nullptr) return -1;
        return 1 + std::max(height(n->left), height(n->right));
    }

    // ---------------------------------------------------------
    // Does the tree contain value 'val' ?
    // ---------------------------------------------------------

    bool contains(const T& val) {
        return contains(root, val);
    }

    bool contains(Node* n, const T& val) {
        if (n == nullptr) return false;
        if (val < n->value) return contains(n->left, val);
        if (val > n->value) return contains(n->right, val);
        return true;
    }

    // ---------------------------------------------------------
    // Insert value 'val' in the tree
    // ---------------------------------------------------------

    bool insert(const T& val) {
        if (contains(val)) return false;
        root = insert(root, val);
        return true;
    }

    Node* insert(Node* n, const T& val) {
        if (n == nullptr) {
            Node* aux = new Node;
            aux->value = val;
            aux->left = aux->right = nullptr;
            return aux;
        }
        else if (val < n->value) {
            n->left = insert(n->left, val);
        }
        else if (val > n->value) {
            n->right = insert(n->right, val);
        }
        return n;
    }

    // ---------------------------------------------------------
    // Remove value 'val' from the tree
    // ---------------------------------------------------------

    bool remove(const T& val) {
        if (!contains(val)) return false;
        root = remove(root, val);
        return true;
    }

    Node* remove(Node* n, const T& val) {
        if (val < n->value) n->left = remove(n->left, val);
        if (val > n->value) n->right = remove(n->right, val);
        else if (n->left == nullptr) {
            Node* tmp = n->right;
            delete n;
            return tmp;
        }
        else if (n->right == nullptr) {
            Node* tmp = n->left;
            delete n;
            return tmp;
        }
        else {
            Node* max = n->left;
            while (max->right != nullptr) max = max->right;
            n->value = max->value;
            n->left = remove(n->left, max->value);
        }
        return n;
    }

    // ---------------------------------------------------------
    // Print tree in preorder, incluing N for the null values
    // ---------------------------------------------------------  

    void printPreOrder() {
        std::cout << "preOrder:";
        printPreOrder(root);
        std::cout << std::endl;
    }

    void printPreOrder(Node* n) {
        if (n == nullptr)
            std::cout << " N";
        else {
            std::cout << " " << n->value;
            printPreOrder(n->left);
            printPreOrder(n->right);
        }
    }

    // ---------------------------------------------------------
    // TODO: put the functions you need to implement below this
    // ---------------------------------------------------------

    //* 45
    int balance(const T& val){
        return balance(this->root,val);
    }

    int balance(Node* n,const T&val){
        if(n == nullptr) return 0;
        if(n->value == val){
            return height(n->right) - height(n->left);
        }
        else{
            return balance(n->right,val) + balance(n->left,val);
        }
    }


    //* 46
    bool isAVL(){
        return isAVL(this->root);
    }

    bool isAVL(Node* n){
        if(n == nullptr) return true;
        if(abs(height(n->left) - height(n->right)) > 1 ){
            return false;
        }
        else{
            return isAVL(n->left) && isAVL(n->right);
        }

    }

    //* 47
    void rightRotate(const T& x){
        if(this->root->value == x){
            Node* temp = this->root->left;
            this->root->left = temp->right;
            temp->right = this->root;
            this->root = temp;
        }
        else{
        this->root->left = rightRotate(this->root->left,x);
        this->root->right =  rightRotate(this->root->right,x);
        }
    }

    Node* rightRotate(Node* n, const T& x){
        Node* temp = n;
        if(n == nullptr) return n;// base case
        if(n->value == x){
            if(n->left == nullptr) return n; //if transformation is not possible
            temp = n->left;
            n->left = temp->right; 
            temp->right = n;
        }
        else{
            n->left =  rightRotate(n->left,x);
            n->right =  rightRotate(n->right,x);
        }
        return temp;
    }
};



#endif