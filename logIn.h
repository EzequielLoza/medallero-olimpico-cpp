#ifndef LOGIN_H
#define LOGIN_H

//LOGIN

bool logIn(int & nroLegajo);
void dibujarCuadro(int x1,int y1,int x2,int y2);
void gotoxy(int x,int y);
bool esCapicua(int x, int& n);
void Generarcontrasena(int nroLegajo, char password[], int& auxContra, int& contrasena,int& contadorContrasenia);
bool esNumero(char texto[6]);
int cantDigitos(char arreglo[6], int TL);
void sacarDigitos(char arreglo[],int TL);
void borrarPantalla();

#endif
