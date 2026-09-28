#ifndef ARCHIVO_H
#define ARCHIVO_H

struct archivoCompetencia;

void crear_archivo(char fechaFormateada[],archivoCompetencia file_competencia);
void actualizar(char fechaFormateada[], archivoCompetencia file_competencia, int total_paises[][5]);
void abrir(char fechaFormateada[], archivoCompetencia &  file_competencia, int total_paises[][5],bool controlCompetencia, bool & c2, bool & c);

void inicializarPaises(int paises[196][5]);
void actualizarPaises(int total_paises[196][5], archivoCompetencia& file_competencia, int & numPaises);
void extraer(const archivoCompetencia file_competencia, int deportes[86]);
#endif
