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

    // Read queries and print their result
    int q;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        std::cin >> x;
        std::cout << "t.balance(" << x << ") = " << t.balance(x) << std::endl;
    }

    return 0;
}

/*
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
};
*/