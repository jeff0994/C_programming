/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 * PROGRAMA USO DE ESTRUCTURAS #2*/
 
 /*  <estadistica2.c>  INTRODUCCION A LOS PUNTEROS O APUNTADORES CON
  * 				   VARIABLES ESTADISTICAS BASICAS.
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
  * V. 0.1 : initial */   
  
    
/* Para correr el programa, aplique el comando en la terminal: 
 * 
 * gcc estadistica.c -w -lm -o escala 
 * -w : muestra advertencias
 * -lm : vincula con la libreria math.h 
 * -o : le da el nombre <nombre_archivo> al ejecutable*/ 
 
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 10000

static double *poblation;

static double ENE;

static double mean;

static double mediana;

static double variance;

static double stddes;

static double liminf;

static double limsup;

static int numdiv;

static double *distribucion[2];

void sortpoblation();

void calculatemediana();

void calculatemean();

void calculatevar();

double calculateporcentil(double porcentilnum);

void constructdistribution();


int main () {
	double *apuntador, numero, porcentil;
	int i=0, respuesta = 1, resp = 1;
	
	/*ESTABLECE EL LIMITE MAXIMO EN EL TAMANO DE LA MEMORA EN LA DIRECCION APUNTADOR */
	apuntador = (double *) malloc(MAXSIZE*sizeof(double));
	
	/*BUCLE PARA AGREGAR VALOR A LA FORMACION EN EL PUNTERO "APUNTADOR" */
	while( resp == 1 && i < MAXSIZE ) {
		printf("\nAgregue un numero:   ");
		scanf("%lf", &numero);
		*(apuntador+i) = numero; 
		printf("\nSe introdujo:  %lf", numero);
		i = i + 1;
		printf("\n\nDesea agregar otro? Escriba \"1\" para continuar  ");
		scanf("%d", &respuesta);
		resp = respuesta;
	}
	
	/* ESTABLECE EL TAMANO EN MEMORIA DEL ARREGLO/APUNTADOR POBLATION */
	
	poblation = (double *) malloc(i*sizeof(double));
	
	/*ESTABLECE EL TAMANO DE LA POBLACION DE DATOS */
	
	ENE = (double)(i);
	
	/*IGUALA LOS DATOS OBTENIDOS DE STDIN EN APUNTADOR Y LOS LLEVA A POBLATION */
	
	for(i=0;i<=ENE-1;++i){
		*(poblation+i) = *(apuntador+i);
	}
	
	/* ORDENA LOS DATOS EN ORDEN ASCENDENTE */ 
	
	sortpoblation();
	
	/* CALCULA LA MEDIANA */
	
	calculatemediana();
	
	/*CALCULA LA MEDIA ARITMETICA CON LOS VALORES DEL PUNTERO POBLATION Y EL NUMERO DE DATOS ENE */
	calculatemean();
	
	/*CALCULA LA VARIANZA Y DESVIACION ESTANDAR CON VALOR DEFINIDOS ESTATICAMENTE */
	
	calculatevar();
	
	printf("\n\nNumero de datos = %lf \nMedia Aritmetica = %lf \nMaximo = %lf \nMinimo = %lf \nMediana = %lf \nVarianza = %lf \nDesviacion estandar = %lf", ENE, mean, *(poblation+(int)(ENE)-1), *(poblation+0), mediana, variance, stddes);
	
	/*BUSCA EN STDIN EL VALOR DE PORCENTIL PARA CALCULAR */
	printf("\n\nIntroduzca un numero entre 0 y 100 para el porcentil =   ");
	scanf("%lf", &porcentil);
	printf("El porcentil-%2.0lf es:  %lf", porcentil, calculateporcentil(porcentil));
	
	/*PIDE LOS LIMITES INFERIOR Y SUPERIOR  Y EL NUMERO DE SUBDIVISIONES PARA CALCULAR UNA DISTRIBUCION */
	printf("\n\nParametros para calcular la distribucion\n\n\n");
	
	printf("\n\nIntroduza el limite inferior para la distribucion:  ");
	scanf("%lf", &liminf);
	
	printf("\n\nIntroduza el limite superior para la distribucion:  ");
	scanf("%lf", &limsup);
	
	printf("\n\nIntroduza el numero de subdivisiones  ");
	scanf("%d", &numdiv);
	
	constructdistribution();
	return(0);
}

void sortpoblation() {
	int i,j;
	double inter, *arreglo;
	
	arreglo = (double *) malloc(ENE*sizeof(double));
	
	printf("\nLista sin ordenar:\n");
	for(i=0;i<=ENE-1;++i){
	*(arreglo+i) = *(poblation+i);
	printf("%lf\n", *(poblation+i));	
	}
	
    for (i = 0; i < ENE; i++) {
        for (j = 0; j < (ENE - i - 1); j++){
            if (*(arreglo + j) > *(arreglo + j + 1)){
                inter = *(arreglo + j);
                *(arreglo + j)= *(arreglo + j + 1 );
                *(arreglo + j + 1)= inter;
            }
        }
    }
    
    printf("\nLista ordenada:\n");
	for(i=0;i<=ENE-1;++i){
		*(poblation+i) = *(arreglo+i); 
		printf("%lf\n", *(poblation+i));	
	}
    return;	
}

void calculatemediana() {
	int temp= (int)(ENE/2);
	/* SI ENE ES IMPAR */
	if( (int)(ENE)%2 != 0 ){
		mediana = *(poblation+temp);
	}
	if( (int)(ENE)%2 == 0 ){
		mediana = (*(poblation+temp)+*(poblation+temp+1))/2;
	}
	return;
}


void calculatemean() {
	int i;
	double suma=0;
	for(i=0;i<=ENE-1;++i){
		suma = suma + *(poblation+i);
	}
	mean = suma/ENE;
	return;
}

void calculatevar(){
	int i;
	double suma=0;
	for(i=0;i<=ENE-1;++i){
		suma = suma + pow( mean - *(poblation+i), 2  );
	}
	variance = suma/(ENE-1);
	stddes = sqrt(variance);
	return;
}

double calculateporcentil(double porcentilnum) {
	int temp;
	temp = (int) (porcentilnum*ENE/100) ;
	return( *(poblation+temp) );
}

void constructdistribution() {
/* Con la poblacion ordenada ascendentemente */	
	int i, j, k;
	double epsilon, medinterval, infinterval, supinterval;
	
	epsilon = (limsup-liminf)/(double)(numdiv);
	
	
	if( liminf < limsup ) {
		
		distribucion[0] = (double *)malloc(numdiv*sizeof(double));
		distribucion[1] = (double *)malloc(numdiv*sizeof(double));
		
		printf("\n\nDistribucion \nepsilon = %lf\n\n", epsilon);
		
		for(i = 0; i < numdiv; ++i) {
			infinterval = liminf+i*epsilon;
			supinterval = liminf+(i+1)*epsilon;
			medinterval = infinterval+epsilon/2;
			k=0;
			for(j=0;j<=ENE-1;++j){
				if( *(poblation+j) >= infinterval && *(poblation+j) < supinterval){
					k = k + 1;
				}
			}
			*(distribucion[0]+i) = medinterval;
			*(distribucion[1]+i)= (double)(k/ENE);
			printf("%lf  %lf\n", *(distribucion[0]+i) , *(distribucion[1]+i));
		}
	}
	else{
	printf("\n\nNo se pudo construir distribucion\n\n");	
	}
}
