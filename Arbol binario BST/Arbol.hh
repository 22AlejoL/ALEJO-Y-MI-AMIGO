#ifndef _QUEUE_HH_
#define _QUEUE_HH_

#include <ioestream>

//Insertar nodo
//Mostrar arbol
//Buscar nodo
//Recorrer arbol
//Borrar nodo
template<typename T>
class BST {
    private:
    T data;
    Node *izq;
    Node *der;
    
    public:
    BST (): izq(nullptr), der(nullptr), data(0);

    BST (T elem): data = elem, izq = nullptr, der = nullptr;

    bool empty(){
        return !root = nullptr;
    }

    void Insert (T elem){
        *BST n = new BST(elem);

    }
    
}
#endif
