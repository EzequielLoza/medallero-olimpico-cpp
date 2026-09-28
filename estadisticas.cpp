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


//Funcion para la opcion 4 del menu principal "Mostrar Estadisticas"
void estadisticas(int total_paises[][5],int numPaises, int Deportes[],archivoCompetencia file_competencia)
{
	bool salida4=false;
	char opcionEstadisticaas;
	while(!salida4){
		system("cls");
		dibujarCuadro(1,1,77,3);
		gotoxy(30,2);cout<<" Menu Estadisticas "<<endl;
		cout  << endl << endl;
		cout << "1.- Pais con mas medallas" << endl;
		cout << "2.- Medallas del pais" << endl;
		cout << "3.- Pais con mas deportes individuales" << endl;
		cout << "4.- Paises premiados del deporte" << endl;
		
		cout << "X.- Volver al menu principal" << endl<<endl<<endl;
		cin >> opcionEstadisticaas;
		switch(opcionEstadisticaas){
		case '1':
			mostrarPaisConMasMedallas(total_paises,numPaises);
			system("pause");
			break;
		case '2':
			mostrarMedallasDePais(total_paises,numPaises);
			system("pause");
			break;
		case '3':
			mostrarMedallasIndividuales( numPaises, total_paises,Deportes);
			system("pause");
			break;
		case '4':
			mostrarPodioPorLetra(Deportes,numPaises ,file_competencia );
			system("pause");
			break;
		case 'x':
		case 'X':
			salida4=true;break;
		}
	}
}


void mostrarPaisConMasMedallas(int total_paises[][5],int numPaises)
{
	int maxMedallas = 0, idMax = -1; //idMax = -1, ya que el id de un pais siempre va a ser mayor a 0, entonces siempre va a actualizarse
	
	for (int i = 0; i < numPaises; i++) {
		if (total_paises[i][4] > maxMedallas) {
			maxMedallas = total_paises[i][4]; //maxMedalas es igual al total de medallas del pais que mas ganó
			idMax = total_paises[i][0];       //Guardamos en idMax el id del pais que mas medallas ganó 
		}
	}

	if (idMax != -1) {
		cout << "El pais con mas medallas es: " ;
		imprimirPais(idMax);
		cout<< " con " << maxMedallas << " medallas." << endl;
	} else {
		cout << "No hay datos cargados." << endl;
	}
}

void mostrarMedallasDePais(int total_paises[][5],int numPaises) {
	cout << " Listado de paises:" << endl;
	listarPaises();
	
	int idSeleccionado;
	cout << endl << "Ingrese el ID del pais: ";
	
	cin >> idSeleccionado;
	if (idSeleccionado > 0 and idSeleccionado <= 197 ) {
		
		bool salir = false;
		
		for(int i =0;i<numPaises;i++){
			if(total_paises[i][0]==idSeleccionado){
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
				cout << "\nPais: " ;
				imprimirPais(idSeleccionado);
				cout <<endl<< "Oro: " << total_paises[i][1] << endl;
				cout << "Plata: " << total_paises[i][2] << endl;
				cout << "Bronce: " << total_paises[i][3] << endl;
				cout << "Total: " << total_paises[i][4] << endl;
				salir = true;
			}
		}
		if(!salir){
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);
				cout << "\nESTE PAIS NO GANO NINGUNA MEDALLA\n";
			}
		
	} else {
		cout << "Pais no valido y sin datos." << endl;
	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
}

bool indicesI( int num , int deportes[]) //Funcion para verificar si un deporte es individual o no
{ 
	bool res = false;
	for(int j=0;j<53;j++){ 	    // Hay 53 deportes individuales
		for(int i=0;i<87;i++){ //  Hay 87 competencias
			if( retornarDeporteIndividual(j)==deportes[i]){
				res = true;
			}
		}
	}
	return res;
}
void mostrarMedallasIndividuales(int numPaises, int total_paises[][5],int deportes[]) 
{
	int maxMedallas = 0, idMax = -1;
	
	for (int i = 0; i < numPaises; i++) {
		int medallasIndividuales = total_paises[i][1] + total_paises[i][2] + total_paises[i][3]; // Suma de medallas individuales
		if ((medallasIndividuales > maxMedallas) and indicesI(i,deportes)){
			maxMedallas = total_paises[i][4];
			idMax = total_paises[i][0];
		}
	}
	
	if (idMax != -1) {
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
		cout << "El pais con mas medallas en los deportes individuales es : " ;
		imprimirPais(idMax);
		cout<< " con " << maxMedallas << " medallas." << endl;
	} else {
		cout << "No hay datos cargados." << endl;
	}
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
}


void mostrarPodioPorLetra(int Deportes[], int numPaises, archivoCompetencia file_competencia) {
	char letra;
	cout << "Ingrese una letra (MAYUSCULA): ";
	cin >> letra;
	
	bool encontrado = false;
	
	for (int i = 0; i < 87; i++) {
		// Verificamos si el deporte tiene medallas cargadas
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
		if (Deportes[i] > 0) {
			const char* nombre = retornarDeportes(i+1); // +1 porque los índices empiezan en 1 en retornarDeportes
			// Comparamos la primera letra
			if (nombre[0] == letra) {
				encontrado = true;
				// Mostramos el nombre del deporte y el podio
				cout << "Deporte: " << nombre << endl;
				cout << "1°:  " ;imprimirPais(file_competencia.deporte_medallas[i][0]);
				cout <<endl<< "2°:  ";imprimirPais(file_competencia.deporte_medallas[i][1]) ;
				cout <<endl<< "3°:  " ;imprimirPais(file_competencia.deporte_medallas[i][2]);
				cout <<endl<< "---------------------------" << endl;
			}
		}
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
	}
	if (!encontrado) {
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);
		cout << "No se encontraron deportes que comiencen con la letra '" << letra << "'." << endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
	}
}







