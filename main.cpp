#include <iostream>
#include <chrono>

using namespace std;

const int MAX = 1000; 

double A[MAX][MAX];
double x[MAX];
double y[MAX];

void inicializar() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      A[i][j] = i + j; 
    }
    x[i] = i;
    y[i] = 0;
  }
}

void bucle1() {
  for (int i = 0; i < MAX; i++) {
    for (int j = 0; j < MAX; j++) {
      y[i] += A[i][j] * x[j]; 
    }
  }
}

void bucle2() {
  for (int j = 0; j < MAX; j++) {
    for (int i = 0; i < MAX; i++) {
      y[i] += A[i][j] * x[j];
    }
  } 
}

int main() {
  
  inicializar();
  
  auto inicio = chrono::high_resolution_clock::now();
  bucle1();
  auto fin = chrono::high_resolution_clock::now();
  chrono::duration<double> tiempo1 = fin - inicio; 

  inicio = chrono::high_resolution_clock::now();
  bucle2();
  fin = chrono::high_resolution_clock::now();
  chrono::duration<double> tiempo2 = fin - inicio;

  cout << "Tiempo bucle 1: " << tiempo1.count() << " segundos" << endl;
  cout << "Tiempo bucle 2: " << tiempo2.count() << " segundos" << endl;

  return 0;
}