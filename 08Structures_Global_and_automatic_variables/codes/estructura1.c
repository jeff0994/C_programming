/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO DE ESTRUCTURAS #2*/
 
 /*  < ESTRUCTURA1.C Uso de estructuras >
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
 * gcc esctructura1.c -wall -lm -o estructura1
 * -wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/ 


#include<stdio.h>
#include<ctype.h>
#include<string.h>
 
typedef struct  {
	int dia;
	int mes;
	int anio;
} fecha;

static fecha iniciocurso = {13,8,2018};

void leerfecha( int date[3] );

void mostrarinicio ();

void mostrarfecha( fecha date );

void mostrarcadenames ( int num );
 
int main() {
	int today[3];
	fecha ayer = {1,1,2000}, hoy; 
		
	printf("\n\nPROGRAMA PARA MOSTRAR DIFERENCIA ENTRE VARIABLES GLOBALES Y VARIABLES AUTOMATICAS\n\n\n");
	
	printf("\nMuestra variable global o externa definida fuera de main \n");
	
	mostrarinicio();
	
	printf("\n\n\nMuestra variable automatica declarada en main \n");
	printf("\nSe solicita mostrar una fecha en el pasado...\n");
	mostrarfecha(ayer);
	
	printf("\n\n\n\nIntroduzca la fecha de hoy: \n");
	leerfecha(today);
	
	/*Asigna valores a variable personalizada por el desarrollador hoy tipo fecha */
	
	hoy.dia = today[0];
	hoy.mes = today[1];
	hoy.anio = today[2]; 
	
	
	printf("\n\n\nMuestra variable automatica definida dentro de main \n");
	printf("\nSe solicita mostrar una fecha de hoy...\n");
	mostrarfecha(hoy);
	
	return(0);
}

void leerfecha( int date[3] ) {
	printf("\nEscriba el dia:  ");
	scanf("%d", &date[0]);
	printf("\nEscriba el mes (numero):  ");
	scanf("%d", &date[1]);
	printf("\nEscriba el anio:  ");
	scanf("%d", &date[2]);
	return;
}


void mostrarinicio ( ) {
	printf("El inicio del curso fue %d de " , iniciocurso.dia);
	mostrarcadenames(iniciocurso.mes);
	printf(" de %d", iniciocurso.anio);
}

void mostrarfecha ( fecha date ) {
	printf("La fecha de solicitada es %d de " , date.dia);
	mostrarcadenames(date.mes);
	printf(" de %d", date.anio);
	return;
}

void mostrarcadenames ( int num ) {
	switch(num){
	case 1:
		printf("enero");
		break;
	case 2:
		printf("febrero");
		break;
	case 3:
		printf("marzo");
		break;
	case 4:
		printf("abril");
		break;
	case 5:
		printf("mayo");
		break;		
	case 6:
		printf("junio");
		break;
	case 7:
		printf("julio");
		break;
	case 8:
		printf("agosto");
		break;
	case 9:
		printf("septiembre");
		break;
	case 10:
		printf("octubre");
		break;	
	case 11:
		printf("noviembre");
		break;	
	case 12:
		printf("diciembre");
		break;
	default:	
		printf("error");	
	}									
	return;
}
