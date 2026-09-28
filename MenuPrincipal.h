#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
struct archivoCompetencia ;struct competidores;
//menu principal
void menuPrincipal(archivoCompetencia& file_competencia,int total_paises[][5] ) ;
void cargarMedalla( archivoCompetencia&  file_competencia, bool& salida, int& numDeportes, int& numPaises, int total_paises[196][5], int deportes[87]) ;
void mostrarMedallero(int paises[][5], int numPaises);

#endif
