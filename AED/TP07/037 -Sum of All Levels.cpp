//* for full implementation in practice check binaryTree.h

/*
std::vector<int> sumLevels() {
    std::vector<int> res(this->height() + 1);
    if (this->root != nullptr) {
      res[0] = this->root->value;
    }
    for(int i = this->height(); i > 0; i--){
      res[i] = sumLevels(this->root->left,i - 1) + sumLevels(this->root->right,i - 1);
    }
    return res;
  }

  int sumLevels(Node *n,int level){
    if(n == nullptr) return 0;
    if(level == 0) return n->value;
    else return sumLevels(n->left, level - 1) + sumLevels(n->right, level - 1);
  }
*/