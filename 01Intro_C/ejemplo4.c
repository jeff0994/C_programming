/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA EJEMPLO 4: Uso de fscanf y fprintf*/
 
 /* ejemplo3: muestra al estudiante la configuración de los caracteres de
  * conversión y su relación con el formato de entrada / salida.>
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
 * gcc ejemplo4.c -w -o ejemplo4
 * -w : muestra advertencias
 * -o : le da el nombre <ejemplo4> al ejecutable*/    


#include<stdio.h>

int main(){
/* Declaración de variables de apuntador a ubicación en memoria 
 * para leer/escribir en dispositivo de almacenamiento */	
FILE *entrada, *salida;
int ele, eme, ene;
double equis, ye, zeta;

/* Funcion fopen para abrir un archivo, sea existente o nuevo*/

entrada = fopen("entrada.txt", "r"); /* el archivo entrada.txt ya existe y de solo-lectura*/
salida = fopen("salida.dat", "w+"); /* el archivo salida.dat se crea en modo escritura */

printf("\n\n\nAprendiendo sobre fscanf y fprintf\n\n\n");

printf("\n\n\nAhora el programa va a leer los 3 numeros en el archivo \"entrada.txt\" \n Los numeros son:    ");

/* Lee los números, uno por línea en el archivo entrada.txt asociado al apuntador entrada */
fscanf(entrada, "%d", &ele);
fscanf(entrada, "%d", &eme);
fscanf(entrada, "%d", &ene);

/* Muestra en STOUT el contenido del archivo*/
printf("%d %d %d", ele, eme, ene);



/* El programa ahora va a leer tres numeros de STIN y los va a escribir en el archivo salida.dat*/ 
printf("\n\n\n\nAhora escriba un numero ...  ");
scanf("%lf", &equis);
printf("\nEscriba otro numero ...  ");
scanf("%lf", &ye);
printf("\nEscriba otro numero ...  ");
scanf("%lf", &zeta);

fprintf(salida, "%5.0lf\n", equis);
fprintf(salida, "%5.0lf\n", ye);
fprintf(salida, "%5.0lf\n", zeta);

printf("\n\n\nFIN DEL PROGRAMA \n\n\n(revise el archivo \"salida.dat\" para ver los numeros que digito) \n\n\n");


/* Funcion fclose que cierra los archivos. Los archivos van a estar en uso mientras el programa este corriendo*/
fclose(entrada);
fclose(salida);
}
