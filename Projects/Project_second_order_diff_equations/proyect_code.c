/* UNIVERSIDAD DE COSTA RICA
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++
 * PROFESOR DAVID SOLANO SOLANO
 * ESTUDIANTE YEFRY LOPEZ NUÑEZ

 PrOYECTO INTEGRACION DE ECUACIONES DIFERENCIALES DE 2DO ORDEN CON METODO DE RUNGE KUTTA */

 #include<stdio.h>
 #include<math.h> /* Use pow()*/
 #define ENE 250  /* Iterations */


 void kaa_values(void);
 double first_derivative( double t, double x, double u);
 double second_derivative( double t, double x, double u);


 static double deltat, deltax, deltau;
 static double x0, t0, u0, t, x, u, kaas[2][4];
 static double b,m;

 int main() {
 	int i;
 	double limsup;
 	FILE *archivo;

 	archivo = fopen("datac.csv", "w+");

 	printf("\n\n\nINTEGRACION NUMERICA DE x'' = (b/m)(x')^2.\n\n\n");

 	/*VALORES Constantes */
  b = 1.0;
  m = 1.0;
 	/*VALORES INICIALES */

 	t0 = 0;
 	x0 = 0;
 	u0 = 0;

 	printf("\n\n\nSe inicia desde el tiempo t0 = %lf .\nContinue Introduciendo el valor final tN: ", t0);
 	scanf("%lf", &limsup);

 	/* TAMANO DEL PASO */

 	deltat = (limsup-t0)/ENE;

 	/* INICIALIAZACION DEL BUCLE */

 	t = t0;
 	x = x0;
 	u = u0;

  printf("\n\nSe resolverá el sistema con masa de %lf kg y una resistencia b de %lf\n", m,b);

 	/* IMPRIME LOS VALORES INICIALES EN LA PRIMERA LINEA DEL ARCHIVO*/

 	fprintf(archivo, "%lf %lf %lf \n", t0, x0, u0);

 	/* BUCLE PROCESA EL CALCULO DE LOS t_i, y_i, y_i hasta i=N */
 	for(i=0;i<ENE;++i) {
 		kaa_values();
 		fprintf(archivo, "%lf %lf %lf \n", t0+(double)(i)*deltat, x+deltax, u+deltau);
 		t = t0+(double)(i)*deltat;
 		x = x+deltax;
 		u = u+deltau;
 	}

 	fclose(archivo);

 	return 0;
 }

 /*CALCULO DE LOS INDICES DE RUNGE-KUTTA K1,K2,K3,K4 */


 void kaa_values( void ) {

 	/* Primer indice 0 calcula los k_0n = f1*/
 	kaas[0][0] = deltat*first_derivative(t, x, u);

 	/* Segundo indice 1 calcula los k_1n = f2*/
 	kaas[1][0] = deltat*second_derivative(t, x, u);


 	kaas[0][1] = deltat*first_derivative(t + deltat, x + 0.5*kaas[0][0], u + 0.5*kaas[1][0]);
 	kaas[1][1] = deltat*second_derivative(t + deltat, x + 0.5*kaas[0][0], u + 0.5*kaas[1][0]);

 	kaas[0][2] = deltat*first_derivative(t + deltat, x + 0.5*kaas[0][1], u + 0.5*kaas[1][1]);
 	kaas[1][2] = deltat*second_derivative(t + deltat, x + 0.5*kaas[0][1], u + 0.5*kaas[1][1]);


 	kaas[0][3] = deltat*first_derivative(t + deltat, x + kaas[0][2], u + kaas[1][2]);
 	kaas[1][3] = deltat*second_derivative(t + deltat, x + kaas[0][2], u + kaas[1][2]);


 	deltax = (1.0/6.0)*(kaas[0][0]+2.0*kaas[0][1]+2.0*kaas[0][2]+kaas[0][3]);
 	deltau = (1.0/6.0)*(kaas[1][0]+2.0*kaas[1][1]+2.0*kaas[1][2]+kaas[1][3]);
 }

 /* ECUACION DIFERENCIAL x' = f1(t,x,u) = u */

 double first_derivative( double t, double x, double u){
 	return(u);
 }

 /* ECUACION DIFERENCIAL u' = f2(t,x,u) */

 double second_derivative( double t, double x, double u){
 	return((-b/m)*pow(u,2));
 }
