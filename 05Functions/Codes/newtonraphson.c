/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * RESOLUCION NUMERICA A ECUACIONES NUMERICAS POR EL METODO DE NEWTON-RAPHSON
 */
 
 /* Application of Newton-Raphson Method for solving algebraic equations>
    Copyright (C) 2019  David Solano-Solano

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
  * V. 0.1 : initial */   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc newtonraphson.c -Wall -lm -o newtonraphson
 * -Wall : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <newtonraphson> al ejecutable*/    

#include<stdio.h>
#include<math.h>
#define ENE 20

/* Se busca resolver la ecuacion algebraica f(x) = 0 */

double fdex ( double equis ); /* f(x) */
double fprimadex( double equis ); /* f'(x) */
double newtonraphson( double equis ); /* Funcion algoritmo de Newton-Raphson */

int main () {
	
	/*Aquí se inicializa la x0, la primera aproximación */ 
	double x0=0, x;
	int i;
	
	printf("Programa Sencillo de la aplicacion del Metodo del Newton-Raphson\n\n\n");
	printf("Aproximacion Inicial:  %22.9lf\n", x0);
	for(i = 0; i < ENE; ++i) {
		x = newtonraphson(x0);
		printf("%3d era aproximacion:  %22.9lf\n", i+1, x);
		x0 = x;
	}
	printf("\n\nDavid Solano-Solano \t Universidad de Costa Rica 2019\n\n\n");
}


double fdex ( double equis ) { 
	/* En este ejemplo, se va resolver f(x) = x-cos(x) */
	return( equis - cos(equis) );
}
double fprimadex( double equis ) {
	/* La primera derivada es: f'(x) = 1 + sin(x) */
	return( 1 + sin(equis) );	
}
double newtonraphson( double equis ){ 
	return( equis - (fdex(equis)/fprimadex(equis)) );
}
