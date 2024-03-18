

#include <iostream>


//Insertar nodo
//Mostrar arbol
//Buscar nodo
//Recorrer arbol
//Borrar nodo
template<typename T>
class BST {
    private:
     class Node {
    private:
        Node* izq; // Puntero a izquierda
        Node* der; // Puntero a derecha
        T data_; // Datos del nodo

    public:
        // Constructor por defecto
        Node() : izq(nullptr), der(nullptr), data_(T()) {}

        // Constructor con inicialización de datos
        Node(const T& d) : izq(nullptr),der(nullptr), data_(d) {}

        // Establecer el siguiente nodo en la lista
        void setNext(Node* p) { next_ = p; }
        

        // Obtener el siguiente nodo en la lista
        Node* getNext() { return next_; }

        // Obtener los datos del nodo
        const T& getData() const {
            return data_;
        }
        T& getData() {
            return data_;
        }
        Node* Raiz;
        unsigned int size = 0;
    };
    
    public:
    BST (): izq(nullptr), der(nullptr), data(0);

    BST (T elem): data = elem, izq = nullptr, der = nullptr;

    bool empty(){
        BST* n;
        return n = nullptr;
    }

    void Insert (T elem){
        if(empty()){
            *BST n = New BST(elem);
        }
        else{
            if(elem > n->data){
                n->der = Insert(n->der,elem);
            }
            else if{
                n->izq = Insert(n->izq,elem);
            }
        }
        return n;
    }
    void Ordenar(BST* n){
        if (empty()){
            return 0;
        }
        Ordenar(n->izq);
        cout << n->data << " ";
        Ordenar(n->der);
    }
    
};

int main(){
    BST<int> a;
    a.Insert(32);
    a.Insert(12);
    a.Ordenar(a);
}


