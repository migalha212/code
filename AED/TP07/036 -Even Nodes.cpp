//* for full implementation in practice check binaryTree.h

/*
int countEven(){
      int res = 0;
      std::stack<Node*> s;
      s.push(root);
      while (!s.empty()) {
        Node* cur = s.top();
        s.pop();
        if (cur != nullptr) {
        if(cur->value % 2 == 0) res++;
          s.push(cur->left);
          s.push(cur->right);
        }
      }
      return res;
    }
*/