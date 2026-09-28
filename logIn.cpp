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

void gotoxy(int x,int y){  //funcion posicion del texto
	HANDLE hcon;  
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
	COORD dwPos;  
	dwPos.X = x;  
	dwPos.Y= y;  
	SetConsoleCursorPosition(hcon,dwPos);  
}
void dibujarCuadro(int x1,int y1,int x2,int y2){ //funcion para dibujar el cuadro

	int i;
	
	for (i=x1;i<x2;i++){
		gotoxy(i,y1); cout << "\304"; //linea horizontal superior
		gotoxy(i,y2); cout << "\304"; //linea horizontal inferior
	}
	
	for (i=y1;i<y2;i++){
		gotoxy(x1,i); cout <<"\263"; //linea vertical izquierda
		gotoxy(x2,i); cout <<"\263"; //linea vertical derecha
	}
	gotoxy(x1,y1); cout<< "\332"; 
	gotoxy(x1,y2); cout<< "\300";
	gotoxy(x2,y1); cout<< "\277";
	gotoxy(x2,y2); cout<< "\331";
}


bool logIn(int &nroLegajo){
	
	borrarPantalla();
	
	cout << "Pantalla de Login" << endl << endl << endl;
	
	int auxContra = 0;
	int contador = 0, usuario1 = 0, contrasena = 0; 
	char usuario[6];
	bool bandera=true, flag=true;
	
	//variable flag utilizada para ver si paso o no al menu principal
	//variable bandera para verificar las  condiciones adentro del do-while
	
	do{

		//USUARIO *****************************
		
		do{
		bandera=true;
		usuario1 = 0; // nro de legajo como tipo INT
		int j = 33; // columna donde se esta escribiendo el usuario
		cout << "Ingresar usuario(nro. de legajo): ";		
		int i=0;
		while(i<5){
			gotoxy(j,5);
			cin >> usuario[i];
			usuario1 = usuario1*10 + (usuario[i]-'0'); 
			//pasar usuario1 a char y de ahi usar isdigit
			
			//usamos la funcion isdigit para verificar que no sea una letra lo que ingrese
			if(!(isdigit(usuario[i]))){
				cout << "No es valido el nro de legajo " << endl;
				bandera = false;
				Sleep(2000);
			}
			j++;
			i++;
		}
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		// condicion de que el usuario(nro de legajo) sea de 5 digitos 
		if(usuario1>=10000 and usuario1<=99999 and bandera){
			cout << endl << "Usuario valido" << endl;
			bandera = true;
			nroLegajo=usuario1;	
			
		}
		else {
			bandera = false;
			cout << "Usuario incorrecto "<<endl;
			Sleep(2000);
			borrarPantalla();
			cout << "Pantalla de Login" << endl << endl << endl;
			contador++;
		}
		}while(!bandera and contador<3);
		
		//CONTRASEÑA**************************************
		
		if(contador>=0 and contador<3){
		
		char password[20];
		int contadorContrasenia = 0;
		char caracter;
		
		cout << "Ingrese la contrase" << (char)164 << "a: "; // para mostrar la "ñ"
		
		caracter = getch();
		
		while (caracter != '\r'){ //mientras se apriete una tecla distinto a ENTER
		
			if (caracter != '\b'){ //mientras se apriete una tecla distinto a ESPACIO
				if(contadorContrasenia<9){
					password[contadorContrasenia] = caracter;
					contadorContrasenia++;
					
					cout << "*";
				}
			}
			else{
				if (contadorContrasenia > 0){
					cout << "\b \b";  //borra el espacio vacio
					contadorContrasenia--;
				}
			}
			caracter = getch(); //guarda la cadena sin mostrar en pantalla
		}
		password[contadorContrasenia] = '\0'; // verifico que no guarde basura en el ultimo elemento
		
		Generarcontrasena(nroLegajo,password, auxContra, contrasena, contadorContrasenia);
	
		if(auxContra == contrasena){
			bandera = true;
		}
		else{
			contador++;
			cout <<endl<< "Contrase" << (char)164 << "a incorrecta" << endl;
			Sleep(300);
			bandera = false;
			
			/*Si la contraseña ingresada es incorrecta, reiniciamos auxContra y contadorContrasenia, porque sino en el 2do/3er intento, si
			la contraseña ingresada es la correspondiente, va a tomar como incorrecta*/
			
			auxContra = 0; 
			contadorContrasenia=0; 
			}
		}
		borrarPantalla();
		cout << "Pantalla de Login" << endl << endl << endl;
		
	} while(contador<3 and !bandera);
	
	if(contador>=3){
		system("cls");
		system("color 1F");
		gotoxy(5,6);cout<<"Superaste el maximo de intentos permitidos (3) "<<endl;
		system("pause");
		flag=false;
	}
	return flag;
}
bool esCapicua(int x, int& n){ //encuentra el primer nro. capicua mayor (estricto) que N
	
	bool bandera=false;
	
	while(!bandera){
		x++;
		int aux=x;
		if((aux/100) == (aux%10)){
			bandera = true;
			n = x;
		}
	}
	return bandera;
}	
void Generarcontrasena(int nroLegajo, char password[], int& auxContra, int& contrasena, int& contadorContrasenia){
	int aux;
	aux = nroLegajo;
	int ultimodigito, tercerdigito,primerdigito, ultimostresdigitos,n=0,numCapicua=0;
	
	ultimodigito=aux%10;
	tercerdigito=(aux/100)%10;
	primerdigito=aux/10000;
	ultimostresdigitos=aux%1000;
	
	n=(ultimodigito)+(tercerdigito*10)+(primerdigito*100);
	
	esCapicua(n,numCapicua);
	
	contrasena = (2024*numCapicua)+ultimostresdigitos;
	
	for(int i=0;i<contadorContrasenia;i++){
		auxContra = auxContra*10 +(password[i]-'0');
	}
}	
void borrarPantalla(){
	system("cls");// 
	system("color 06"); //COLOR DE LA VISTA
	dibujarCuadro(1,1,77,3);
	gotoxy(30,2);
}
