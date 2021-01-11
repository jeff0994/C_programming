/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * PROGRAMA USO DE INSTRUCCION WHILE*/
 
 /*  < CONTROLWHILE.C TAKES CHARACTER DATA FROM STIN AND PRINT IN UPPER CASE.>
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
  * V. 0.2 : more commentaries added */   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc controlwhile.c -w -lm -o controlwhile 
 * -w : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>
#include<math.h>


int main () {
	double i, limite, sucene;
	
	printf("\n\n\nPrograma que imprime tabla con valores de otra sucesion\n\n");
	printf("\nIntroduzca el numero de iteraciones  ");
	scanf("%lf", &limite);
	i=0;
	
	/* Calcula con el bucle for los valores de la sucesión S_n = (n+1)^(-1/2) y los
	 * imprime en pantalla. Comienza con n=1 y termina con n=limite (valor dado en STIN) */
	while(i <= limite){
		sucene = sqrt( 1.0 /(i+1.0) );
		printf("\n%5lf %10.5lf\n", i, sucene);
		i= i + 1;
		}
}
