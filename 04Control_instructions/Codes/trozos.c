/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA FUNCION DEFINIDA A TROZOS*/
 
 /*  < TROZOS.c PRINT FILE WITH TABLE OF VALUES OF PERSONALIZE FUNCTION.>
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
  * v. 0.2 : function trozos corrected, more commentaries added*/   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc trozos.c -wall -o trozos 
 * -wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    




#include<stdio.h>
#include<math.h>
#define ENE 250


void trozosinterval (double a, double b, FILE *archivo);
	
double trozos ( double equis ) ;


int main(){
	FILE *archive;
	double inferior, superior;
	archive = fopen("trozos.dat", "w+");
	printf("\n\n\nPROGRAMA PARA VER UNA FUNCION DEFINIDA A TROZOS\n\n");
	printf("\n\nEscriba el limite inferior del intervalo:  ");
	scanf("%10lf",  &inferior);
	printf("\n\nEscriba el limite superior del intervalo:  ");
	scanf("%10lf",  &superior);
	printf("\n\n\nLA TABLA ESTA EN EL ARCHIVO \"trozos.dat\" ");
	printf("\n\n\nCORRA EL COMANDO: gnuplot\n\nluego:\nplot 'trozos.dat' \n\n\nFIN");
	trozosinterval(inferior, superior, archive);
	fclose(archive);
}

/* Esta funcion imprime en el archivo una tabla con ENE valores de la funcion de personalizada "trozos" */

void trozosinterval (double a, double b, FILE *archivo) {
	int i;
	double x=a, eps;
	eps = (b-a)/ENE;
	for (i=1;i<=ENE+1;++i){
		fprintf(archivo, "%10lf %10lf\n", x, trozos(x));
		x=a+i*eps;
		}
	return;
	}

/* Esta funcion calcula las imagenes de 
 * f(x) = -30, x<-10
 * 		= 3x, -10<=x<=10 
 * 		= 30 x>10 */
 
  
double trozos ( double equis ) {
	double funvariar;
	if (equis < -10 ) {
		funvariar = -30; 
	}
	else {
	  if (equis >= -10 && equis < 10){ 
	    funvariar = 3*equis;
	  }
	  else {
		  funvariar = 30;
	  }
	}	
	return(funvariar);	
}
