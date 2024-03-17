#include <iostream>
#include "vector.hh"
#include "gauss.hh"

#define CYAN    "\x1b[36m"
#define RESET   "\033[0m"
#define ROJO    "\033[31m"     
#define VERDE   "\033[32m"      
#define AZUL    "\033[34m"      
#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"

int main() {
    int filas, columnas;
    cout << CYAN "Ingrese el número de filas de la matriz: " RESET;
    cin >> filas;
    cout << CYAN "Ingrese el número de columnas de la matriz: " RESET;
    cin >> columnas;

    Matriz<double> m(filas, columnas); // Puedes cambiar double por otro tipo de dato si lo necesitas
    m.inicializar();

    cout << VERDE "La matriz ingresada es:" RESET<< endl;
    m.imprimir();
    cout << endl;

    cout << VERDE "El determinante de la matriz es: " RESET << m.determinante() << endl;

    // Calcular la inversa de la matriz
    cout << VERDE "La matriz inversa es:" RESET << endl;
    Matriz<double> inversa = m.inversa();
    inversa.imprimir();

    // resolver la matriz
    m.gaussJordan();

    cout << VERDE "La matriz después de la eliminación Gauss-Jordan es:" RESET << endl;
    m.imprimir();

    return 0;
}
