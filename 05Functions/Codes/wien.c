/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * RESOLUCION NUMERICA A ECUACIONES NUMERICAS POR EL METODO DE NEWTON-RAPHSON
 * DEMOSTRACIÓN DE LA LEY DE WIEN */
 
 /* Application of Newton-Raphson Method for solving algebraic equations
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
 * gcc wien.c -Wall -lm -o wien
 * -Wall : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <wien> al ejecutable*/    

#include<stdio.h>
#include<math.h>
#define hplanck 6.62607015E-34
#define kboltzmann 1.38064852E-23
#define clight 	299792458
#define ENE 150

/* Se busca resolver la ecuacion algebraica f(x) = (x - 5)*exp(-x) + 5 = 0 */



double fdex ( double equis ); /* f(x) */
double fprimadex( double equis ); /* f'(x) */
double newtonraphson( double equis ); /* Funcion algoritmo de Newton-Raphson */

int main () {
	
	/*Aquí se inicializa la x0, la primera aproximación */ 
	double x0=5, x;
	int i;
	
	printf("Programa de aplicacion del Metodo del Newton-Raphson\n\n\n");
	printf("Demostracion de la Ley de Wien a partir de la Ley de Radiacion de cuerpo negro de Planck\n\n\n");
	printf("Ecuacion: f(x) = (x-5)*exp(x) + 5 = 0 \t \t x = (hc)/(k*T*lambda)\n\n");
	printf("Iteracion \t \t Solucion ecuacion \t Constante de Wien (m*K) \n\n");
	printf("Aproximacion Inicial: \t %lf \t \t %10.8lf \n", x0, hplanck*clight/(kboltzmann*x0)	);
	for(i = 0; i < ENE; ++i) {
		x = newtonraphson(x0);
		printf("%3d era aproximacion: \t %lf \t \t %10.8lf \n", i+1, x, hplanck*clight/(kboltzmann*x)   );
		x0 = x;
	}
	printf("\n\nDavid Solano-Solano \t Universidad de Costa Rica \t 2019\n\n\n"); 
}


double fdex ( double equis ) { 
	/* En este ejemplo, se va resolver f(x) = (x-5)*exp(-x)+5 */
	return( (equis-5)*exp(equis) + 5 );
}
double fprimadex( double equis ) {
	/* La primera derivada es: f'(x) = exp(-x)*(6.0-x) */
	return( exp(equis)*(4.0+equis) );	
}
double newtonraphson( double equis ){ 
	return( equis - (fdex(equis)/fprimadex(equis)) );
}
