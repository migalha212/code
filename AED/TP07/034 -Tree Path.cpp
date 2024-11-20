//* for full implementation in practice check binaryTree.h


/*
    T & path(std::string s){
        if(s[0] == '_') return this->root->value;
        else if(s[0] == 'R') return path(s.substr(1),this->root->right);
        else if(s[0] == 'L') return path(s.substr(1),this->root->left);
        return root->value;
    }

    T & path(std::string s,Node* node){
        if(s.empty()) return node->value;
        else if(s[0] == 'R') return path(s.substr(1),node->right);
        else if(s[0] == 'L') return path(s.substr(1),node->left);
        return node->value;
    }
*/