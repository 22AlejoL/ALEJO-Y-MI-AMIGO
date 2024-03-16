#include<iostream>
//For vectors
#include<vector>

//define red
#define RED "\033[31m"
#define RESET "\033[0m"


using namespace std;

// Definición de la plantilla de clase 'Vector' con tipo de dato genérico 'T'
template <typename T>
class Vector {
private: 
    unsigned int size_;     // Número actual de elementos en el vector
    unsigned int capacity_; // Capacidad actual del arreglo (cuántos elementos puede contener antes de necesitar una expansión)
    T* storage_;            // Puntero al arreglo dinámico que almacena los elementos

public:
    // Constructor por defecto
    Vector() : size_(0), capacity_(10) { // Inicializa un vector con capacidad para 10 elementos
        cout << "Hola desde el constructor " << this << endl;
        storage_ = new T[capacity_]; // Reserva memoria para la capacidad inicial
    }

    // Destructor
    ~Vector() {
        cout << "Hola mundo desde el destructor" << endl;
        delete[] storage_; // Libera la memoria reservada por el arreglo
    }

    // Verifica si el vector está vacío
    bool empty() const {
        return size_ == 0;
    }

    // Retorna el número de elementos en el vector
    unsigned int size() const {
        return size_;
    }

    // Retorna la capacidad actual del vector
    unsigned int capacity() const {
        return capacity_;
    }

    // Agrega un elemento al final del vector
    void push_back(const T& elem) {
        if (size_ == capacity_) { // Si el vector está lleno, aumenta su capacidad
            resize(capacity_ * 2); // Duplicar la capacidad
        }
        storage_[size_] = elem; // Asigna el nuevo elemento al final del vector
        size_++; // Incrementa el tamaño del vector
    }

    // Redimensiona el vector a una nueva capacidad
    void resize(unsigned int new_capacity) {
        T* newStorage = new T[new_capacity]; // Crea un nuevo arreglo con la nueva capacidad
        for (unsigned int i = 0; i < size_; i++) {
            newStorage[i] = storage_[i]; // Copia los elementos al nuevo arreglo
        }
        delete[] storage_; // Libera la memoria del arreglo anterior
        storage_ = newStorage; // Actualiza el puntero al nuevo arreglo
        capacity_ = new_capacity; // Actualiza la capacidad del vector
    }

    // Retorna una referencia al primer elemento del vector
    T& front() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return storage_[0];
    }

    // Retorna una referencia al último elemento del vector
    T& back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        return storage_[size_ - 1];
    }

    // Retorna una referencia al elemento en la posición especificada
    T& at(unsigned int pos) {
        if (pos >= size_) throw std::out_of_range("Index out of range");
        return storage_[pos];
    }

    // Elimina el último elemento del vector
    void pop_back() {
        if (!empty()) {
            size_--; // Simplemente disminuye el tamaño, los elementos se sobrescribirán cuando se agregue un nuevo elemento
        }
    }

    // Elimina el primer elemento del vector
    void pop_front() {
        if (!empty()) {
            for (unsigned int i = 0; i < size_ - 1; i++) {
                storage_[i] = storage_[i + 1]; // Desplaza todos los elementos una posición hacia adelante
            }
            size_--; // Disminuye el tamaño del vector
        }
    }

    // Agrega un elemento al inicio del vector
    void push_front(const T& elem) {
        if (size_ == capacity_) { // Si el vector está lleno, aumenta su capacidad
            resize(capacity_ * 2); // Duplicar la capacidad
        }
        for (unsigned int i = size_; i > 0; i--) {
            storage_[i] = storage_[i - 1]; // Desplaza todos los elementos una posición hacia atrás
        }
        storage_[0] = elem; // Inserta el nuevo elemento al inicio del vector
        size_++; // Incrementa el tamaño del vector
    }
};
