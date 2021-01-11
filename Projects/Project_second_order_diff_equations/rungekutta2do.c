/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 <rungekutta2do.c>  INTEGRACION DE ECUACIONES DIFERENCIALES DE 2DO ORDEN CON METODO DE RUNGE KUTTA
 					
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
  * V. 0.1 : initial 
  * V. 1.0 : k's calculation function changed and optimized*/   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc -Wall rungekutta2do.c -o rungekutta2do -lm
 * -Wall : muestra advertencias
 * -o : le da el nombre <rungekutta2do> al ejecutable*/ 
 
#include<stdio.h>
#define ENE 250


void prockaas(void);
double funcion1eradev( double t, double y, double u);
double funcion2dadev( double t, double y, double u);


static double deltat, deltay, deltau;
static double y0, t0, u0, t, y, u, kaas[2][4];

int main() {
	int i;
	double limsup;
	FILE *archivo;
	
	archivo = fopen("2doorden.dat", "w+");
	
	printf("\n\n\nINTEGRACION NUMERICA DE ECUACIONES DIFERENCIALES EN C.\n\nECUACION DIFERENCIAL TIPO y''=f(t,y, y')  \n\nUNIVERSIDAD DE COSTA RICA - ESCUELA DE FISICA\n\n\n");
	
		
	/*VALORES INICIALES */ 
	
	t0 = 0;
	y0 = 0;
	u0 = 21;
	
	printf("\n\n\nEl valor inicial es t0 = %lf . Introduzca el valor final tN\n\n", t0);
	scanf("%lf", &limsup);
	
	/* TAMANO DEL PASO */
	
	deltat = (limsup-t0)/ENE;
	
	/* INICIALIAZACION DEL BUCLE */
	
	t = t0;
	y = y0;
	u = u0;
	
	/* IMPRIME LOS VALORES INICIALES EN LA PRIMERA LINEA DEL ARCHIVO*/
	
	fprintf(archivo, "%lf %lf \n", t0, y0);
	
	/* BUCLE PROCESA EL CALCULO DE LOS t_i, y_i, y_i hasta i=N */
	for(i=0;i<ENE;++i) {
		prockaas();
		fprintf(archivo, "%lf %lf \n", t0+(double)(i)*deltat, y+deltay);
		t = t0+(double)(i)*deltat;
		y = y+deltay;
		u = u+deltau;
	}
	
	fclose(archivo);
	
	return 0;
}

/* SUBRUTINA DE CALCULO DE LOS INDICES DE RUNGE-KUTTA K1,K2,K3,K4 */


void prockaas( void ) {
	
	/* Primer indice 0 calcula los k_0n = f1*/
	kaas[0][0] = deltat*funcion1eradev(t, y, u);
	
	/* Segundo indice 1 calcula los k_1n = f2*/
	kaas[1][0] = deltat*funcion2dadev(t, y, u);
	
	
	kaas[0][1] = deltat*funcion1eradev(t + deltat, y + 0.5*kaas[0][0], u + 0.5*kaas[1][0]);
	kaas[1][1] = deltat*funcion2dadev(t + deltat, y + 0.5*kaas[0][0], u + 0.5*kaas[1][0]);
	
	kaas[0][2] = deltat*funcion1eradev(t + deltat, y + 0.5*kaas[0][1], u + 0.5*kaas[1][1]);
	kaas[1][2] = deltat*funcion2dadev(t + deltat, y + 0.5*kaas[0][1], u + 0.5*kaas[1][1]);
	
	
	kaas[0][3] = deltat*funcion1eradev(t + deltat, y + kaas[0][2], u + kaas[1][2]);
	kaas[1][3] = deltat*funcion2dadev(t + deltat, y + kaas[0][2], u + kaas[1][2]);
	
	
	deltay = (1.0/6.0)*(kaas[0][0]+2.0*kaas[0][1]+2.0*kaas[0][2]+kaas[0][3]);
	deltau = (1.0/6.0)*(kaas[1][0]+2.0*kaas[1][1]+2.0*kaas[1][2]+kaas[1][3]);
}

/* SUBRUTINA DE LA FUNCION DE LA ECUACION DIFERENCIAL y' = f1(t,y,u) = u */

double funcion1eradev( double t, double y, double u){
	return(u);	
}

/* SUBRUTINA DE LA FUNCION DE LA ECUACION DIFERENCIAL u' = f2(t,y,u) */

double funcion2dadev( double t, double y, double u){
	return(-9.78);	
}


