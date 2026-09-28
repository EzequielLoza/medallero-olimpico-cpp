#ifndef DEPORTES_H
void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();

const char* retornarDeportes(int indice);
int retornarDeporteIndividual(int indice);
#endif
