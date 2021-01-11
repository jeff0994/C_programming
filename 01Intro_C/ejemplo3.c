/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA EJEMPLO 3: Caracteres de conversión*/
 
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
 * gcc ejemplo3.c -w -o ejemplo3
 * -w : muestra advertencias
 * -o : le da el nombre <ejemplo3> al ejecutable*/    


#include<stdio.h>

int main(){
int ele, eme, ene;
double equis, ye, zeta;

printf("\n\n\nAprediendo sobre scanf y printf\n\n\n");


printf("\n\nEscriba tres numeros enteros con 3 digitos \(separados por un espacio \):     ");
scanf("%3d %4d %5d", &ele, &eme, &ene);
printf("\n1er entero es: %3d\n", ele);
printf("\n2do entero es: %4d\n", eme);
printf("\n3er entero es: %5d\n", ene);
printf("\nObserve que el 1er entero ocupa 3 espacios, el 2do con cuatro y el tercero con 5\n\n ");

printf("\n\nEscriba tres numeros enteros con 3 digitos \( sin separacion \):     ");
scanf("%3d%4d%5d", &ele, &eme, &ene);
printf("\n\nEl primero digito se guardo con tres espacios, el segundo con 4 y el tercero con 5, \n vea el resultado: ");
printf("\n1er entero es: %3d\n", ele);
printf("\n2do entero es: %4d\n", eme);
printf("\n3er entero es: %5d\n", ene);
printf("\nObserve como el programa separa los datos leidos desde la entrada estandar\n\n ");

printf("\n\nEscriba ahora 3 numeros con decimal que ocupe 5 espacios separados por un espacio:     ");
scanf("%5lf %5lf %5lf", &equis, &ye, &zeta);
printf("\n\nEl primero numero se guardo con tres decimales, el segundo con 4 y el tercero con 5, \n vea el resultado: ");
printf("\n1er numero es:%5.3lf\n", equis);
printf("\n2do numero es:%5.4lf\n", ye);
printf("\n3er numero es:%5.5lf\n", zeta);
printf("\nObserve como el programa separa los datos leidos desde la entrada estandar. Note que el punto incluye un espacio. \n\n ");

printf("\nVuelva a correr el programa e introduzca valores numericos con variantes para que observe como maneja el programa las variables en la memoria. \n\n ");
printf("\n\nFIN\n\n");
}
