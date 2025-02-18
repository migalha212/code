//* for implementation of this exercise check TP08/binarySearchTree.h

#include <iostream>
#include <string>

#include "binarySearchTree.h"

int main() {
    BSTree<int> t;

    // Read tree by inserting numbers
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        t.insert(x);
    }

    // Read rotation asked and print before and after tree
    int x;
    std::cin >> x;
    t.printPreOrder();
    t.rightRotate(x);
    std::cout << "rightRotate(" << x << ")" << std::endl;
    t.printPreOrder();

    return 0;
}

/*
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
*/