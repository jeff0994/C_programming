/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * CALCULO DE SUMAS O SERIES */
 
 /*  < SUMA.C USE "FOR" CONTROL INSTRUCTION TO COMPUTE SUMS .>
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
 * gcc suma.c -wall -o suma
 * -wall : muestra advertencias
 * -o : le da el nombre "controlfor" al ejecutable*/    


#include<stdio.h>
#include<math.h>

/* Programa que calcula la suma: S_n = sum x^n/n*/
int main () {
	int ene, limite;
	double inter, equis;
	
	printf("\n\n\nPrograma el valor de la suma: S_n = sum_(n=1)^N x^n/n \n\n");
	printf("\nIntroduzca el numero de iteraciones: ...  ");
	scanf("%d", &limite);
	printf("\nIntroduzca el valor de x: ...  ");
	scanf("%lf", &equis);
	
	
	/* Se inicializa la suma con el termino "inter" o intermediario con el primer termino de la suma */
	inter = pow(equis,1)/1;
	
	/* El bucle for le anade un valor en cada iteracion al valor de inter*/ 
	for (ene=2; ene<=limite; ++ene) {
		/* Como inter es double, es necesasrio hacer que el entero ene pueda operar con las otras variables double
		 * Note como se realiza la conversion en la operacion */
		inter = inter + pow(equis, ene)/(double)(ene);
	}
	printf("\n\n\nEl valor de la suma es S_(%d) = %lf", limite, inter);
}
