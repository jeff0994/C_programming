/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA EJEMPLO 2: entrada / salida estandar */
 
 /* ejemplo2: muestra al estudiante resultados de cálculo en salida estandar.>
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
 /* V. 0.2 : more commentaries */  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc ejemplo2.c -w -o ejemplo2
 * -w : muestra advertencias
 * -o : le da el nombre <ejemplo2> al ejecutable*/  



/* Cabeceras a incluir */
#include<stdio.h>

/* Constante simbolica */
#define PI 3.141593

/* Inicio de la funcion principal*/
void main ( void ) { 
  /* Declaracion de variables e inicializacion */
  int entero1 = 5, entero2 = 17;
  float real1, real2;
  char palabra[5] = "dedo", letra='x';
  
  /* Imprime en pantalla instruccion para el usuario */
  printf("\n\n\n Area de un Cubo \n\n Introduzca la arista:  ");
  
  /* Buscan datos en entrada estandar : el teclado */
  scanf("%f", &real1);
  
  /* Realiza una operacion */
  real2 = 6*real1*real1;
  
  /* Imprime el resultado */
  printf("\n El Area es: %f \n\n\n FIN", real2);
/*Fin de la funcion principal */
} 
