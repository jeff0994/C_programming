/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA EJEMPLO Nº 1*/
 
 /* FACTORIAL: calcutes n! of one integer n.>
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
 * gcc factorial.c -w -lm -o factorial 
 * -w : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <escala> al ejecutable*/    


#include<stdio.h>

int main () {
	int  ka, ele, factor;
		
	printf("\n\nCalculemos Factorial de un entero\n\n\n");
	printf("Escriba un valor:  ");
	scanf("%d", &ka);
	
	
	
	
	/* Calculando el factorial*/ 
	if(ka < 0) {
		printf("\n\nNo definido\n\n");
	}	
	else {
		if(ka == 0 || ka == 1) {
			factor = 1;
		}
		else {
			/* Inicializacion */
			factor = 2;
			for(ele=2; ele < ka; ++ele) {
				factor = factor*(ele+1);
			}
		}
		printf("\n\nEl valor de %d ! es :  %d\n\n", ka, factor);
	}		
	
	
}
