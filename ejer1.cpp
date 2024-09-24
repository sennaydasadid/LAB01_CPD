#include <iostream>
#include <chrono>
using namespace std::chrono;
#define MAX 10000

using namespace std;

double A[MAX] [MAX], x[MAX],y[MAX];
int main(){

    for (int i = 0; i < MAX; i++) {
        y[i] = 0; 
    }

    auto inicio = high_resolution_clock::now();
    for (int i=0; i < MAX; i++) 
        for (int j=0; j < MAX; j++) 
            y[i] += A[i][j]*x[j];
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);
    cout << "Tiempo de Ejecucion, 1er caso: " << duracion.count() << endl;

    for (int i = 0; i < MAX; i++) {
        y[i] = 0; 
    }

    auto inicio_ = high_resolution_clock::now();
    for  (int j=0; j < MAX; j++) 
        for  (int i=0 ; i < MAX; i++) 
            y[i] += A[i][j]*x[j];
    auto fin_ = high_resolution_clock::now();
    auto duracion_ = duration_cast<milliseconds>(fin_ - inicio_);
    cout << "Tiempo de Ejecucion, 2do caso: " << duracion_.count() << endl;
            
    return 0;
}
// se diferenciasn por el orden en que se recorren los idices de las matrices
// en el primero se recorre por filas y el segundo por columnas