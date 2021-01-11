#include<stdio.h>
#include<stdlib.h>

void main(){

    int n = 2;

    int  i;

    float a[2] =  {5,2};

    float b[2] = {7,3};

    float producto_punto;

   for( i = 0 ; i  < n; i++){

        producto_punto += a[i]*b[i];

    }

    printf("producto punto es %f", producto_punto);

}
