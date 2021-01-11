/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO DE ESTRUCTURAS #1/
 
 /  < ESTRUCTURA0.C Uso de estructuras y variables automaticas>
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
 * gcc estructura0.c -o estructura0.c 
  * -o : le da el nombre <nombre_archivo> al ejecutable*/ 
 
 
#include<stdio.h>


typedef struct {
	char *simbolo;
	double valor;
} variable; 

extern variable PI = {"PI", 3.1415926};

int main () {

	auto variable radio={"radio", 0};
	auto variable perimetro={"P",0};
	
	printf("\n\n Escriba el radio del circulo:  ");
	scanf("%lf", &radio.valor);
	perimetro.valor =  2 * PI.valor * radio.valor;
	printf("\n %s = 2 * %s * %s = %lf", perimetro.simbolo, PI.simbolo, radio.simbolo, perimetro.valor);


	return (0);
}

