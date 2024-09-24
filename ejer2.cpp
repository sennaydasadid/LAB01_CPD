#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <time.h>
#include <chrono>
using namespace std::chrono;
using namespace std;
void llenarMatriz(int** matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = rand() % 11; 
        } 
    }
}

int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    return matriz;
}



void multiplicarMatrices(int** A, int** B, int** C, int n) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
void multiplicarPorBloques(int** A, int** B, int** C, int n, int blockSize) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
        }
    }

    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                
                for (int i = ii; i < min(ii + blockSize, n); i++) {
                    for (int j = jj; j < min(jj + blockSize, n); j++) {
                        for (int k = kk; k < min(kk + blockSize, n); k++) {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}

int main() {
    auto inicio = high_resolution_clock::now();

    int tam[] = {10, 100, 1000, 2000};  
    for (int t = 0; t < 4; t++) {
        
        int n = tam[t];

       
        int** A = crearMatriz(n, n);
        int** B = crearMatriz(n, n);
        int** C = crearMatriz(n, n);

        llenarMatriz(A, n, n);
        llenarMatriz(B, n, n);
        
        multiplicarMatrices(A, B, C, n);

        auto fin = high_resolution_clock::now();
        auto duracion = duration_cast<milliseconds>(fin - inicio);

        cout << "Tiempo de Ejecucion: " << duracion.count() << endl;
        //por bloques
        auto inicio_ = high_resolution_clock::now();
        int blockSize = 2; 

        multiplicarPorBloques(A, B, C, n, blockSize);
        auto fin_ = high_resolution_clock::now();
        auto duracion_ = duration_cast<milliseconds>(fin_ - inicio_);
        cout << "Tiempo de Ejecucion_bloques: " << duracion_.count() << endl;
    }

    return 0;
}