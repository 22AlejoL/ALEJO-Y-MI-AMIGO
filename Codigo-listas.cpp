#include <ioestream>
using namespace std;

template<typename T>
class List{
private:
class Node {
Node* next_;
T data;
public:
Node(): next_(nullptr), data(T()) {}
Node (const T& d) next_(nullptr), data_(d) {}
void setNext (Node* p){
  next_ = p;
}
Node* getNext () { return next_; }
};

// Atributos
Node* first_;
Node* last_;
unsigned int size_;
public:
list() : first_(nullptr), last_(nullptr), size_(0) {}
insigned int size_() const {return size_;}
bool empty () {
  if (first_ == nulptr){
    true;
}}
void push_back (T& elem) {
  Node* n = new Node(elem);
  if (empty()) {
    first_ = n;
  }else{
    last_
  }
  last_ = n;
  size++;
}

void push_front (T& elem) {
  Node* n = new Node(elem);
  if (empty()) {
    first_ = n;
    last_ =n;
    size++;
  }
  //El siguiente de n debe apuntar a lo que apunta firts
  //fisrt deberia apuntar a n
  //incrementar size
}
}
