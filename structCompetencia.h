#ifndef STRUCTCOMPETENCIA_H
#define STRUCTCOMPETENCIA_H

struct competidores{
	int paises [16];
	int tl;
};

struct archivoCompetencia {
	competidores competencia[87];
	int deporte_medallas[87][3];
	tm fechaCreacion;
	int legajo;
};		

#endif
