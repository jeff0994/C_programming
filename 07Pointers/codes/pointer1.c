/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO BASICO DE APUNTADORES #2*/
 
 /*  < pointer1.c>  INTRODUCCION A LOS PUNTEROS O APUNTADORES
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
 * gcc pointer1.c -Wall -o pointer
  * -o : le da el nombre <nombre_archivo> al ejecutable*/ 
#include<stdio.h>
#include<stdlib.h>
 

int main() {
	int *matriz1[2], *matriz2[2], *matriz3[2], i, j;
	
	/*ASIGNAR CON MALLOC MEMORIA AL ARREGLO DE PUNTEROS */
	
	for(i=0;i<=1;++i){
		matriz1[i] = (int *) malloc (2*sizeof(int));
		matriz2[i] = (int *) malloc (2*sizeof(int));
		matriz3[i] = (int *) malloc (2*sizeof(int));
	}

	
	
	/*INICIALIZACION MATRIZ1*/
	
	
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			*(*(matriz1+i)+j) = 1;
		}
	}
	
	/*MOSTRAR MATRIZ1*/	
	printf("LA MATRIZ1 ES: \n");	
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			printf(" %d  ", *(*(matriz1+i)+j));
		}
		printf("\n");
	}	
	
	/*INICIALIZAR MATRIZ2 */
	
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			*(*(matriz2+i)+j) = 2;
		}
	}
	
	
	/* MOSTRAR MATRIZ2 */
	printf("\nLA MATRIZ2 ES: \n");
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			printf(" %d  ", *(*(matriz2+i)+j));
		}
		printf("\n");
	}
	
	/*SUMAR MATRIZ1+MATRIZ2 Y ESCRIBIR EL RESULTADO EN MATRIZ3 */
		
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			*(*(matriz3+i)+j) = *(*(matriz1+i)+j) + *(*(matriz2+i)+j);
		}	
	}
	
	/* MOSTRAR SUMA MATRIZ3 */
	printf("\nLA MATRIZ23 = MATRIZ1 + MATRIZ2 ES: \n");
	for(i=0;i<=1;++i){
		for(j=0;j<=1;++j){
			printf("  %d  ", *(*(matriz3+i)+j));
		}
		printf("\n");
	}
		
	
	
	return(0);
	
}
