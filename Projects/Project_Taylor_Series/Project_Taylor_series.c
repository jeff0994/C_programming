/* UNIVERSIDAD DE COSTA RICA
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++
 * PROFESOR DAVID SOLANO SOLANO
 * ESTUDIANTE YEFRY JOSUE LOPEZ NUÑEZ
 * TAREA 06 Series de Taylor /


/* IMPORTAR LIBRERIAS BÁSICAS*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*DEFINA SUS CONTANTES SÍMBOLICAS*/
#define CENTRADO 3
#define PI 3.141593

/*Variables Globales*/
static int i,j;
static int ENE = 1;
static double x0 = 3.14;
static double x0_log = 0.5;

/*Prototipo de Funciones*/
static double factorial(int numero);
double Exp(int N, double x0);
double Exp_Negativa(int N, double x0);
double coseno(int N, double x0);
double logaritmo(int N ,double x0 );

/*INICIO FUNCION MAIN*/
int main(){
  printf("\n\nImportante! Los valores trigonométricos se dan en radianes!\n");
  printf("Recuerde que el valor evaluado en logaritmo debe ser x0 < 1\n\n");
  printf("El valor de exponencial del valor %lf para %d iteraciones es: %lf\n\n", x0 ,ENE ,Exp(ENE,x0));
  printf("El valor de exponencial negativa del valor %lf  para %d iteraciones es: %lf\n\n", x0 ,ENE ,Exp_Negativa(ENE,x0));
  printf("El valor del coseno del valor %lf para %d iteraciones es: %lf\n\n", x0 ,ENE ,coseno(ENE,x0));
  printf("El valor del log(1+x) del valor %lf para %d iteraciones es: %lf\n\n", x0_log ,ENE ,logaritmo(ENE,x0_log));
}

/* Cálcula serie de Taylor para Exponente(x)*/
double Exp(int N, double x0  ){
  double suma = 0;
  for (i = 0; i <= N; ++i){
    suma += pow(x0,i) / factorial(i);
}
  return suma;
}

/* Cálcula serie de Taylor para Exponente(-x)*/
double Exp_Negativa(int N, double x0){
  double suma = 0;
  for (i = 0; i <= N; ++i){
    suma += pow(-x0,i) / factorial(i);
}
  return suma;
}

/* Cálcula serie de Taylor para cos(x)*/
double coseno(int N, double x0){
  double suma = 0;
  for (i = 0; i <= N; ++i){
    suma += pow(-1,i)*pow(x0,2*i) / factorial(2*i);
}
  return suma;
}

double logaritmo(int N , double x0 ){
  double suma = 0;
  for (i = 1; i <= N; ++i){
    suma += pow(-1,i+1)*pow(x0,i) / i;
}
  return suma;
}
/* Calcula el factorial de un numero*/
static double factorial(int numero){
  if(numero == 0)
    return 1;
  else
    return (numero * factorial(numero-1));
  }
