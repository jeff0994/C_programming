/* UNIVERSIDAD DE COSTA RICA
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA FUNCIONES ANFITRIONAS Y FUNCIONES HUESPED*/

 /*  <rungekutta.c>  INTEGRACION DE ECUACIONES DIFERENCIALES CON METODO DE RUNGE KUTTA
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
  * V. 0.1 : initial
  * V. 0.2 : minor changes in initial values
  * V. 0.3 : new commentaries added */

/* Para correr el programa, aplique el comando en la terminal:
 *
 * gcc -Wall rungekutta.c -o rungekutta
 * -Wall : muestra advertencias
 * -o : le da el nombre <rungekutta> al ejecutable*/

#include<stdio.h>
#include<math.h>
#define ENE 100
#define PI 3.1416


extern double kaas( double x, double y );
double paraintegrar( double x, double y);
/* Resistencia 10 ohm , Capacitancia 0.01 farad*/
/*static double bateria=1, resistencia=10, capacitancia=0.01, tauc;*/
static double delta;
static double y_inicial, x_inicial;

int main() {
	int i;
	double limsup, y, x;
	FILE *archivo;

	archivo = fopen("tabla.dat", "w+");

	printf("\n\n\nINTEGRACION NUMERICA DE ECUACIONES DIFERENCIALES EN C.\n\nECUACION DIFERENCIAL TIPO y'=f(x,y) \n\nUNIVERSIDAD DE COSTA RICA - ESCUELA DE FISICA\n\n\n");



	/*VALORES INICIALES */

	/*tauc = resistencia*capacitancia;*/
	x_inicial = PI/2; /* Cronometro comienza en 0*/
	y_inicial = 3/2; /* Capacitor descargado inicialmente */


	/* Para ver los resultados con mayor claridad, se puede introducir un valor como limsup = 1 ~ 10*tauc
	 * es decir, 10 veces la escala temporal del circuito */
	printf("\nEl problema se inicia a resolver en t0=0. Introduzca la cota superior tN:   \n");
	scanf("%lf", &limsup);

	/* TAMANO DEL PASO */

	delta = (limsup-x_inicial)/ENE;


	/* INICIALIZACION DEL BUCLE */

	x = x_inicial;
	y = y_inicial;

	fprintf(archivo, "%lf %lf \n", x, y);

	for(i=1;i<ENE;++i) {
		x = x_inicial+(double)(i)*delta;
		y = y + kaas(x, y);
		fprintf(archivo, "%lf %lf \n", x, y);
	}

	fclose(archivo);

	return 0;
}

/* SUBRUTINA DE CALCULO DE LOS INDICES DE RUNGE-KUTTA K1,K2,K3,K4 */


double kaas( double x, double y ) {
	double k1, k2, k3, k4, dy;
	k1 = delta*paraintegrar(x, y);
	k2 = delta*paraintegrar(x+delta, y+0.5*k1);
	k3 = delta*paraintegrar(x+delta, y+0.5*k2);
	k4 = delta*paraintegrar(x+delta, y+k3);
	dy = (k1+2*k2+2*k3+k4)/6;
	return(dy);
}

/* SUBRUTINA DE LA FUNCION DE LA ECUACION DIFERENCIAL y' = f(t,y) */
/* Se resuelve el problema de la carga en un capacitor con constante de tiempo de tau_c = RC
 * conectado en serie a un resistor y a una bateria de 1.0 V. La carga inicial es de q_0 =0   */

/*Practica*/

/*double paraintegrar( double x, double y){
	double dy;
	dy = 1- y/x;
	return(dy);
}*/

/*double paraintegrar( double x, double y){
	double dy;
	dy = x- 3*y/x;
	return(dy);
}*/


/*double paraintegrar( double x, double y){
	double dy;
	dy = 1 / (x - 3*y);
	return(dy);
}*/

double paraintegrar( double x, double y){
	double dy;
	dy = cos(x) - y/tan(x);
	return(dy);
}
