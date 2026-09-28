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

void crear_archivo(char fechaFormateada[],archivoCompetencia file_competencia){
	time_t ahora;
	tm *fecha;
	time(&ahora);
	fecha = localtime(&ahora);
	// Crear el string con el formato deseado
	sprintf(fechaFormateada, "%04d-%02d-%02d-%02d-%02d-%02d", 
			fecha->tm_year + 1900, fecha->tm_mon + 1, fecha->tm_mday, 
			fecha->tm_hour, fecha->tm_min, fecha->tm_sec);
	
	// Convertir el arreglo a string
	string fechaStr(fechaFormateada);
	
	// Crear el archivo con el nombre basado en la fecha
	ofstream archivo(fechaStr + ".bin");
	
	if (archivo) {
		archivo << "Este es el archivo con fecha: " << fechaStr << endl;
		
		archivo.close();
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
		cout <<endl<<endl<< "Archivo creado exitosamente: " << fechaStr << ".bin" << endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		
	} else {
		cout << "Error al crear el archivo." << endl;
	}
	archivo.close();
}
	
void actualizar(char fechaFormateada[], archivoCompetencia file_competencia, int total_paises[][5])
{
	
	string fechaStr(fechaFormateada);
	ofstream  archivo;
	archivo.open(fechaStr+".bin" , ios:: binary );
	if(!archivo){
		cout<<"ERRROR EN ABRIR EL ARCHIVO!!! "<<endl;
	}
	else{
		archivo.write((char*)(&file_competencia),sizeof(archivoCompetencia));
		archivo.write((char*)(total_paises),195* 5 * sizeof(int));
		cout<<"Se se realizo correctamente la carga de la informacion"<<endl;
		cout<<"LEGAJO: "<<file_competencia.legajo<<endl;
		cout<<"FECHA CREACION: "<<fechaStr<<endl;
		system("pause");
	}
	archivo.close();
}

void abrir(char fechaFormateada[], archivoCompetencia &  file_competencia, int total_paises[][5],bool controlCompetencia, bool & bandera2, bool & bandera)
{
	string fechaStr(fechaFormateada);
	ifstream  archivo;
	archivo.open(fechaStr+".bin" , ios:: binary );
	if(!archivo){
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);
		cout<<"ERRROR EN ABRIR EL ARCHIVO!!!"<<endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		system("pause");
	}else{
		archivo.read((char*)(&file_competencia),sizeof(archivoCompetencia));
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
		cout<<"\nSE LEYO CORRECTAMENTE EL ARCHIVO "<<fechaStr<<endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		controlCompetencia=true;
		bandera2 = false; 
		bandera = false;
		system("pause");
	}
	archivo.close();
}

void inicializarPaises(int paises[196][5]) {
	for (int i = 0; i < 196; i++) {
		paises[i][0] = i + 1; // Columna 0 contiene el ID del país
		paises[i][1] = 0;     // Oro
		paises[i][2] = 0;     // Plata
		paises[i][3] = 0;     // Bronce
		paises[i][4] = 0;     // Total
	}
}

void actualizarPaises(int total_paises[196][5], archivoCompetencia& file_competencia, int &numPaises)
{//Funcion para pasar lo que esta en la estructura file_competencia a la matriz total_paises

	// Iterar sobre cada competencia
	for (int c = 0; c < 87; c++) {
		int oro = file_competencia.deporte_medallas[c][0];
		int plata = file_competencia.deporte_medallas[c][1];
		int bronce = file_competencia.deporte_medallas[c][2];
		
		// Actualizar los valores en la matriz países
		if (oro > 0 and oro <= 196) 
		{total_paises[oro - 1][1]++;}   
		if (plata > 0 and plata <= 196)
		{total_paises[plata - 1][2]++;}  
		if (bronce > 0 and bronce <= 196)
		{total_paises[bronce - 1][3]++;} 
	}
	
	// Recalcular el total de medallas para cada país
	for (int i = 0; i < 196; i++) {
		total_paises[i][4] = total_paises[i][1] + total_paises[i][2] + total_paises[i][3];
		if(total_paises[i][4]>0){numPaises++;}
	}
}

void extraer(const archivoCompetencia file_competencia, int deportes[86])
{ //En esta funcion obtenemos los deportes en los que se cargaron medallas
	
	for(int i =0;i<87;i++){
		if((file_competencia.deporte_medallas[i][0] > 0 or file_competencia.deporte_medallas[i][1] > 0 or file_competencia.deporte_medallas[i][2] > 0))
		{
			deportes[i]=i+1;
		}
	}
}
