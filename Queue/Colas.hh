
#include <iostream>
#include <vector>

using namespace std;
template <typename T>

class Cola
{
    private: 
        vector<T> storage;

    public:
        Cola() : storage() {}

    /*  
    EVALUAR SI LA Cola ESTÁ VACÍA

    COMPLEJIDAD : O(1) porque storage empty es O(1).
    */

        bool empty() const {
            return storage.empty();
        }

    /*
    Retorna el número de elementos en la Cola
    */

        unsigned int size() const { return storage.size(); }
    
    /*
    Inserta el elemento en la Cola.
    Complejidad: constante amortoizada.
    */

        void push(const T &elem) { storage.push_back(elem); }
        void pop() { storage.pop_front(); }
        void print() const {
             storage.print();
        }
};
