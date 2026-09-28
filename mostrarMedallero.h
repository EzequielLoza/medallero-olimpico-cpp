#ifndef MOSTRARMEDALLERO_H
#define MOSTRARMEDALLERO_H

bool esMejor(const int a[], const int b[]);
void ordenarPaises(int total_paises[][5], int n);
void mostrarMedallero(int total_paises[][5], int numPaises);
void inicializarPaises(int total_paises[][5], int var ,int contador, int &numPaises );
void sumaMedallas(int suma[], int total_paises[][5], int numPaises, bool& control);

	
#endif
