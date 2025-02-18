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

    // Call method to check if tree is an AVL Tree
    std::cout << "t.isAVL() = " << (t.isAVL() ? "true" : "false") << std::endl;

    return 0;
}


/*
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
*/