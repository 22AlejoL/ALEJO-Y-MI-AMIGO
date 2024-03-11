#include <iostream>
#include <vector>

using namespace std;
template <typename T>

class Pila
{
    private: 
        vector<T> storage;

    public:
        Pila() : storage() {}

    /*  
    EVALUAR SI LA PILA ESTÁ VACÍA

    COMPLEJIDAD : O(1) porque storage empty es O(1).
    */

        bool empty() const {
            return storage.empty();
        }

    /*
    Retorna el número de elementos en la pila
    */

        unsigned int size() const { return storage.size(); }
    
    /*
    Inserta el elemento en la pila.
    Complejidad: constante amortoizada.
    */

        void push(const T &elem) { storage.push_back(elem); }
        void pop() { storage.pop_back(); }
        const T &top() const { return storage.back(); }
        T &top() { return storage.back(); }
        void print() const {
            for (const T &1 : storage) {
                cout << " " << i; 
            }
        }
};
