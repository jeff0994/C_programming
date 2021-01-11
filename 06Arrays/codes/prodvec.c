/* UNIVERSIDAD DE COSTA RICA 
 * ESCUELA DE FISICA
 * CURSO: FS0733 TOPICOS DE METODOS MATEMATICOS DE LA FISICA
 * TEMA: FISICA COMPUTACIONAL Y PROGRAMACION EN C/C++ 
 * PROFESOR DAVID SOLANO SOLANO
 
 * Producto Vectorial con el Pseudo-Tensor de Levi-Civita*/
 
 /*  < Compute Vector product through Levi-Civita tensor.>
    Copyright (C) 2019  David Solano-Solano
 

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
 * gcc vectorprod.c -Wall -o vectorprod 
 * -Wall : muestra advertencias
 * -o : le da el nombre <nombre_archivo> al ejecutable*/    


#include<stdio.h>

void initialize_levi3d(double tensor[3][3][3]);
void mostrarvector( double vector[] );
void productovectorial( double vec1[3], double vec2[3], double vec3[3], double tensor[3][3][3] );

int main () {
	double vector1[3], vector2[3], vector3[3], levicivita3[3][3][3];
	initialize_levi3d(levicivita3);
	vector1[0]=1.0;
	vector1[1]=-1.0;
	vector1[2]=-1.0;
	vector2[0]=2.0;
	vector2[1]=0.0;
	vector2[2]=1.0;
	printf("\n\nvector1 =");
	mostrarvector(vector1);
	printf("\n\nvector2 =");
	mostrarvector(vector2);
	printf("\n\nEl producto vectorial vector3 = vector1 x vector2 =");
	productovectorial(vector1,vector2,vector3,levicivita3);
	mostrarvector(vector3);
}

void initialize_levi3d(double tensor[3][3][3]){
	int i,j,k;
	for(i=0;i<3;++i){
		for(j=0;j<3;++j){
			for(k=0;k<3;++k){
				if(i==j || i==k || j==k){
					tensor[i][j][k] = 0.0;
				}
				else{
					if( (i==0 && j==1 && k==2) || (i==1 && j==2 && k==0) || (i==2 && j==0 && k==1)  ){
						tensor[i][j][k] = 1.0;
					}
					else{
						tensor[i][j][k] = -1.0;
					}	
				}
			}
		}
	}
	return;
}


void mostrarvector( double vector[] ){
	int i;
	for( i = 0; i < 3; ++i ){
		printf("\n%lf\n", vector[i]);
	}
	printf("\n\n");
}


void productovectorial( double vec1[3], double vec2[3], double vec3[3], double tensor[3][3][3] ){
	int i,j,k;
	double suma;
	for(i=0;i<3;++i){
		suma = 0;
		for(j=0;j<3;++j){
			for(k=0;k<3;++k){
				suma = suma + tensor[i][j][k]*vec1[j]*vec2[k];
			}
		}
		vec3[i] = suma;
		suma = 0;
	}
	return;
}
