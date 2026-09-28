#ifndef CARGARMEDALLAS_H
#define CARGARMEDALLAS_H

struct archivoCompetencia ;struct competidores;
void cargarMedalla(int indicesIndividuales[],archivoCompetencia& file_competencia, bool& salida , int& numDeportes, int& numPaises ,int total_paises[196][5],int deportes[87]);
bool pais_ingresado(int verif2[], int var, int contador);
/*bool tipo_deporte_individual(int dep,  int indiceDeporte[]);
bool tipo_deporte_colectivo(int dep,  int indiceDeporte[]);*/

#endif
