/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA FUNCIONES ANFITRIONAS Y FUNCIONES HUESPED*/
 
 /*  <modulo.c>  INTEGRACION NUMERICA - SUBRUTINAS DE INTEGRACION
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
  
    
 
#include<stdio.h>
#include<math.h>
#include"integracion.h"

/* AQUI SE DEFINE EL PARTICIONAMIENTO DEL INTERVALO*/

#define ENE 10000


/* SUBRUTINA DE REGLA DE LOS TRAPECIOS */

double trapecios( double (*funcionparaintegrar)( double equis ) , double inf, double sup) {
	int i;
	double suma, epsilon, primero, ultimo, final;
	epsilon = (sup - inf) / ENE;
	primero = (*funcionparaintegrar)( inf );
	ultimo  = (*funcionparaintegrar)( sup );
	suma = 0; 
	for(i=1; i < ENE; ++i ){
		suma = suma + 2 * (*funcionparaintegrar)( inf + (double)(i) * epsilon );
	}
	final = 0.5*epsilon*(primero+ultimo+suma);
	return(final);
}

/* SUBRUTINA DE REGLA DE SIMPSON */


double simpson( double (*funcionparaintegrar)( double equis ) ,  double inf, double sup) {
	int i,j;
	double sumaimpar, sumapar, epsilon, primero, ultimo, final;
	epsilon = (sup - inf) / ENE;
	primero = (*funcionparaintegrar)( inf );
	ultimo  = (*funcionparaintegrar)( sup );
	
	/* SUMA  DE INDICES IMPARES, COMIENZA EN X_1 = INF + EPSILON */ 
	sumaimpar = 0;
	i = 1;
	j = 1;
	while(j<ENE) {
		sumaimpar = sumaimpar + 4 * (*funcionparaintegrar)( inf + (double)(j) * epsilon );
		j = 2*i+1; 
		i = i+1;
		
	}
	
	/* SUMA DE INDICES PARES, COMIENZA EN X_2 = INF + 2*EPSILON */
	
	sumapar = 0;
	i = 2;
	j = 2; 
	while(j < ENE){
		sumapar = sumapar + 2 * (*funcionparaintegrar)( inf + (double)(j) * epsilon );
		j = 2*i;
		i = i+1;
	}
	
	
	final = epsilon*(primero+ultimo+sumapar+sumaimpar)/3.0;
	return(final);
}


/* LA FUNCION TIENE QUE ESTAR DEFINIDA EN EL INTERVALO!!!*/
double paraintegrar ( double equis ){
	double inter;
	inter = sqrt(equis);
	return ( inter );
}
