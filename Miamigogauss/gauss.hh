#include<iostream>

// Colores para impresiones
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
};
