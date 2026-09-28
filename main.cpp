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


int main(){
	int nrolegajo;
	archivoCompetencia file_competencia={0};
	int total_paises[196][5]={0}; //Matriz en la que guardamos la info. de los paises(id,medallas,total de medallas)
	
	bienvenida();
	
	//if(logIn(nrolegajo)){
		file_competencia.legajo=nrolegajo;
		menuPrincipal(file_competencia,total_paises);
	//}
	
	
	return 0;
	
}
