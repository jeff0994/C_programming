/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA FUNCIONES ANFITRIONAS Y FUNCIONES HUESPED*/
 
 /*  <main.c>  INTEGRACION NUMERICA - PRINCIPAL
  * 					
    Copyright (C) 2017  David Solano-Solano

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
 * gcc -Wall main.c modulo.c -o integrar -lm
 * -Wall : muestra advertencias
 * -o : le da el nombre <integrar> al ejecutable*/ 
 
#include<stdio.h>
#include"integracion.h"

/* PROTOTIPE LAS FUNCIONES QUE USTED DESEE AQUI*/ 


int main() {
	double liminf, limsup;
	
	printf("\n\n\nINTEGRACION NUMERICA  \n\nI = int(sqrt(x),x,inf,sup) \n\nUNIVERSIDAD DE COSTA RICA - ESCUELA DE FISICA\n\n\n");
	printf("\n\nEscriba el limite inferior: ");
	scanf("%lf", &liminf);
	printf("\nEscriba el limite superior:  ");
	scanf("%lf", &limsup);
	/* PUEDE CAMBIAR EL ARGUMENTO PARAINTEGRAR POR LA FUNCIONES QUE USTED QUIERA */
	printf("\n\nSegun regla de trapecios, I =  %20.10lf", trapecios( paraintegrar, liminf, limsup ) );
	printf("\n\nSegun regla  de  Simpson, I =  %20.10lf \n\n\n", simpson( paraintegrar, liminf, limsup ) );

	return 0;
}
