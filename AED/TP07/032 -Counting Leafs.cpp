//* check binaryTree.h for full implementation of function in practice

/*

    int numberLeafs(){
        if(this->root == nullptr) return 0;
        if(this->root->left == nullptr && this->root->right == nullptr) return 1;
        return numberLeafs(this->root->left) + numberLeafs(this->root->right);
        }
        
    int numberLeafs(Node* node){
        if(node == nullptr) return 0;
        if(node->left == nullptr && node->right == nullptr) return 1;
        return numberLeafs(node->left) + numberLeafs(node->right);
    }

*/