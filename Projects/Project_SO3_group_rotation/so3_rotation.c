/* UNIVERSIDAD DE COSTA RICA
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++
 * PROFESOR DAVID SOLANO SOLANO
 * ESTUDIANTE YEFRY JOSUE LOPEZ NUÑEZ
 * TAREA 07 El grupo SO(3) con formaciones /


/* IMPORTAR LIBRERIAS BÁSICAS*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*DEFINA SUS CONTANTES SÍMBOLICAS*/
#define ENE 3
#define PI 3.141593

/* DECLARACION DE VARIABLES GLOBALES*/
static double vector[ENE];
static double angulo;
static char eje;
static double producto[ENE];
static double c,d;
static double PMatrix_X[ENE][ENE];
static double PMatrix_Y[ENE][ENE];
static double PMatrix_Z[ENE][ENE];
static double Matrix_T[ENE][ENE];
static int i,j;

/*PROTOTIPO DE FUNCIONES*/
void Eje();
void Angulo();
void leervector( double array[]);
void mostrarvector( double array[]);
void MatrixRot_X();
void MatrixRot_Y();
void MatrixRot_Z();
void Rotacion(double array[],double Matrix[ENE][ENE]);
void Matrix_Transpuesta(double Matrix[ENE][ENE]);
double producto_escalar(double array[]);
void Mostrar_Matriz(double Matriz[ENE][ENE]);

int main () {
  Eje();
  Angulo();
  leervector(vector);
  printf("\nUd desea rotar sobre el eje %c\n",eje);

  if (eje == 'x'){
    MatrixRot_X();
    Rotacion(vector, PMatrix_X);}
  else if(eje == 'y'){
    MatrixRot_Y();
    Rotacion(vector, PMatrix_Y);}
  else {
    MatrixRot_Z();
    Rotacion(vector, PMatrix_Z);}

  mostrarvector(producto);

  printf("\n\n\nLa distancia d^2 es: %lf\n\n",producto_escalar(vector));

  if (eje == 'x'){
    Matrix_Transpuesta(PMatrix_X);
    printf("\n\n\nSu matriz %c original es: \n", eje);
    Mostrar_Matriz(PMatrix_X);}
  else if(eje == 'y'){
    Matrix_Transpuesta(PMatrix_Y);
    printf("\n\n\nSu matriz %c orignal es: \n", eje);
    Mostrar_Matriz(PMatrix_Y);}
  else {
    Matrix_Transpuesta(PMatrix_Z);
    printf("\n\n\nSu matriz %c original es: \n", eje);
    Mostrar_Matriz(PMatrix_Z);}

  printf("\n\n\nSu matriz %c transpuesta es: \n", eje);
  Mostrar_Matriz(Matrix_T);

  printf("\n\n\nLa distancia d^2 para el vector rotado es: %lf\n\n", producto_escalar(producto));
}

/*FUNCION QUE SELECCIONA EL EJE */
void Eje(){
  printf("\n\nSobre cual eje desea rotar?\n");
  printf("Digite x, y o z: ");
  eje = getchar();
  return;
}

/* FUNCION QUE SOLICITA EL ANGULO AL USUARIO */
void Angulo(){
  printf("\n¿Con cuantos grados desea rotar su vector?: ");
  scanf("%lf", &angulo);
  return;
}

/* FUNCION QUE LEE VECTOR POR PARTE DEL USUARIO */
void leervector( double array[]) {
	printf("\n\n\nIntroduzca las componentes del vector");
	for( i = 0; i <= ENE - 1; ++i ){
		printf("\nu_%d = ", i);
		scanf("%lf", &array[i]);
	}
	return;
	}

/* FUNCION QUE MUESTRA EN PANTALLA UN VECTOR */
void mostrarvector(double array[]){
  	printf("\n\n\nLa rotación en el eje %c del vector da como resultado: \n", eje);
  	for( i = 0; i <= ENE - 1; ++i ){
  		printf("\ncomponente_rotada[ %d ] = %lf \n",i, array[i]);
  	}
  }

/*FUNCIÓN QUE CREA LA MATRIZ DE ROTACIÓN EN X*/
void MatrixRot_X(){
  c = cos(angulo);
  d = sin(angulo);
  double Matrix_X[ENE][ENE] = {{1,0,0},{0,c,d},{0,-d,c}};

  for(i = 0;i<3;++i){
    for(j = 0;j<3;++j){
      PMatrix_X[i][j] = Matrix_X[i][j];
    }
  }
}
/*FUNCIÓN QUE CREA LA MATRIZ DE ROTACIÓN EN Y*/
void MatrixRot_Y(){
  c = cos(angulo);
  d = sin(angulo);

  double Matrix_Y[ENE][ENE] = {{c,0,d},{0,1,0},{-d,0,c}};

  for(i = 0;i<3;++i){
    for(j = 0;j<3;++j){
      PMatrix_Y[i][j] = Matrix_Y[i][j];
    }
  }
}
/*FUNCIÓN QUE CREA LA MATRIZ DE ROTACIÓN EN Z*/
void MatrixRot_Z(){
  c = cos(angulo);
  d = sin(angulo);

  double Matrix_Z[ENE][ENE] = {{c,d,0},{-d,c,0},{0,0,1}};

  for(i = 0;i<3;++i){
    for(j = 0;j<3;++j){
      PMatrix_Z[i][j] = Matrix_Z[i][j];
    }
  }
}

/*ROTACION T SOBRE EL VECTOR V TV*/
void Rotacion(double array[],double Matrix[ENE][ENE]){
// Dentro recorremos las filas de la primera (A)

for (i = 0; i < 3; ++i) {
    double suma = 0;
    // Y cada columna de la primera (A)
    for (j = 0; j <  3; ++j) {
        // Multiplicamos y sumamos resultado
        suma += Matrix[i][j] * array[j];
    }
    // Lo acomodamos dentro del producto
    producto[i] = suma;
  }
}

/*CALCULO DE LA DISTANCIA AL CUADRADO*/
double producto_escalar(double array[])
{
  double dot_product = 0;
  for( i = 0; i < ENE; ++i){
    dot_product += array[i]*array[i];
  }
  return dot_product;
}

/*SUBRUTINA PARA TRANSPONER UNA MATRIZ*/
void Matrix_Transpuesta(double Matrix[ENE][ENE]){
  for(i=0; i < ENE ; ++i){
    for(j=0; j < ENE; ++j){
      Matrix_T[j][i] = Matrix[i][j];
    }
  }

}

/*SUBRUTINA PARA MOSTRAR FILAS Y COLUMNAS DE MATRIZ*/
void Mostrar_Matriz(double Matriz[ENE][ENE]){
  for (i = 0; i < ENE; ++i) {
      for (j = 0; j < ENE; ++j){
         printf("%lf\t", Matriz[i][j]);
      }
      printf("\n");
  }
}
