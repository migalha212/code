//* for full implementation in practice check binaryTree.h

/*int nodesLevel(int k){
      if (k == 0) return 1;
      else return nodesLevel(k - 1,this->root->left) + nodesLevel(k - 1,this->root->right); 
    }

    int nodesLevel(int k,Node* node){
      if (node == nullptr) return 0;
      if (k == 0) return 1;
      else return nodesLevel(k - 1, node->left) + nodesLevel(k - 1, node->right); 
    }*/