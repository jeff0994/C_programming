/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * USO DE FUNCIONES ANFITRIONAS Y FUNCIONES HUESPED */
 
 /*  <integracion.h>  INTEGRACION NUMERICA - ARCHIVO DE ENCABEZADO
  * 					
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
 * gcc -Wall modulo1.c modulo2.c -o alumno
 * -Wall : muestra advertencias
 * -o : le da el nombre <alumno> al ejecutable*/ 
 
#include<stdio.h>

extern double trapecios( double (*funcionparaintegrar)( double equis ) , double inf, double sup);
extern double simpson( double (*funcionparaintegrar)( double equis ) ,  double inf, double sup);
extern double paraintegrar ( double equis );
