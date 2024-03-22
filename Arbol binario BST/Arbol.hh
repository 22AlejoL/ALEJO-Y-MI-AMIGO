#ifndef ARBOL_BINARIO
#define ARBOL_BINARIO

#include <iostream>
using namespace std;

template<typename T>
class binary_tree {
private:
    class Node {
    private:
        T data;
        Node* right;
        Node* left;
    public:
        Node() : data(), right(nullptr), left(nullptr) {}
        Node(const T& valor) : data(valor), left(nullptr), right(nullptr) {}
        
        const T& getData() const {
            return data;
        }
        
        Node* getLeft() const {
            return left;
        }
        
        Node* getRight() const {
            return right;
        }
        
        void setData(const T& newdata) {
            data = newdata;
        }

        void setLeft(Node* newleft) {
            left = newleft;
        }

        void setRight(Node* newright) {
            right = newright;
        }
    };

    Node* Raiz;
    unsigned int size;

    void Insert(Node* n, const T& newdata) {
        if (n->getData() > newdata) {
            if (n->getLeft() != nullptr) {
                Insert(n->getLeft(), newdata);
            }
            else {
                n->setLeft(new Node(newdata));
            }
        }
        else if (n->getData() < newdata) {
            if (n->getRight() != nullptr) {
                Insert(n->getRight(), newdata);
            }
            else {
                n->setRight(new Node(newdata));
            }
        }
        else {
            return;
        }
    }

    void deleteNode(Node* aux, Node* n) {
        if (n->getLeft() == nullptr && n->getRight() == nullptr) {
            if (aux->getLeft() == n) {
                aux->setLeft(nullptr);
            } else {
                aux->setRight(nullptr);
            }
            delete n;
        } else if (n->getLeft() != nullptr && n->getRight() == nullptr) {
            if (aux->getLeft() == n) {
                aux->setLeft(n->getLeft());
            } else {
                aux->setRight(n->getLeft());
            }
            delete n;
        } else if (n->getLeft() == nullptr && n->getRight() != nullptr) {
            if (aux->getLeft() == n) {
                aux->setLeft(n->getRight());
            } else {
                aux->setRight(n->getRight());
            }
            delete n;
        } else {
            Node* temp = n->getRight();
            while (temp->getLeft() != nullptr) {
                temp = temp->getLeft();
            }
            T value = temp->getData();
            deleteRecursive(Raiz, temp->getData());
            n->setData(value);
        }
    }

    void deleteRecursive(Node* n, const T& val) {
        if (n == nullptr) {
            return;
        }
        if (val < n->getData()) {
            if (n->getLeft() != nullptr) {
                if (n->getLeft()->getData() == val) {
                    deleteNode(n, n->getLeft());
                } else {
                    deleteRecursive(n->getLeft(), val);
                }
            }
        } else {
            if (n->getRight() != nullptr) {
                if (n->getRight()->getData() == val) {
                    deleteNode(n, n->getRight());
                } else {
                    deleteRecursive(n->getRight(), val);
                }
            }
        }
    }

    void Print(Node* n) const {
        if (n != nullptr) {
            Print(n->getLeft());
            cout << n->getData() << endl;
            Print(n->getRight());
        }
    }

    bool find(Node* n, const T& valor) const {
        if (n == nullptr) {
            return false;
        }
        if (n->getData() == valor) {
            return true;
        }
        if (valor < n->getData()) {
            return find(n->getLeft(), valor);
        }
        return find(n->getRight(), valor);
    }
public:
    binary_tree() : Raiz(nullptr), size(0) {}

    bool empty() const {
        return Raiz == nullptr;
    }

    void Insert(const T& newdata) {
        if (Raiz == nullptr) {
            Raiz = new Node(newdata);
        }
        else {
            Insert(Raiz, newdata);
        }
        size++;
    }

    void mostrar() const {
        Print(Raiz);
    }

    bool find(const T& data) const {
        return find(Raiz, data);
    }

    void remove(const T& val) {
        if (find(val)) {
            deleteRecursive(Raiz, val);
            size--;
        }
    }
};

#endif
