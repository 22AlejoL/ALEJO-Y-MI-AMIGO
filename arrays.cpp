#include <iostream>

using namespace std;

class Vector
{
private:
    unsigned int capacity;
    unsigned int size;
    int* storage;
public:
    Vector() {
        capacity = 6;
        size = 0;
        storage = new int[capacity]; // Corregido para crear un arreglo de tamaño 'capacity'
    }

    ~Vector() {
        delete[] storage; // Liberar la memoria cuando el objeto se destruye
    }

    void push_back(int elem) {
        if (size == capacity) {
            cout << "El arreglo esta lleno, hay que redimensionar" << endl;
            resize();
        }
        storage[size] = elem;
        size++;
    }

    bool empty() { return size == 0; }

    void resize() {
        int* newstorage = new int[capacity * 2];
        for (unsigned int i = 0; i < size; i++) {
            newstorage[i] = storage[i];
        }
        delete[] storage;
        storage = newstorage;
        capacity = capacity * 2;
    }

    int& front() {
        if (size == 0) {
            cout << "Error: Vector vacío. No se puede obtener el primer elemento." << endl; // Otra opción sería lanzar una excepción.
        }
        return storage[0];
    }

    int& back() {
        if (size == 0) {
            cout << "Error: Vector vacío. No se puede obtener el último elemento." << endl;
        }
        return storage[size - 1];
    }

    int& at(unsigned int p) {
        if (p >= size) {
            cout << "Error: Índice fuera de rango." << endl;
        }
        return storage[p];
    }

    void pop_back() {
        if (size == 0) {
            cout << "Error: No se puede eliminar el último elemento de un vector vacío." << endl;
        }
        size--;
    }

    void pop_front() {
        if (size == 0) {
            cout << "Error: No se puede eliminar el primer elemento de un vector vacío." << endl;
        }
        for (unsigned int i = 0; i < size - 1; i++) {
            storage[i] = storage[i + 1];
        }
        size--;
    }

    void push_front(int e) {
        if (size == capacity) {
            cout << "El arreglo esta lleno, hay que redimensionar" << endl;
            resize();
        }
        for (unsigned int i = size; i > 0; i--) {
            storage[i] = storage[i - 1];
        }
        storage[0] = e;
        size++;
    }
};

int main() {
    Vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    v.push_back(10);
    cout << "Front: " << v.front() << endl; // Imprime 1
    cout << "Back: " << v.back() << endl;   // Imprime 3
    cout << "Elemento en la posición 1: " << v.at(1) << endl; // Imprime 2
    v.pop_back();
    cout << "Back después de pop_back(): " << v.back() << endl; // Imprime 2
    v.pop_front();
    cout << "Front después de pop_front(): " << v.front() << endl; // Imprime 2
    v.push_front(5);
    cout << "Front después de push_front(5): " << v.front() << endl; // Imprime 5
    return 0;
}