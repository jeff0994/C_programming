#include<stdio.h>
#include<math.h>


/* PROTOTIPE LAS FUNCIONES QUE USTED DESEE AQUI*/
extern double trapecios( double (*funcionparaintegrar)( double equis ) , double inf, double sup);
extern double simpson( double (*funcionparaintegrar)( double equis ) ,  double inf, double sup);
extern double paraintegrar ( double equis );

/* AQUI SE DEFINE EL PARTICIONAMIENTO DEL INTERVALO*/

#define ENE 10000



int main() {
	double liminf, limsup;

	printf("\n\n\nINTEGRACION NUMERICA  \n\nI = int(sqrt(x),x,inf,sup) \n\nUNIVERSIDAD DE COSTA RICA - ESCUELA DE FISICA\n\n\n");
	printf("\n\nEscriba el limite inferior: ");
	scanf("%lf", &liminf);
	printf("\nEscriba el limite superior:  ");
	scanf("%lf", &limsup);
	/* PUEDE CAMBIAR EL ARGUMENTO PARAINTEGRAR POR LA FUNCIONES QUE USTED QUIERA */
	printf("\n\nSegun regla de trapecios, I =  %20.10lf", trapecios( paraintegrar, liminf, limsup ) );
	printf("\n\nSegun regla  de  Simpson, I =  %20.10lf \n\n\n", simpson( paraintegrar, liminf, limsup ) );

	return 0;
}

/*SUBRUTINAS*/
/* SUBRUTINA DE REGLA DE LOS TRAPECIOS */

double trapecios( double (*funcionparaintegrar)( double equis ) , double inf, double sup) {
	int i;
	double suma, epsilon, primero, ultimo, final;
	epsilon = (sup - inf) / ENE;
	primero = (*funcionparaintegrar)( inf );
	ultimo  = (*funcionparaintegrar)( sup );
	suma = 0;
	for(i=1; i < ENE; ++i ){
		suma = suma + 2 * (*funcionparaintegrar)( inf + (double)(i) * epsilon );
	}
	final = 0.5*epsilon*(primero+ultimo+suma);
	return(final);
}

/* SUBRUTINA DE REGLA DE SIMPSON */


double simpson( double (*funcionparaintegrar)( double equis ) ,  double inf, double sup) {
	int i,j;
	double sumaimpar, sumapar, epsilon, primero, ultimo, final;
	epsilon = (sup - inf) / ENE;
	primero = (*funcionparaintegrar)( inf );
	ultimo  = (*funcionparaintegrar)( sup );

	/* SUMA  DE INDICES IMPARES, COMIENZA EN X_1 = INF + EPSILON */
	sumaimpar = 0;
	i = 1;
	j = 1;
	while(j<ENE) {
		sumaimpar = sumaimpar + 4 * (*funcionparaintegrar)( inf + (double)(j) * epsilon );
		j = 2*i+1;
		i = i+1;

	}

	/* SUMA DE INDICES PARES, COMIENZA EN X_2 = INF + 2*EPSILON */

	sumapar = 0;
	i = 2;
	j = 2;
	while(j < ENE){
		sumapar = sumapar + 2 * (*funcionparaintegrar)( inf + (double)(j) * epsilon );
		j = 2*i;
		i = i+1;
	}


	final = epsilon*(primero+ultimo+sumapar+sumaimpar)/3.0;
	return(final);
}

/* LA FUNCION TIENE QUE ESTAR DEFINIDA EN EL INTERVALO!!!*/
/*double paraintegrar ( double equis ){
	double inter;
	inter = sqrt(equis);
	return ( inter );
}*/

double paraintegrar ( double equis ){
	double inter;
	inter = pow(sin(equis),2);
	return ( inter );
}
