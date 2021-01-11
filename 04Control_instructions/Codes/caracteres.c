/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * Instrucciones de control: PROGRAMA LECTURA DE CARACTERES*/
 
 /*  < CARATERES.C TAKES CHARACTER DATA FROM STIN AND PRINT IN UPPER CASE.>
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
  * V. 0.1 : initial
  * V. 0.2 : more commetaries added*/   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc caracteres.c -w -lm -o caracteres
 * -w : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>

/* Header con funciones para manejo de caracteres */
#include<ctype.h>

int main () {
	
	/* Se daclara nombre como una variable de formacion con un maximo de 80 espacios */
	char nombre[80];
	
	/* Variables de conteo para la instruccion for*/
	int i, j;
	
	printf("\n\nEscriba una frase corta (max. 80 caracteres)...\n");
	/* Bucle for sencillo que se repite hasta que el usuario introduzca el caracter de nueva linea con ENTER*/
	for (i=0; (nombre[i] =getchar()) != '\n'; ++i) ;
	
	/* j adquiere el valor del ultimo valor de i, que es el tamaño de la cadena de caracteres*/
	j = i;
	
	
	/* Un bucle sencillo que corre hasta el valor de j y muestra en STOUT la cadena "nombre" en mayusculas  */
	for (i=0; i < j; ++i)
		putchar(toupper(nombre[i]));
	
	}
