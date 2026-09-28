#include <iostream>
#include<stdlib.h>// Se incluye principalmente para utilizar la función system()
#include <windows.h>//se utiliza la manipulación de la consola.
#include <conio.h>//Se utiliza para manejar la entrada de caracteres (getch())
#include <ctime>
#include <time.h>
#include <limits>
#include <iomanip>
#include <fstream>
// Son creadas por nosotros
#include "bienvenida.h"
#include "cargarMedallas.h"
#include "deportes.h"
#include "generarCompetencia.h"
#include "logIn.h"
#include "menuPrincipal.h"
#include "mostrarMedallero.h"
#include "paises.h"
#include "structCompetencia.h"
#include "structPais.h"
#include "archivo.h"
#include "estadisticas.h"


using namespace std;


bool esMejor(const int a[], const int b[]) {
	bool resultado;
	
	if (a[1] != b[1]) { // Comparar cantidad de oro
		resultado = a[1] > b[1];
	} 
	else if (a[2] != b[2]) { // Comparar cantidad de plata
		resultado = a[2] > b[2];
	} 
	else if (a[3] != b[3]) { // Comparar cantidad de bronce
		resultado = a[3] > b[3];
	} 
	else { // Comparar ID en caso de empate
		resultado = a[0] < b[0];
	}
	
	return resultado;
}




void ordenarPaises(int total_paises[][5], int n) {
	for (int i = 0; i < n ; i++) {
		int mejorIndice = i;
		for (int j = i + 1; j < n; j++) {
			if (esMejor(total_paises[j], total_paises[mejorIndice])) {
				mejorIndice = j;
			}
		}
		// Intercambiar filas si es necesario
		if (mejorIndice != i) {
			for (int k = 0; k < 5; k++) {
				swap(total_paises[i][k], total_paises[mejorIndice][k]);
			}
		}
	}
}


// Función para mostrar el medallero
void mostrarMedallero(int total_paises[][5], int numPaises) {
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
	cout << "Top del medallero olimpico:" << endl;
	cout << left << setw(20) << "Pais" << setw(10) << "Oro" << setw(10) << "Plata" << setw(10) << "Bronce" << setw(10) << "TOTAL" << endl;
	cout << "-------------------------------------------------------------" << endl;
	for (int i = 0; i < numPaises; i++) {
		if (total_paises[i][0] != 0) {
			cout << left << setw(15);
			imprimirPais(total_paises[i][0]);
			//cout << left << setw(20);
			cout << right<< setw(25) << total_paises[i][1]
				<< setw(10) << total_paises[i][2]
				<< setw(10) << total_paises[i][3]
				<< setw(10) << total_paises[i][4] << endl;
		}
	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
	system("pause");
}

// Función para inicializar los países
void inicializarPaises(int total_paises[][5], int var ,int contador, int & numPaises ) {
	bool bandera= false;
	/*Corremos un for que recorre total_paises,
	si esta el pais le sumamos la medallas pero sino esta 
	agregamos otro id y le sumamos las medallas
	*/
		for(int k=0;k<numPaises;k++){
			if(total_paises[k][0] == var){
				if(contador == 0)
					total_paises[k][1]++;
				else if(contador == 1)
					total_paises[k][2]++;
				else if(contador == 2)
					total_paises[k][3]++;
				total_paises[k][4]++;
				bandera = true;
				break;
			}
		}
		if(!bandera){
		total_paises[numPaises][0] = var;
		if(contador == 0)
			total_paises[numPaises][1]++;
		else if(contador == 1)
			total_paises[numPaises][2]++;
		else if(contador == 2)
			total_paises[numPaises][3]++;
			
		total_paises[numPaises][4]++;
		
		numPaises++;
		}
}

void sumaMedallas(int suma[], int total_paises[][5], int numPaises, bool& control){
	for(int i=0;i<numPaises;i++){
		suma[i]+=total_paises[i][1];
		suma[i]+=total_paises[i][2];
		suma[i]+=total_paises[i][3];
	}
	control=false;
}
