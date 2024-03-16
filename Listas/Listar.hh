#ifndef __LIST_HH__
#define __LIST_HH__

#include <iostream>

template<typename T>
class List {
private:
  class Node {
  private:
    Node* next_;
    T data_;
  public:
    Node() : next_(nullptr), data_(T()) {}
    Node(const T& d) : next_(nullptr), data_(d) {}
    void setNext(Node* p) { next_ = p; }
    Node* getNext() { return next_; }
    const T& getData() {
      return data_;
    }
  };
  
  // Attributes
  Node* first_;
  Node* last_;
  unsigned int size_;
public:
  
  List() : first_(nullptr), last_(nullptr), size_(0) {}
  
  unsigned int size() const { return size_; }
  
  bool empty() { 
    return first_ == nullptr;
  }

  void push_back(const T& elem) {
    Node* n = new Node(elem);
    if(empty()) {
      first_ = n;
    } else {
      last_->setNext(n);
    }
    last_ = n;
    size_++;
  }

  void push_front(const T& elem) {
    Node* n = new Node(elem);
    if(empty()) {
      first_ = n;
      last_ = n;
      size_++;
    } else {
      n->setNext(first_);
      first_ = n;
      size_++;
    }
  }

  void print() {
    if (empty()) {
      std::cout << "< >" << std::endl;
    }
    Node* p = first_;
    while(p != nullptr) {
      std::cout << "(" << p->getData() 
                << "-> " << p->getNext() 
                << ")" << std::endl;
      p = p->getNext();
    }
    std::cout << "-----" << std::endl; 
  }
};
#endif
listc.hh
Mostrando listc.hh.
