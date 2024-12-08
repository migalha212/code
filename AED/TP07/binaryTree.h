// -------------------------------------------------------------
// Algoritmos e Estruturas de Dados 2024/2025 - LEIC (FCUP/FEUP)
// http://www.dcc.fc.up.pt/~pribeiro/aulas/aed2425/
// -------------------------------------------------------------
// Binary Tree
// Last update: 09/11/2024
// -------------------------------------------------------------

#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <queue>
#include <stack>

template <class T> class BTree
{
private:
  struct Node
  {
    T value;            // The value stored on the node
    Node* left, * right; // Pointers to left and right child
  };

  // The tree 
  Node* root;           // Pointer to the root node

public:

  // Constructor: initially the tree is empty
  BTree() {
    root = nullptr;
  }

  // Destructor: delete all nodes (garbage collection) [see slide 33]
  ~BTree() {
    destroy(root);
  }

  // Recursively delete left and right subtrees and then current node
  void destroy(Node* n) {
    if (n == nullptr) return;
    destroy(n->left);
    destroy(n->right);
    delete n;
  }


  // ---------------------------------------------------------
  // Count the number of nodes (see slides 13 and 14)
  // ---------------------------------------------------------

  int numberNodes() {
    return numberNodes(root);
  }

  int numberNodes(Node* n) {
    if (n == nullptr) return 0;
    return 1 + numberNodes(n->left) + numberNodes(n->right);
  }

  // ---------------------------------------------------------
  // Height of the tree (see slides 15 and 16)
  // ---------------------------------------------------------

  int height() {
    return height(root);
  }

  int height(Node* n) {
    if (n == nullptr) return -1;
    return 1 + std::max(height(n->left), height(n->right));
  }

  // ---------------------------------------------------------
  // Does the tree contain value 'val'? (see slides 17 and 18)
  // ---------------------------------------------------------

  bool contains(const T& val) {
    return contains(root, val);
  }

  bool contains(Node* n, const T& val) {
    if (n == nullptr) return false;
    if (n->value == val) return true;
    return contains(n->left, val) || contains(n->right, val);
  }

  // ---------------------------------------------------------
  // Print tree in PreOrder (see slides 20 and 21)
  // ---------------------------------------------------------

  void printPreOrder() {
    std::cout << "PreOrder:";
    printPreOrder(root);
    std::cout << std::endl;
  }

  void printPreOrder(Node* n) {
    if (n == nullptr) return;
    std::cout << " " << n->value;
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in InOrder (see slides 22 and 23)
  // ---------------------------------------------------------

  void printInOrder() {
    std::cout << "InOrder:";
    printInOrder(root);
    std::cout << std::endl;
  }

  void printInOrder(Node* n) {
    if (n == nullptr) return;
    printInOrder(n->left);
    std::cout << " " << n->value;
    printInOrder(n->right);
  }

  // ---------------------------------------------------------
  // Print tree in PostOrder (see slides 22 and 24)
  // ---------------------------------------------------------

  void printPostOrder() {
    std::cout << "PostOrder:";
    printPostOrder(root);
    std::cout << std::endl;
  }

  void printPostOrder(Node* n) {
    if (n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    std::cout << " " << n->value;
  }

  // ---------------------------------------------------------
  // Print tree in Breadt-First order using a queue
  // (see slides 25, 26 and 27)
  // ---------------------------------------------------------

  void printBFS() {
    std::cout << "BFS:";

    std::queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      Node* cur = q.front();
      q.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        q.push(cur->left);
        q.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Print tree in Depth-First order using a stack
  // (see slides 28 and 29)
  // ---------------------------------------------------------

  void printDFS() {
    std::cout << "DFS:";

    std::stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      Node* cur = s.top();
      s.pop();
      if (cur != nullptr) {
        std::cout << " " << cur->value;
        s.push(cur->left);
        s.push(cur->right);
      }
    }

    std::cout << std::endl;
  }

  // ---------------------------------------------------------
  // Read a tree in PreOrder from standard input
  // (see slides 30, 31 and 32)
  // ---------------------------------------------------------

  void read(std::string null) {
    root = readNode(null);
  }

  Node* readNode(std::string null) {
    std::string buffer;
    std::cin >> buffer;
    if (buffer == null) return nullptr;
    Node* n = new Node;
    std::istringstream ss(buffer);
    ss >> n->value;
    n->left = readNode(null);
    n->right = readNode(null);
    return n;
  }

  // ---------------------------------------------------------
  // TODO: put the functions you need to implement below this
  // ---------------------------------------------------------

  int numberLeafs() {
    if (this->root == nullptr) return 0;
    if (this->root->left == nullptr && this->root->right == nullptr) return 1;
    return numberLeafs(this->root->left) + numberLeafs(this->root->right);
  }

  int numberLeafs(Node* node) {
    if (node == nullptr) return 0;
    if (node->left == nullptr && node->right == nullptr) return 1;
    return numberLeafs(node->left) + numberLeafs(node->right);
  }

  bool strict() {
    if (this->root == nullptr) return true;
    if (this->root->left != nullptr && this->root->right != nullptr) return strict(this->root->left) && strict(this->root->right);
    return this->root->left == nullptr && this->root->right == nullptr;
  }

  bool strict(Node* node) {
    if (node == nullptr) return true;
    if (node->left != nullptr && node->right != nullptr) return strict(node->left) && strict(node->right);
    return node->left == nullptr && node->right == nullptr;
  }

  T& path(std::string s) {
    if (s[0] == '_') return this->root->value;
    else if (s[0] == 'R') return path(s.substr(1), this->root->right);
    else if (s[0] == 'L') return path(s.substr(1), this->root->left);
    return root->value;
  }

  T& path(std::string s, Node* node) {
    if (s.empty()) return node->value;
    else if (s[0] == 'R') return path(s.substr(1), node->right);
    else if (s[0] == 'L') return path(s.substr(1), node->left);
    return node->value;
  }

  int nodesLevel(int k) {
    if (k == 0) return 1;
    else return nodesLevel(k - 1, this->root->left) + nodesLevel(k - 1, this->root->right);
  }

  int nodesLevel(int k, Node* node) {
    if (node == nullptr) return 0;
    if (k == 0) return 1;
    else return nodesLevel(k - 1, node->left) + nodesLevel(k - 1, node->right);
  }

  //* 36 literalmente só fazer uma dfs ou bfs
  int countEven() {
    int res = 0;
    std::stack<Node*> s;
    s.push(root);
    while (!s.empty()) {
      Node* cur = s.top();
      s.pop();
      if (cur != nullptr) {
        if (cur->value % 2 == 0) res++;
        s.push(cur->left);
        s.push(cur->right);
      }
    }
    return res;
  }

  //* 37
  std::vector<int> sumLevels() {
    std::vector<int> res(this->height() + 1);
    if (this->root != nullptr) {
      res[0] = this->root->value;
    }
    for (int i = this->height(); i > 0; i--) {
      res[i] = sumLevels(this->root->left, i - 1) + sumLevels(this->root->right, i - 1);
    }
    return res;
  }

  int sumLevels(Node* n, int level) {
    if (n == nullptr) return 0;
    if (level == 0) return n->value;
    else return sumLevels(n->left, level - 1) + sumLevels(n->right, level - 1);
  }

  //* 38
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
};



#endif