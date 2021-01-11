/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * RESOLUCION NUMERICA A ECUACIONES NUMERICAS POR EL METODO DE NEWTON-RAPHSON
 * EFICIENCIA DE UN RECTIFICADOR DE MEDIA ONDA */
 
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
 * gcc rectificador1.c -Wall -lm -o rectificador1
 * -Wall : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <rectificador1> al ejecutable*/    

#include<stdio.h>
#include<math.h>
#define PI 3.141592653589793
#define ENE 50

/* Se busca resolver la ecuacion algebraica f(x) = exp(-x/(R*C) ) - cos ( 2*PI*frec*x ) = 0 */

/* Resistencia = 3000 ohm , Capacitancia = 20000 micro farad , frec = 60 Hz*/
static double R = 3, C = 0.02, frec= 60;

double fdex ( double equis ); /* f(x) */
double fprimadex( double equis ); /* f'(x) */
double newtonraphson( double equis ); /* Funcion algoritmo de Newton-Raphson */

int main () {
	
	/*Aquí se inicializa la x0, la primera aproximación */ 
	double x0=3.0/(4.0*frec), x;
	int i;
	
	printf("Programa de aplicacion del Metodo del Newton-Raphson\n\n\n");
	printf("Eficiencia de un rectificador de Media Onda\n\n\n");
	printf("Aproximacion Inicial:  %lf\n", x0);
	for(i = 0; i < ENE; ++i) {
		x = newtonraphson(x0);
		printf("%3d era aproximacion:  %lf  dis = %lf %c \n", i+1, x, 100*fabs( (float) (1-exp(-x/(R*C))) ), '%'  );
		x0 = x;
	}
	printf("\n\nDavid Solano-Solano \t Universidad de Costa Rica \t 2019\n\n\n"); 
}


double fdex ( double equis ) { 
	/* En este ejemplo, se va resolver f(x) = exp(-x/(R*C) ) + cos (2*PI*frec*x) */
	return( exp(-equis/(R*C) ) + cos (2*PI*frec*equis) );
}
double fprimadex( double equis ) {
	/* La primera derivada es: f'(x) = -(1/(R*C))*exp(-x/(R*C) ) - (2*PI*frec) * sin (2*PI*frec*x) */
	return( (1/(R*C))*exp(-equis/(R*C) ) - (2*PI*frec) * sin (2*PI*frec*equis) );	
}
double newtonraphson( double equis ){ 
	return( equis - (fdex(equis)/fprimadex(equis)) );
}
