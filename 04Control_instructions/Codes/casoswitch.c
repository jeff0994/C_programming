/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * PROGRAMA USO DE INSTRUCCION SWITCH-CASE-DEFAULT*/
 
 /*  < CASOSSWITCH.C TAKES CHARACTER DATA FROM STIN AND PRINT IN UPPER CASE.>
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
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc casoswitch.c -wall  -o casoswitch 
 * -wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>



int main () {
	int num;
	
	printf("\n\n\nPrograma que da el nombre de un mes al insertar su numero\n\n");
	printf("\nIntroduzca un numero de 1 a 12   ");
	scanf("%d", &num);
	
	if(num <= 0 || num >= 13) {
		printf("\n\nError\n\nFIN DEL PROGRAMA\n\n\n");
	}
	else{
		switch (num){
			case 1:
				printf("\n\tEnero\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 2:
				printf("\n\tFebrero\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 3:
				printf("\n\tMarzo\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 4:
				printf("\n\tAbril\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 5:
				printf("\n\tMayo\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 6:
				printf("\n\tJunio\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 7:
				printf("\n\tJulio\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 8:
				printf("\n\tAgosto\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 9:
				printf("\n\tSeptiembre\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 10:
				printf("\n\tOctubre\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 11:
				printf("\n\tNoviembre\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			case 12:
				printf("\n\tDiciembre\n\n\tFIN DEL PROGRAMA\n\n\n");
				break;
			default:
				printf("\n\n\tError\n\n\t\tFIN DEL PROGRAMA\n\n\n");
				break;
		}	
		
	}
	return(0);
}
