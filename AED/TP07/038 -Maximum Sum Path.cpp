//* for full implementation in practice check binaryTree.h

/*
std::string maxSum() {
    if (this->root == nullptr) return "";
    std::string lres = "L";
    std::string rres = "R";
    int left = maxSum(this->root->left, lres);
    int right = maxSum(this->root->right, rres);
    if (left > right) return lres;
    else return rres;
  }

  int maxSum(Node* n, std::string& res) {
    if (n == nullptr) return 0;
    if(n->right == nullptr && n->left == nullptr) return n->value;
    std::string lres = "L";
    std::string rres = "R";
    int left = maxSum(n->left, lres);
    int right = maxSum(n->right, rres);
    if(left > right) {
      res += lres;
      return left + n->value;
    }
    else{
      res += rres;
      return right + n->value;
    }
  }
*/