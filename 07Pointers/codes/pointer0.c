/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO BÁSICO DE LOS APUNTADORES #1*/
 
 /*  < pointer0.c>  INTRODUCCION A LOS PUNTEROS O APUNTADORES
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
 * gcc pointer0.c -w -lm -o pointer0
 * -w : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/ 
#include<stdio.h>
#include<stdlib.h>
 

int main() {
	int i, j, aa=10, bb=34;
	double equis=8.314, ye=-0.82;
	double uvector[5];
	
	int *paa, *pbb;
	double *pequis, *pye;
	double *puvector;
	char *frase;
	
	paa = &aa;
	pbb = &bb;
	
	printf("Con declaracion de variable, el valor de aa es %d y de bb es %d \n\n", aa, bb);
	printf("Con puntero, el valor de aa es %d y de bb es %d \n\n", *paa, *pbb);
	
	pequis = &equis;
	pye = &ye;
	
	printf("\nCon declaracion de variable, el valor de equis es %lf y de ye es %lf \n\n", equis, ye);
	printf("Con puntero, el valor de equis es %lf y de equis es %lf \n\n", *pequis, *pye);
	
	uvector[0] = 1;
	uvector[1] = 2;
	uvector[2] = -5;
	uvector[3] = 4;
	uvector[4] = 9;
	
	puvector = (double *) malloc(5*sizeof(double));
	
	for(i=0;i<5;++i){
		printf("Con declaracion de constante: uvector_%d = %lf\n", i, uvector[i]);
	}
	
	for(i=0;i<5;++i){
		*(puvector+i) = uvector[i];
		printf("Con puntero: uvector_%d = %lf\nVea el valor del puntero: %X\n", i, *(puvector+i), (puvector+i));
	}
	
	
	frase = (char *) malloc (80*sizeof(char));
	printf("\nEscriba una frase o palabra:\n");
	for(i=0; ( *(frase+i) = getchar() ) != '\n'; ++i);
	printf("\nUsted escribio:\n");
	j=i;
	for (i=0; i < j; ++i){
		putchar(*(frase+i));
	}
	
	return(0);
	
}
