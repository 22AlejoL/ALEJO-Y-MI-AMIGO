#include <iostream>

#define CYAN    "\x1b[36m"
#define RESET   "\033[0m"
#define ROJO    "\033[31m"     
#define VERDE   "\033[32m"      
#define AZUL    "\033[34m"      
#define YELLOW  "\x1b[33m"
#define MAGENTA "\x1b[35m"

// Espacio de nombres
using namespace std;

template<typename T>
class Matriz {
private:
    int numFilas;
    int numColumnas;
    vector<vector<T>> datos;

public:
    // constructor
    Matriz(int filas, int columnas) {
        numFilas = filas;
        numColumnas = columnas;
        datos.resize(filas, vector<T>(columnas + 1, 0)); // +1 para la columna de resultados
        cout << VERDE "Matriz creada" RESET << endl;
    }

    // inicializar la matriz
    void inicializar() {
        T valor;
        cout << YELLOW "Ingrese los elementos de la matriz fila por fila:" RESET << endl;
        for (int i = 0; i < numFilas; i++) {
            for (int j = 0; j < numColumnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> valor;
                datos[i][j] = valor;
            }
        }
        cout << YELLOW "Ingrese los elementos del vector respuesta:" RESET << endl;
        for (int i = 0; i < numFilas; i++) {
            cout << "Elemento [" << i << "]: ";
            cin >> valor;
            datos[i][numColumnas] = valor; // almacenar los resultados en la última columna
        }
    }

    // imprimir la matriz
    void imprimir() {
        for (int i = 0; i < numFilas; i++) {
            for (int j = 0; j < numColumnas + 1; j++) {
                cout << datos[i][j] << "\t";
            }
            cout << endl;
        }
    }

    // aplicar eliminación de Gauss-Jordan
    void gaussJordan() {
        int lider = 0;
        for (int r = 0; r < numFilas; r++) {
            if (lider >= numColumnas)
                return;

            int i = r;
            while (datos[i][lider] == 0) {
                i++;
                if (i == numFilas) {
                    i = r;
                    lider++;
                    if (lider == numColumnas)
                        return;
                }
            }

            // Intercambiar filas i y r
            datos[i].swap(datos[r]);

            // Normalizar fila r
            T divisor = datos[r][lider];
            for (int j = 0; j <= numColumnas; j++) {
                datos[r][j] /= divisor;
            }

            cout << AZUL "Paso " << r + 1 << ":" << RESET << endl;
            imprimir();
            cout << endl;

            for (int i = 0; i < numFilas; i++) {
                if (i != r) {
                    T resta = datos[i][lider];
                    for (int j = 0; j <= numColumnas; j++) {
                        datos[i][j] -= (resta * datos[r][j]);
                    }
                }
            }
            lider++;
        }
    }

    // Calcular el determinante de la matriz
    T determinante() {
        if (numFilas != numColumnas) {
            cout << ROJO "No se puede calcular el determinante de una matriz no cuadrada." RESET << endl;
            return 0;
        }

        Matriz<T> temp(*this); // Copia de la matriz original
        T det = 1;

        for (int i = 0; i < numFilas; i++) {
            if (temp.datos[i][i] == 0) {
                // Si el elemento diagonal es cero, intercambiar con una fila no cero debajo
                int j = i + 1;
                while (j < numFilas && temp.datos[j][i] == 0)
                    j++;

                if (j == numFilas) // Si no se encuentra una fila no cero
                    return 0; // El determinante es cero

                temp.datos[i].swap(temp.datos[j]); // Intercambiar filas
                det *= -1; // Cambiar el signo del determinante
            }

            det *= temp.datos[i][i]; // Multiplicar por el elemento diagonal actual
            T divisor = temp.datos[i][i]; // Almacenar el elemento diagonal actual como divisor

            // Normalizar la fila actual
            for (int j = 0; j < numColumnas; j++)
                temp.datos[i][j] /= divisor;

            // Hacer ceros en la columna actual por eliminación gaussiana
            for (int j = i + 1; j < numFilas; j++) {
                T factor = temp.datos[j][i] / temp.datos[i][i];
                for (int k = 0; k < numColumnas; k++)
                    temp.datos[j][k] -= factor * temp.datos[i][k];
            }
        }

        return det;
    }

    // Calcular la matriz inversa
    Matriz<T> inversa() {
        if (numFilas != numColumnas) {
            cout << ROJO "No se puede calcular la matriz inversa de una matriz no cuadrada." RESET << endl;
            return *this;
        }

        Matriz<T> identidad(numFilas, numColumnas); // Matriz identidad del mismo tamaño que la matriz original
        for (int i = 0; i < numFilas; i++)
            identidad.datos[i][i] = 1; // Llenar la diagonal principal con unos

        Matriz<T> temp(*this); // Copia de la matriz original

        // Aplicar eliminación gaussiana a la matriz original y a la matriz identidad simultáneamente
        for (int i = 0; i < numFilas; i++) {
            // Encontrar el primer elemento no cero en la columna i
            int row_index = i;
            while (temp.datos[row_index][i] == 0 && row_index < numFilas)
                row_index++;

            // Si no se encuentra un elemento no cero, la matriz no tiene inversa
            if (row_index == numFilas) {
                cout << ROJO "La matriz no tiene inversa." RESET << endl;
                return *this;
            }

            // Intercambiar las filas en ambas matrices
            temp.datos[i].swap(temp.datos[row_index]);
            identidad.datos[i].swap(identidad.datos[row_index]);

            // Escalar la fila para que el elemento diagonal sea igual a 1 en la matriz original y la matriz identidad
            T divisor = temp.datos[i][i];
            for (int j = 0; j < numColumnas; j++) {
                temp.datos[i][j] /= divisor;
                identidad.datos[i][j] /= divisor;
            }

            // Hacer ceros en la columna i en ambas matrices
            for (int j = 0; j < numFilas; j++) {
                if (j != i) {
                    T factor = temp.datos[j][i];
                    for (int k = 0; k < numColumnas; k++) {
                        temp.datos[j][k] -= factor * temp.datos[i][k];
                        identidad.datos[j][k] -= factor * identidad.datos[i][k];
                    }
                }
            }
        }

        return identidad;
    }
};
