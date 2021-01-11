/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA APLICACION DE ESTADISTICAS*/
 
 /*  <estadistica.c>  INTRODUCCION A LOS PUNTEROS O APUNTADORES MEDIANTE CALCULOS ESTADISTICOS
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
  * V. 0.1 : initial */   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc estadistica1.c -wall -lm -o estadistica1 
 * -wall : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <nombre_archivo> al ejecutable*/ 
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>


static double *poblation;

static double ENE;

static double mean;

static double variance;

static double stddes;

static FILE *filer; 

void procpoblation ();

void calculatemean();

void calculatevar();

void sortpoblation();

int main () {
	/* Archivo en donde están los datos en forma de columna*/	
	filer = fopen("estats.dat", "r");
	procpoblation();
	sortpoblation();
	calculatemean();
	calculatevar();
	fclose(filer);
	printf("\n\nNumero de datos = %lf \nMedia Aritmetica = %lf \nVarianza = %lf \nDesviancion estandar = %lf", ENE, mean, variance, stddes);
	return(0);
}

void procpoblation () {
	int i=0;
	char inter=0;
	
	/*Lee el numero de lineas */
	while( (inter = fgetc(filer)) != EOF){
		if( inter == '\n' ){
			i=i+1; 	
		}
	}
	ENE = i;
	poblation = (double *) malloc (ENE*sizeof(double));
	
	/*Se devuelve al inicio del archivo*/
	rewind(filer);
	
	
	for(i=0; i<=ENE; i++){
		fscanf(filer, "%lf",  poblation+i);
	}
	return;
}



void calculatemean() {
	int i;
	double suma=0;
	for(i=0;i<=ENE-1;++i){
		suma = suma + *(poblation+i);
	}
	mean = suma/ENE;
	return;
}

void calculatevar(){
	int i;
	double suma;
	for(i=0;i<=ENE-1;++i){
		suma = suma + pow( mean - *(poblation+i), 2  );
	}
	variance = suma/(ENE-1);
	stddes = sqrt(variance);
	return;
}

void sortpoblation() {
	int i,j;
	double inter, *arreglo;
	
	arreglo = (double *) malloc(ENE*sizeof(double));
	
	printf("\nLista sin ordenar:\n");
	for(i=0;i<=ENE-1;++i){
	*(arreglo+i) = *(poblation+i);
	printf("%lf\n", *(poblation+i));	
	}
	
    for (i = 0; i < ENE; i++) {
        for (j = 0; j < (ENE - i - 1); j++){
            if (*(arreglo + j) > *(arreglo + j + 1)){
                inter = *(arreglo + j);
                *(arreglo + j)= *(arreglo + j + 1 );
                *(arreglo + j + 1)= inter;
            }
        }
    }
    
    printf("\nLista ordenada:\n");
	for(i=0;i<=ENE-1;++i){
		*(poblation+i) = *(arreglo+i); 
		printf("%lf\n", *(poblation+i));	
	}
    return;	
}

