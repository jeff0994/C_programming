/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * Instrucciones de control: ejemplo instrucciones if-else*/
 
 /*  < CONTROLIFELSE.C SHOWS HOW IF-ELSE WORKS.>
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
  
    
 * Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc controlifelse.c -wall -o controlifelse
 * -wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>

/* Programa que calcula la imagen de la funcion definida por trozos:
 * 
 * f(x) = 0 , x<0
 * 		= 1/x+1, 0<=x<=1
 * 		= 3/2 - x, x>1*/ 
 
 
int main () {
  /* Variables tipo double precission para manejar calculos matematicos*/ 	
  double equis, efe;
  
  /* Pide al usuario introducir en STIN un valor para la variable equis*/
  printf("\n\n\nFuncion definida a trozos...\nEscriba el valor de x:  ");
  scanf("%lf", &equis);
  
  /* x < 0 -> f(x) = 0*/
  if( equis < 0 ) {
	efe = 0;  
  }
  
  /* Ahora: x > 0*/
  else {
	/* 0<=x<=1 */  
	if( equis <= 1 ){
		efe = 1/(equis+1);
	}
	/* El resto de valores de x, es decir, x > 1*/ 
	else{
		efe = 1.5 - equis;	
	}
  }
  
  printf("\nEl valor de la imagen es: f(x) = %lf\n\n\nFIN DEL PROGRAMA", efe);
  
  
}
