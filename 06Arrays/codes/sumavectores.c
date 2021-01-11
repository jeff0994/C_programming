/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA LECTURA DE UNA FORMACION*/
 
 /* sumavectores.c suma dos vectores definidos en una formacion.>
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
 * gcc sumavectores.c -Wall -o sumavectores 
 * -Wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define ENE 3 /*Dimension vectores */
#define EME 30 /* Tamano maximo cadena de caracteres*/


void leercadena (char vectorid[]);

void leervector( double vector[], char vectorid[] ) ;
	
void mostrarvector( double vector[], char vectorid[] );

void sumarvectores( double suma[],  double vector1[], double vector2[] );


int main(){
	double uvector[ENE], vvector[ENE], wvector[ENE]; /* declaracion arreglo vector de ENE dimensiones */
	char uvectorid[EME], vvectorid[EME], wvectorid[EME]; /* declaracion arreglo de cadena de caracteres que identifica a uvector */
	
	printf("\n\nEscriba el simbolo que identifica al vector 1: ");
	leercadena(uvectorid); /* lee la cadena de caracteres que identifica al vector */
	
	printf("\n\nEscriba el simbolo que identifica al vector 2: ");
	leercadena(vvectorid); /* lee la cadena de caracteres que identifica al vector */
	
	printf("\n\nEscriba el simbolo que identifica a la suma de vector 1 y vector 2: ");
	leercadena(wvectorid);
	
	leervector(uvector, uvectorid); /*lee el vector en forma interactiva */
	mostrarvector(uvector, uvectorid);
	
	leervector(vvector, vvectorid);
	mostrarvector(vvector, vvectorid); 

	sumarvectores(wvector, uvector, vvector); /* suma uvector + vvector */

	mostrarvector(wvector, wvectorid); /*muestra wvector */
}


void leercadena (char vectorid[]){
	int i,j;
	/* Bucle corre hasta que se da "nueva linea" o "ENTER"*/
	for(i=0; (vectorid[i]=getchar()) != '\n'; ++i);
	j=i;
	/* Bucle para rellenar los espacios en blanco con valores nulos*/
	for(i=j; i<=EME-1; ++i){
		vectorid[i]='\0';
		}
	return;
	}

void leervector( double vector[], char vectorid[] ) {
	int i;
	printf("\nIntroduzca las componentes del vector %s \n", vectorid);
	for( i = 0; i <= ENE - 1; ++i ){
		printf("\n%s_%d = ", vectorid, i);
		scanf("%lf", &vector[i]);
	}
	return;
	}
	
void mostrarvector( double vector[], char vectorid[] ){
	int i;
	printf("\nSe ha introducido el vector con componentes: \n");
	for( i = 0; i <= ENE - 1; ++i ){
		printf("\n%s [ %d ] = %lf \n", vectorid , i, vector[i]);
	}
	}


void sumarvectores(double suma[],  double vector1[], double vector2[] ) {
	int i;
	for(i = 0; i<=ENE-1; ++i) {
		suma[i] = vector1[i]+vector2[i];
		}
	return;
	}
