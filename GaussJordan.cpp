#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    int rows;
    int cols;

public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    void set(int row, int col, T value) {
        data[row][col] = value;
    }

    T get(int row, int col) const {
        return data[row][col];
    }

    int numRows() const {
        return rows;
    }

    int numCols() const {
        return cols;
    }

    // Método para intercambiar dos filas de la matriz
    void swapRows(int i, int j) {
        std::swap(data[i], data[j]);
    }

    // Método para multiplicar una fila por un escalar
    void multiplyRow(int row, T scalar) {
        for (int j = 0; j < cols; ++j) {
            data[row][j] *= scalar;
        }
    }

    // Método para sumar a una fila el múltiplo de otra fila
    void addRowMultiple(int destRow, int srcRow, T scalar) {
        for (int j = 0; j < cols; ++j) {
            data[destRow][j] += scalar * data[srcRow][j];
        }
    }

    // Método para calcular el determinante de la matriz
    T determinant() const {
        if (rows != cols) {
            throw logic_error("La matriz debe ser cuadrada para calcular el determinante.");
        }

        Matrix<T> temp(*this);
        T det = 1;

        for (int i = 0; i < rows; ++i) {
            int pivot = i;
            while (pivot < rows && temp.get(pivot, i) == 0) {
                ++pivot;
            }
            if (pivot == rows) {
                return 0;
            }
            if (pivot != i) {
                temp.swapRows(i, pivot);
                det = -det;
            }
            det *= temp.get(i, i);
            temp.multiplyRow(i, 1 / temp.get(i, i));
            for (int j = i + 1; j < rows; ++j) {
                temp.addRowMultiple(j, i, -temp.get(j, i));
            }
        }
        return det;
    }

    // Método para obtener la matriz inversa
    Matrix<T> inverse() const {
        if (rows != cols) {
            throw logic_error("La matriz debe ser cuadrada para tener inversa.");
        }

        Matrix<T> temp(rows, 2 * cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                temp.set(i, j, data[i][j]);
            }
            temp.set(i, i + cols, 1);
        }

        for (int i = 0; i < rows; ++i) {
            int pivot = i;
            while (pivot < rows && temp.get(pivot, i) == 0) {
                ++pivot;
            }
            if (pivot == rows) {
                throw logic_error("La matriz no es invertible.");
            }
            temp.swapRows(i, pivot);
            temp.multiplyRow(i, 1 / temp.get(i, i));
            for (int j = 0; j < rows; ++j) {
                if (j != i) {
                    temp.addRowMultiple(j, i, -temp.get(j, i));
                }
            }
        }

        Matrix<T> result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.set(i, j, temp.get(i, j + cols));
            }
        }
        return result;
    }
};

int main() {
    int size;
    cout << "Ingrese el tamaño de la matriz cuadrada: ";
    cin >> size;

    Matrix<double> mat(size, size);

    cout << "Ingrese los componentes de la matriz:" << endl;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << "Ingrese el componente (" << i+1 << "," << j+1 << "): ";
            double value;
            cin >> value;
            mat.set(i, j, value);
        }
    }

    try {
        // Calcula el determinante
        cout << "Determinante: " << mat.determinant() << endl;

        // Calcula la inversa e imprime la matriz inversa
        Matrix<double> inverse = mat.inverse();
        cout << "Matriz Inversa:" << endl;
        for (int i = 0; i < inverse.numRows(); ++i) {
            for (int j = 0; j < inverse.numCols(); ++j) {
                cout << inverse.get(i, j) << " ";
            }
            cout << endl;
        }
    } catch (exception& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
