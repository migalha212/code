#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename T>
class Stack {
public:
  Stack(){
    elements.clear();
  }
  size_t size() const{
    return elements.size();
  }
  bool peek(T& elem) const{
    if (elements.empty()) return false;
    elem = elements.back();
    return true;
  }
  bool pop(T& elem){
    if(!elements.size()) return false;
    elem = elements.back(); elements.pop_back(); return true;
  }
  void push(const T& elem){
    elements.push_back(elem);
  }
private:
  std::vector<T> elements;
};


