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
//Funcion para verificar que el pais haya participado en la competencia 
bool verificar(int num , archivoCompetencia file_competencia, int c, int i){
	bool retornar = false;
	if (c < 0 or c > 87) {
		cout << "Error: índice del deporte fuera de rango.\n";
		retornar = false;
	}
	
	for (int j = 0; j < i; j++) {
		if (num == file_competencia.competencia[c].paises[j]) {
			retornar = true;
		}
	}
	return retornar;
}
//Funcion para generar los paises que participan en la competencia
void generar( archivoCompetencia& file_competencia, bool &bandera){
	int num;
	
	for(int c=0; c<87;c++){
		cout << "Competencia " << c+1 << " = " << endl;
	
	// Definimos el número total de países (entre 4 y 16)
	file_competencia.competencia[c].tl = 4 + rand() % 13;
	cout<<" TL " <<file_competencia.competencia[c].tl <<endl;
	for (int i = 0; i < file_competencia.competencia[c].tl; i++) {
		do {
			num = 1 + rand() % 196; // Número de país entre 1 y 196
		} while (verificar(num,file_competencia,c,i));// Verifica si el id ya fue utilizado
		file_competencia.competencia[c].paises[i] = num; // Asigna el número de país al arreglo
	}
	// Mostrar los países generados
	cout << "Paises seleccionados: ";
		for (int i = 0; i < file_competencia.competencia[c].tl; i++) {
			cout << file_competencia.competencia[c].paises[i] << " ";
		}
	cout << endl;
		
	}
	bandera = false;
}
	
	
	

