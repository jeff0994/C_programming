/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 */
 
 /*  FUNCION SENO: calcutes sin(x) by power expansion.>
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
 * gcc seno.c -Wall -lm -o seno 
 * -w : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <seno> al ejecutable*/    

#include<stdio.h>
#include<math.h>


/* ESTE PROGRAMA APROXIMA LOS VALORES DE LA FUNCION SENO PARA VALORES CERCANOS A 0 RADIANES */
int main () {
	int N, ENE,  ele,  ene, factor;
	double equis, suma;
	
	printf("\n\nCalculemos sen(x) por expansion de potencias\n\n\n");
	printf("\n\n\nEscriba el valor de x en radianes:  ");
	scanf("%lf", &equis);
	printf("\n\n\nEscriba el numero de terminos de la expansion:  ");
	scanf("%d", &N);
	
	if( N%2 == 0 ) {
		ENE = N-1;
	}
	else{
		ENE = N;
	}
	
	printf("\n\n\nSe calculara con el termino elevado a %d potencia \n\n\n", 2*ENE+1);
	/* Inicializando la suma */ 
	
	suma = equis;
	
		
	
	for( ene = 1; ene <= ENE; ++ene) {
	/* Inicializacion del factorial*/
		factor = 2;
	
	/* Inicio del calculo del factorial*/ 
		for(ele=2; ele < 2*ene+1; ++ele) {
				factor = factor*(ele+1);
		}
		
	/* Fin de calculo de factorial */
	
	/* Comprobacion de calculos */ 
	printf("Comprobando terminos...\n");
	printf("%d ! = %d \n", 2*ene+1, factor);	
	printf("x^(%d)/%d ! = %30.20lf\n\n", 2*ene+1, 2*ene+1, 	pow(equis, (double)(2*ene+1)) / (double)(factor) );
	suma = suma + pow(-1, (double)(2*ene+1)) * pow(equis, (double)(2*ene+1)) / (double)(factor); 		
	}
	
	printf("\n\n\nEl valor de sen(%lf) es : %30.20lf \n\n\n", equis, suma );
		
}
