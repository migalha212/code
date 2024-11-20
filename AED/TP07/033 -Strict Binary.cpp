//* for full implementation in practice check binaryTree.h

/*
    bool strict(){
        if(this->root == nullptr) return true;
        if(this->root->left != nullptr && this->root->right != nullptr) return strict(this->root->left) && strict(this->root->right);
        return this->root->left == nullptr && this->root->right == nullptr;
    }

    bool strict(Node* node){
        if(node == nullptr) return true;
        if(node->left != nullptr && node->right != nullptr) return strict(node->left) && strict(node->right);
        return node->left == nullptr && node->right == nullptr;
    }
*/