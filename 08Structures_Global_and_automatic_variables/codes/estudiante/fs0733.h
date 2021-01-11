/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA VARIABLES EXTERNAS*/
 
 /*  				
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
  
    
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

/* ESTE ES EL ARCHIVO DE ENCABEZADO (HEADER). ESTE ARCHIVO TRAE:
 * 
 * 
 * 1-.  LAS DEFINICIONES HECHAS POR EL PROGRAMADOR (TYPEDEF'S)
 * 2-.  LOS PROTOTIPOS DE FUNCIONES
 * 
 * 
 * NOTE QUE EN LOS OTROS ARCHIVOS DE CODIGO SE DEBE USAR LA INSTRUCCION #INCLUDE CON COMILLAS PARA
 * INCLUIR ESTE ENCABEZADO */


/* ESTA ES LA ESTRUCTURA DEFINIDA ESPECIFICAMENTE PARA EL PROGRAMA */

typedef struct {
	char nombre[100];
	int carne[8];
}estudiante;
	
/* AQUI SE INCLUYEN LOS PROTOTIPOS CON LA CLAVE EXTERN; QUIERE DECIR QUE ESTAS FUNCIONES SE DEFINEN
 * EN OTRA PARTE */
 
 
extern void leerdatos();

extern void mostrardatos();
