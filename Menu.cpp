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


void menuPrincipal(archivoCompetencia& file_competencia,int total_paises[][5] ) 
{
	
	char fechaFormateada[20]; //nombre del archivo binario
	char opcion,volver;
	bool esvalido=true, salida=true, bandera= true, bandera2=true;
	int top // opcion de mostrar top medallero en el submenu "mostrar medallero"
	,numDeportes=0, numPaises=0 //Cantidad total de paises y deportes cargados
	,Deportes[87]={0}; //Acumulador de deportes cargados
	int suma[87] = {}; //Total de medallas obtenidas por el pais
	bool control=true; //
	bool controlCompetencia=false, controlCompetencia2= false;
	bool salida3=false; // salir de la opcion 3
	char opcion_generarCompetencia;
	
	srand(time(NULL));
	while(esvalido){
		system("cls");
		dibujarCuadro(1,1,77,3);
		gotoxy(30,2);cout<<" Menu Principal "<<endl;
		
		cout << endl << endl;
		
		if(!controlCompetencia){SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6); 
		}else{
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8); //Opcion deshabilitada
		}
		cout << "1.- Generar Competencia" << endl;
		
		if(!bandera){SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6); }
		else{
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8); //Opcion deshabilitada
		}
		cout << "2.- Cargar Medallas por Deporte" << endl;
		if((!bandera2)){SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		}else{
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
		}
		cout << "3.- Mostrar Medallero" << endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		if((!bandera2)){SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		}else{
			SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
		}
	
		cout << "4.- Mostrar Estadisticas" << endl;
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
		cout << "X.- Salir de la aplicacion" << endl << endl << endl ;
		cout << "Ingrese una opcion: " ; 
		
		
		
		salida=true;
		cin >> opcion;
		
		if(opcion=='x' or opcion=='X')esvalido=false;
		
		switch(opcion){
		
		case '1':
			if(!controlCompetencia){
			//SUB MENU GENERAR COMPETENCIA 
			system("cls");
			dibujarCuadro(1,1,77,3);
			gotoxy(30,2);
			
			cout << "Menu Generar Competencia " << endl;
			cout  << endl << endl;
			cout << "1.- Generar Competencia" << endl;
			cout << "2.- Cargar Competencia" << endl;
			cout << "X.- Volver al menu principal" << endl<<endl<<endl;
			cout << "Ingrese una opcion: " ;
			
			cin >> opcion_generarCompetencia;
			switch(opcion_generarCompetencia){
			case '1':
				if(!controlCompetencia){
					generar(file_competencia,bandera);
					crear_archivo(fechaFormateada,file_competencia);
					
					if(!bandera){
						controlCompetencia=true;
					}
				}
				else{
					cout << "YA SE GENERARON LOS PAISES QUE PARTICIPAN EN LA COMPETENCIA" << endl;
					system("pause");
					break;
					
				}
			system("pause");
				break;
			case '2':
				cout<<endl<<"INTRODUZCA LA FECHA CON EL SIGUIENTE FORMATO(AAAA-MM-DD-HH-MM-SS) :"<<endl;
				cin.ignore();
				cin.getline(fechaFormateada,20);
				abrir(fechaFormateada,file_competencia,total_paises,controlCompetencia,bandera2,bandera);
				inicializarPaises(total_paises);
				actualizarPaises(total_paises,file_competencia,numPaises);
				ordenarPaises(total_paises,196) ;
				extraer(file_competencia,Deportes);
				controlCompetencia2 = true;
				controlCompetencia=true;
				
				break;
				
			case 'x':
			case  'X':
				cout << endl << endl << "Deseas Salir de la aplicacion? " << endl;
				cout << endl << endl << "Presione 'S' si desea volver al menu principal o 'N' si no " << endl;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> volver;
				switch(volver){
				case 'S':
					case's':
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),12);
						cout << endl << endl <<  "USTED HA SALIDO DE LA APLICACION" << endl;
						SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
						break;
				case 'N':
					case'n':
						esvalido=true;
						
				}
				break;
			}
			break;
			}
			else{
				cout<<"YA SE GENERARON LOS PAISES QUE PARTICIPAN EN LA COMPETENCIA"<<endl;
				system("pause");
				break;
			}
			
		
		case '2':
			if(!bandera){
				
				while(salida){
					
					cargarMedalla(file_competencia, salida, numDeportes, numPaises ,total_paises,Deportes);
					if(salida){
						bandera2 = false;//Variable de control para que se me habilite la opcion 3
						controlCompetencia2 = true;
					}
					
				}
				ordenarPaises(total_paises, 196);
			}
			else{
				cout<<" No se completo correctamente la opcion 1 "<<endl;
				system("pause");
			}
			break;
		case '3':
			salida3=false;			
			if((!bandera2 or !bandera) and controlCompetencia2 ){
				while(!salida3){
					char opcion1;
					system("cls");
					dibujarCuadro(1,1,77,3);
					gotoxy(30,2);cout<<" Menu Medallero "<<endl;
					cout  << endl << endl;
					cout << "1.- Medallero por Pais" << endl;
					cout << "2.- Medallero por Deporte" << endl;
					cout << "3.- Top Medallero" << endl;
					cout << "X.- Volver al menu principal" << endl<<endl<<endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> opcion1;
					
					switch(opcion1){
					case '1':
	
					ordenarPaises(total_paises, 196);
					mostrarMedallero(total_paises, numPaises);
					
					break;
				case '2':
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
					cout << "Los deportes que se cargaron medallas son: " << endl;
					for(int i=0;i<87;i++){
						if(Deportes[i]>0){
							
							imprimirDeporte(Deportes[i]);
							cout << endl<< "1°: " ;imprimirPais(file_competencia.deporte_medallas[i][0]);
							cout <<endl<< "2°: ";imprimirPais(file_competencia.deporte_medallas[i][1]) ;
							cout <<endl<< "3°: " ;imprimirPais(file_competencia.deporte_medallas[i][2]);
							cout <<endl<< "---------------------------" << endl;
						}
					}
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
					system("pause");
					break;
				case '3':
					
					ordenarPaises(total_paises, numPaises);
					if(control)
						sumaMedallas(suma,total_paises,numPaises,control);
	
					cout << "Elija el top que quiera ver: " << endl;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> top;
					
					if(top>0){
						for(int i=0;i<top;i++){
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
							cout << "TOTAL DE MEDALLAS" << endl;
							cout << i+1 << ": ";
							imprimirPais(total_paises[i][0]);
							cout << " " << suma[i] << endl;
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6);
						}
						system("pause");
					}
					break;
				case 'x':
				case 'X':
					salida3=true;
				}
				}
			}
			else{
				cout<<" No se completo correctamente la opcion  2"<<endl;
				system("pause");
			}
			break;
		case '4':
			if(controlCompetencia2){
				estadisticas(total_paises,numPaises,Deportes,file_competencia);
			}
			else{
				cout<<" No se completo correctamente la opcion 2"<<endl;
				system("pause");
			}
			break;
			
		case 'X':
		case 'x':
		cout << endl << endl << "Deseas Salir de la aplicacion? " << endl;
		cout << endl << endl << "Presione 'S' si desea volver al menu principal o 'N' si no " << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> volver;
		switch(volver){
		case 'S':
			case's':
				actualizar(fechaFormateada,file_competencia, total_paises);
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),10);
				cout << endl << endl <<  "USTED HA SALIDO DE LA APLICACION" << endl;
				cout <<  "CON EXITO!" << endl;
				SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),6); 
				break;
		case 'N':
			case'n':
				esvalido=true;
		}
		break; 
		default:
			cout << "Opcion invalida" << endl;
			Sleep(3000);
		}
	}
}



