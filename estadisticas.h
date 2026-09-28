#ifndef ESTADISTICAS_H
#define ESTADISTICAS_H
void estadisticas(int total_paises[][5],int numPaises, int Deportes[],archivoCompetencia file_competencia);
void mostrarPaisConMasMedallas(int total_paises[][5],int numPaises);

bool indicesI( int num , int deportes[]);
void mostrarMedallasIndividuales(int numPaises, int total_paises[][5],int deportes[]) ;
void mostrarMedallasDePais(int total_paises[][5],int numPaises);

void mostrarPodioPorLetra(int Deportes[], int numPaises, archivoCompetencia file_competencia) ;
const char* retornarDeportes(int indice);
int retornarDeporteIndividual(int indice);
#endif
