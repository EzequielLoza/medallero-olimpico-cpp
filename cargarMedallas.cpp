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




void cargarMedalla(archivoCompetencia & file_competencia, bool& salida, int& numDeportes, int& numPaises, int total_paises[196][5], int deportes[87]) {
	
	system("cls");
	dibujarCuadro(1, 1, 77, 3);
	gotoxy(30, 2); cout << " Menu Carga Medallas por Deporte " << endl;
	int contador = 0, var;
	char salir; // Vble para salir o no de la opcion actual
	int verif2[196]; //Arreglo para verificar que no se repitan los paises en la competencia dada
	bool bandera = true;
	cout << endl << endl;
	cout << "1.- Carga por Deporte Individual" << endl;
	cout << "2.- Carga por Deporte Colectivo" << endl;
	cout << "X.- Volver al menu principal" << endl << endl << endl;
	
	char opcion1;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin >> opcion1;
	
	int dep; //Deporte a cargar
	
	
	switch(opcion1) {
	case '1':
		contador = 0; //Paises que ganaron medallas en la competencia actual
		bandera = true;
		mostrarDeportesIndividuales();
		cout << endl << endl;
		cout << "Elige un deporte individual: " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // limpiamos buffer 
		cin >> dep;
		
		if(dep<=87){
			system("cls");
			
		
			cout << " Los paises quienes participaron en esa competencia son: " << endl;
			
			for (int i=0;i<file_competencia.competencia[dep-1].tl;i++) {
				cout << file_competencia.competencia[dep-1].paises[i] << " - ";
				imprimirPais(file_competencia.competencia[dep-1].paises[i]);
			}
			
			cout << endl << endl;
			cout << " PRESIONE (0) PARA SALIR " << endl;
			cout << endl << endl;
			cout << " Paises quienes ganaron medallas: " << endl;
			
			while (contador<3 and bandera) {
				cout << "Ingrese quien salio " << contador+1 << " = "; 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> var;
				verif2[contador] = var; 
				
				if (var==0) {
					cout << "¿Estas seguro que quiere abandonar la carga? " << endl;
					cout << "S= (Si)    N= (NO)" << endl;
					cin >> salir;
					if (salir=='S' or salir=='s') {
						bandera = false; 
					}
				}
				else {
					if (verificar(var, file_competencia, dep - 1, file_competencia.competencia[dep-1].tl)) {
						if (pais_ingresado(verif2, var, contador)) {
							verif2[contador] = var; 
							file_competencia.deporte_medallas[dep-1][contador] = var;
							inicializarPaises(total_paises, var, contador, numPaises);
							contador++;  
						} else {
							cout << "YA INGRESASTE ESTE PAIS, INGRESA OTRO" << endl;
						}
					} else {
						cout << "El pais no participa en la competencia dada." << endl;
					}
				}
			}
		} else {
			cout << "EL DEPORTE ESTA FUERA DE RANGO \n";
			system("pause");
		}
			borrarPantalla();
			
			if (contador>=3) {
				cout << "Se ha cargado correctamente" << endl << endl << endl;
				cout << "Presione una tecla para continuar";
				deportes[dep-1] = dep;
				numDeportes++;
				
				} else {
				file_competencia.deporte_medallas[dep][contador]=0;
				cout <<endl<<endl<< "Usted ha abandonado la carga" << endl;
				
			}
			system("pause");
		break;
		
	case '2':
		
		contador = 0;
		bandera = true;
		mostrarDeportesColectivos();
		cout << endl << endl;
		cout << "Elige un deporte colectivo: " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> dep;
		
		if(dep<=87) {
		
			system("cls");
			cout << " Los paises quienes participaron en esa competencia son: " << endl;
			for (int i=0;i<file_competencia.competencia[dep-1].tl;i++) {
				cout << file_competencia.competencia[dep-1].paises[i] << " - ";
				imprimirPais(file_competencia.competencia[dep-1].paises[i]);
			}
			cout << endl << endl;
			cout << " PRESIONE (0) PARA SALIR " << endl;
			cout << endl << endl;
			cout << " Paises quienes ganaron medallas: " << endl;
			
			while (contador<3 and bandera) {
				cout << "Ingrese quien salio " << contador+1 << " = "; 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> var;
				verif2[contador] = var; 
				
				if (var==0) {
					cout << "¿Estas seguro que quiere abandonar la carga? " << endl;
					cout << "S= (Si)    N= (NO)" << endl;
					cin >> salir;
					if (salir=='S' or salir=='s') {
						bandera = false; 
					}
				}
				else {
					if (verificar(var, file_competencia, dep - 1, file_competencia.competencia[dep-1].tl)) {
						if (pais_ingresado(verif2, var, contador)) {
							verif2[contador] = var; 
							file_competencia.deporte_medallas[dep-1][contador] = var;
							inicializarPaises(total_paises, var, contador, numPaises);
							contador++;  
						} else {
							cout << "YA INGRESASTE ESTE PAIS, INGRESA OTRO" << endl;
						}
					} else {
						cout << "El pais no participa en la competencia dada." << endl;
					}
				}
			}
		} else {
			cout << "EL DEPORTE ESTA FUERA DE RANGO \n";
			system("pause");
		}
		borrarPantalla();
		
		if (contador>=3) { 
			cout << "Se ha cargado correctamente" << endl << endl << endl;
			cout << "Presione una tecla para continuar";
			deportes[dep-1] = dep;
			numDeportes++;
			
		} else {
			file_competencia.deporte_medallas[dep][contador]=0;
			cout <<endl<<endl<< "Usted ha abandonado la carga" << endl;
		}
		system("pause");
		
		
		
		break;
	case 'x':
	case 'X':
		salida = false;
		break;
	}
}	

// Verifica si el país ya fue ingresado en la misma sesión de carga
bool pais_ingresado(int verif2[], int var, int contador) {
	bool retorno = true;
	if (contador>=0) {
		for (int i=0;i<contador;i++) {
			if (verif2[i] == var) {
				retorno = false;  //El pais fue ingresado en la sesion actual
			}
		}
	}
	return retorno; //El pais no fue ingresado en la sesion actual
}

