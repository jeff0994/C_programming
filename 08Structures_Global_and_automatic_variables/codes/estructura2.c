/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO DE ESTRUCTURAS #2*/
 
 /*  < ESTRUCTURA2.C Uso de estructuras para calcular puntos en distintos sistemas de coordenadas>
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
 * gcc ejemplo4.c -w -lm -o escala 
 * -w : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <nombre_archivo> al ejecutable*/ 


#include<stdio.h>
#include<ctype.h>
#include<math.h>

#define ENE 3
#define EME 30

struct vector3 {
char symbolo[EME];
double cartesian[ENE];
double cilyndrical[ENE];
double espherical[ENE];
} vector0;


void leercadena (  );

void leervector (  );
	
void mostrarrectangular (  );

void mostrarcilyndrical (  );

void mostrarespherical (  );


int main () {
	
	printf("\n\nIntroduza el simbolo para el vector: ");
	leercadena();
	
	leervector();
	
	mostrarrectangular();
	
	mostrarcilyndrical();
	
	mostrarespherical();
	
	return(0);
}


void leercadena (  ) {
	int i,j;
	/* Bucle corre hasta que se da "nueva linea" o "ENTER"*/
	for(i=0; (vector0.symbolo[i]=getchar()) != '\n'; ++i);
	j=i;
	/* Bucle para rellenar los espacios en blanco con valores nulos*/
	for(i=j; i<=EME-1; ++i){
		vector0.symbolo[i]='\0';
	}
	return;
	}

void leervector(  ) {
	int i;
	printf("\nIntroduzca las componentes cartesianas (x,y,z) del vector %s \n", vector0.symbolo);
	for( i = 0; i <= ENE - 1; ++i ){
		printf("\n%s_%d = ", vector0.symbolo, i);
		scanf("%lf", &vector0.cartesian[i]);
	}
	return;
	}
	
void mostrarrectangular(  ) {
	int i;
	printf("\nSe ha introducido el vector con componentes cartesianas: \n");
	for( i = 0; i <= ENE - 1; ++i ){
		printf("\n%s [ %d ] = %lf \n", vector0.symbolo , i, vector0.cartesian[i]);
	}
	}
void mostrarcilyndrical(  ) {
	int i;
	vector0.cilyndrical[0] = sqrt( pow(vector0.cartesian[0],2)+pow(vector0.cartesian[1],2) );
	vector0.cilyndrical[1] = atan(vector0.cartesian[1]/vector0.cartesian[0]);
	vector0.cilyndrical[2] = vector0.cartesian[2];
	printf("\nEn coordenas cilindricas (r,theta,z) es: \n");
	for( i = 0; i <= ENE - 1; ++i ){
	printf("\n%s [ %d ] = %lf \n", vector0.symbolo , i, vector0.cilyndrical[i]);
	}
}

void mostrarespherical(  ) {
	int i;
	double rho;
	rho = sqrt( pow(vector0.cartesian[0],2)+pow(vector0.cartesian[1],2)+pow(vector0.cartesian[0],2) );
	vector0.espherical[0] = rho;
	vector0.espherical[1] = atan(vector0.cartesian[1]/vector0.cartesian[0]);
	vector0.espherical[2] = acos(vector0.cartesian[2]/rho);
	printf("\nEn coordenas esfericas (rho,theta,phi) es: \n");
	for( i = 0; i <= ENE - 1; ++i ){
	printf("\n%s [ %d ] = %lf \n", vector0.symbolo , i, vector0.espherical[i]);
	}
}
