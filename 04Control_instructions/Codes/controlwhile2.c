/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * PROGRAMA USO DE INSTRUCCION WHILE CON IF-ELSE*/
 
 /*  < CONTROLWHILE2.C TAKES CHARACTER DATA FROM STIN AND PRINT IN UPPER CASE.>
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
  * V. 0.1 : more commentaries added*/   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc controwhile2.c -w -lm -o controlwhile2 
 * -w : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>

int main () {
	int i, ene, eme;
	
	printf("\n\n\nPrograma FALSO VERDADERO\n\n");
	printf("\n\nEl programa correr\'a mientras se introduzca el valor verdadero\n");
	printf("\nIntroduzca un numero  ");
	scanf(" %d", &ene);
	
	/* El programa simplemente prueba la memoria del usuario al preguntar si recuerda el 
	 * valor de numero que inicialmente dio */
	/* El bucle while va correr mientras i sea 1, tambien se suele decir mientras i = TRUE */ 
	while(i){
		printf("\nCual fue el numero \?  ");
		scanf(" %d", &eme);
		if(ene == eme){
			i = 1;
			printf("\n  VERDADERO \n");
		}
		if (ene != eme){
			i = 0;
			printf("\n  FALSO \n");
		}
		}
}
