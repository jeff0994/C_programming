/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA FUNCION DE HEAVISIDE*/
 
 /*  < HEAVISIDE.C GENERATES TABLE WITH HEAVISIDE FUNCTION OVER INTERVAL.>
    Copyright (C) 2018  David Solano-Solano

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses. */
    
    
 /* History Log:
  * 
  * V. 0.1 : initial 
  * V. 0.2 : more commentaries added*/   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc heaviside.c -wall -o heaviside
 * -wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>
#include<math.h>
#define ENE 500


void heavisideinterval (double a, double b, FILE *archivo);
	
double heaviside ( double equis ) ;
int main(){
	FILE *archive;
	double inferior, superior;
	archive = fopen("heaviside.dat", "w+");
	printf("\n\n\nPROGRAMA PARA VER LA FUNCION DE HEAVISIDE\n\n");
	printf("\n\nEscriba el limite inferior del intervalo:  ");
	scanf("%10lf",  &inferior);
	printf("\n\nEscriba el limite superior del intervalo:  ");
	scanf("%10lf",  &superior);
	printf("\n\n\nLA TABLA ESTA EN EL ARCHIVO \"heaviside.dat\" ");
	printf("\n\n\nCORRA EL COMANDO: gnuplot\n\nluego: \n\nplot 'heaviside.dat' \n\n\nFIN");
	heavisideinterval(inferior, superior, archive);
	fclose(archive);
}

/* Esta funcion imprime en el archivo una tabla con ENE valores de la funcion de Heaviside */
void heavisideinterval (double a, double b, FILE *archivo) {
	int i;
	double x=a, eps;
	eps = (b-a)/ENE;
	for (i=1;i<=ENE+1;++i){
		fprintf(archivo, "%10lf %10lf\n", x, heaviside(x));
		x=a+i*eps;
		}
	return;
}

/* Esta función calcula la image de la funcion Heaviside 
 * H(x) = 0 , x < 0
        = 1 , x >= 0*/
        
        															
double heaviside ( double equis ) {
	double funvariar;
	if (equis < 0 ){
		funvariar = 0;
	}
	else {
		funvariar = 1;
	}	
	return(funvariar);	
}
