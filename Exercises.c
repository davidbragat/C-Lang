//Page 19 - Data Structure I
#include <stdio.h>
#include <stdlib.h>
int xi; 
int *ptr_xi; //ponteiro
float xf;
float *ptr_xf; // ponteiro
char xc;
char *ptr_xc;


void imprimir(){
    printf("Valor de xi = %d \n", xi);
    printf("Valor de &xi = %p \n", &xi);
    printf("Valor de ptr_xi = %p \n", ptr_xi);
    printf("Valor de *ptr_xi = %d \n\n", *ptr_xi);
    printf("David, you take it\n");
}

int main(){
    xi  = 15;
    ptr_xi = &xi;
    imprimir();
    system("Pause");
    return (0);
}