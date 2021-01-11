/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C
 * PROFESOR DAVID SOLANO SOLANO
 
 * CALCULO NUMERICO DE DERIVADAS: TABLA RESPALDADA EN ARCHIVO*/
 
 /*  < DERIVADAS.C TAKES CHARACTER DATA FROM STIN AND PRINT IN UPPER CASE.>
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
    
    
 /* History Log: */
   
 /* V. 0.1 : initial */
  
  
    
/* Para correr el programa, aplique el comando en la terminal: */
/* gcc derivadas.c -Wall -lm -o derivadas */
/* -Wall : muestra advertencias o recomendaciones para mejorar el codigo */
/* -o : le da el nombre <nombre_archivo> al ejecutable */    



#include<stdio.h>
#include<math.h>
#include<stdlib.h>

/* hache CORRESPONDE AL EPSILON EN LA DEFINICION DE DERIVADA*/
#define hache 0.001

/* PROTOTIPOS DE FUNCION */
void imprimir (FILE* archiv, double x);

void bucle ( int mini, int maxi, FILE *archiv);

double calcular (double equis);

double derivar1 (double equis);



int main() {
	int minimo, maximo;
	/* AQUI SE PUEDE EDITAR EL RANGO EN DONDE SE QUIERE DERIVAR*/
	minimo = 0;
	maximo = 4;
	FILE *tabla;
	tabla = fopen("tabla.dat", "w");
	bucle(minimo, maximo, tabla); 
	fclose(tabla);
}

/* FUNCION BUCLE QUE IMPRIME EN EL ARCHIVO HASTA LLEGAR AL VALOR MAXIMO*/

void bucle ( int mini, int maxi, FILE *archiv){
	double equis = mini;
	while ( equis <= maxi ){
		imprimir(archiv, equis); 
	    equis = equis + hache;
	}
	return;
}

/* FUNCION QUE IMPRIME LOS VALORES EN UNA ARCHIVO */

void imprimir (FILE* archiv, double equis){
	fprintf(archiv, "%lf %lf %lf \n", equis, calcular(equis), derivar1(equis));
	return;
}

/* FUNCION A DERIVAR NUMERICAMENTE */
/* LA COLUMNA QUE GENERA ESTA FUNCION PUEDE SER REEMPLAZADA POR UNA LISTA DE NUMEROS OBTENIDOS
 * DIRECTAMENTE DE UN INSTRUMENTO DE MEDIDA: VOLTIMETRO, TERMOPAR, SENSOR DE PRESION, ETC.*/
double calcular (double equis) {
	double ret;
	ret  = cos(equis);
	return ret;
}

/* CALCULO APROXIMADO DE LA 1ERA DERIVADA POR LA DEFINICIÓN CON hache PEQUENO*/

double derivar1 ( double equis ) {
	double ret;
	ret = (calcular(equis+hache)-calcular(equis)) / hache;
	return ret;
	}
