#include<stdio.h>
#include<math.h>

/* Programa que calcula la suma: S_n = sum_(i=1)^n i = 0.5*n*(n+1) */  /* Sn = 1 + 2 + 3 + 4 + ...*/
int main () {
	int ene, i;
	double inter;
	
	printf("\n\n\nPrograma el valor de la suma: S_n = sum_(i=1)^n i = 0.5*n*(n+1) \n\n");
	printf("\nIntroduzca el numero de términos: ...  ");
	scanf("%d", &ene);
	
	/* Se inicializa la suma con el termino "inter" o intermediario con el primer termino de la suma */
	printf("\n\n\nCon la formula S_%d =  %lf\n\n\n", ene, 0.5*ene*(ene+1));
	
	inter = 1;
	
	/* El bucle for le anade un valor en cada iteracion al valor de inter*/ 
	for (i=2; i<=ene; ++i) {
		/* Como inter es double, es necesasrio hacer que el entero ene pueda operar con las otras variables double
		 * Note como se realiza la conversion en la operacion */
		inter = inter + i;
	}
	printf("\n\n\nEl valor de la suma es S_%d = %lf", ene, inter);
}
