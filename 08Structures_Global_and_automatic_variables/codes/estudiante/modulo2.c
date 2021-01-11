/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA VARIABLES EXTERNAS*/
 
 /*  <modulo2.c>  INTRODUCCION VARIABLES EXTERNAS
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
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "fs0733.h"


/* EN ESTE MODULO SE DEFINEN LAS FUNCIONES PROTOTIPADAS EN FS0733.H */


/* AQUI SE DECLARA LA VARIABLE DEFINIDA POR EL USUARIO DE TIPO ESTUDIANTE CON NOMBRE ASIGANO ALUMNO.
 * 
 * SE LE DA LA CLAVE EXTERN PORQUE SE VA A DEFINIR OTRO MODULO DEL PROGRAMA 
 * NOTE TAMBIEN QUE AQUI SOLO SE DECLARA, NO SE INICIALIZA */
 
  
extern estudiante alumno;	

/* SE DEFINEN LAS FUNCIONES PROTOTIPADAS EN FS0733.H*/

void leerdatos(){
	int i;
	printf("\n\nEscriba su nombre:  ");
	for(i=0; (alumno.nombre[i]=getchar()) != '\n'; ++i);
	printf("\nEscriba su carne:   ");
	for(i=0; (alumno.carne[i]=getchar()) != '\n'; ++i);
	return;
}


void mostrardatos(){
	int i, numcadena;
	numcadena = strlen(alumno.nombre);
	printf("\n\nSu nombre es:  ");
	for(i=0; i<numcadena; ++i){
		putchar(alumno.nombre[i]);
		}
	printf("\nSu carne es:  ");
	for(i=0; i<8; ++i){
		putchar(alumno.carne[i]);
		}
	printf("\n\n");	
	return;
}
