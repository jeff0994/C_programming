/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA MEJORA PROGRAMA DE FUNCION SENO*/
 
 /* SEN02.C CALCULA EL VALOR DE UN ANGULO EN GRADOS.>
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
 * gcc seno2.c -Wall -lm -o seno2 
 * -w : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <seno> al ejecutable*/    


#include<stdio.h>
#include<math.h>
#define PI 3.14151
#define ENE 10

/* PROTOTIPOS DE FUNCION */

double signoangulo ( double angulo );
double menorangulo ( double angulo );
double rangoangulo ( double angulo );
double factorial ( int ene );

double serie0 ( double x );
double seriepi_cuartos ( double x );
double seriepi_medios ( double x );
double calcularseno( double angulo );



int main () {
	double angle, angle1, angle2;
		
	printf("\n\nCalculemos sen(x) para cualquier angulo en grados\n\n\n");
	printf("Escriba un angulo:  ");
	scanf("%lf", &angle);
	printf("\n\nUsted introdujo el valor de....  %lf\n", angle);
	printf("\n\nEl signo es....  %lf\n", signoangulo(angle));
	angle1 = menorangulo(signoangulo(angle)*angle);
	printf("Este angulo equivale a .... %lf\n", angle1);
	/*SELECCION DEL RANGO */
	angle2 = rangoangulo(angle1);
	printf("Al calcular seno, este angulo equivale a %lf\n", angle2);
	printf("Al aproximar se obtiene sen(%lf) = %lf\n", angle2, calcularseno(angle2) );
	
	return 0;
}


double signoangulo ( double angulo ) {
	if (angulo >= 0) {
		return(1.0);
	}
	else {
		return(-1.0);
	}
}

double menorangulo ( double angulo ) {
	int i=1;
	double inter;
	while (i) {
		
		if(angulo < 360.0) {
			inter = angulo;
			i = 0;
		}
		else{
			inter = angulo - 360.0;
			angulo = inter;
			i = 1;	
		}
	}	
	return(inter);
}

double rangoangulo ( double angulo ) {
	double inter;
	if(angulo >= 0.0 && angulo <= 90.0) {
		inter = angulo;
	}
	else{
		if(angulo > 90.0 && angulo <= 180.0) {
			inter = (180.0-angulo);
		}
		else {
			if(angulo > 180.0 && angulo <= 270.0) {
				inter = -1.0*(angulo-180.0);
			}
			else {
				inter = -1.0*(360.0-angulo);
			}
		}
	}
	return(inter);
}

double factorial ( int ene ) {
	int ele, factor;
	
	if(ene == 0 || ene == 1) {
		factor = 1;
	}
	else {
	/* Inicializacion */
		factor = 2;
		for(ele=2; ele < ene; ++ele) {
			factor = factor*(ele+1);
		}
	}
	return( (double)(factor) );
}

double serie0 ( double x ){
	int ii;
	double suma;
	suma = x;
	for(ii=1;ii<=ENE;++ii) {
		suma = suma + pow(-1, (double)(ii))*pow(x,(double)(2*ii+1))/factorial(2*ii+1);
	}
	return(suma);
}		


double seriepi_cuartos ( double x ){
	int ii;
	double suma, suma1, suma2;
	suma1 = 1;
	suma2 = x - 0.25*PI;
	for(ii=1;ii<=ENE;++ii) {
		suma1 = suma1 + pow(-1,(double)(ii))*pow(x - 0.25*PI,(double)(2*ii))/factorial(2*ii);
	}
	for(ii=1;ii<=ENE;++ii) {
		suma2 = suma2 + pow(-1,(double)(ii))*pow(x - 0.25*PI,(double)(2*ii+1))/factorial(2*ii+1);
	}
	suma = (sqrt(2)/2)*(suma1+suma2);
	return(suma);
}		

double seriepi_medios ( double x ){
	int ii;
	double suma;
	suma = 1;
	for(ii=1;ii<=ENE;++ii) {
		suma = suma + pow(-1,(double)(ii))*pow(x - 0.5*PI, (double)(2*ii))/factorial(2*ii);
	}
	return(suma);
}		

double calcularseno ( double angulo ) {
	double signo, inter, resultado;
	signo = signoangulo(angulo);
	inter = signo*angulo;
	if(inter >= 0 && inter <= 22.5000 ) {
		printf("\nangulo menor a 22.5\n");
		resultado = serie0(inter*PI/180);
	}
	else {
		if(inter > 22.5000 && inter <= 67.5000 ) {
			printf("\nangulo entre  22.5 y 67.5\n");
			resultado = seriepi_cuartos(inter*PI/180);
		}
		else {
			printf("\nangulo mayor a 67.500\n");
			resultado = seriepi_medios(inter*PI/180);
		}
	}
	return(resultado);
}
