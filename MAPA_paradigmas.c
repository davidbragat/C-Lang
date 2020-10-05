#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Portuguese");

    int vecRa[5], i=0; //store the ra number (15119)
    vecRa[0] = 1;
    vecRa[1] = 5;
    vecRa[2] = 1;
    vecRa[3] = 1;
    vecRa[4] = 9;

    int vecKey[5]; //store the input number

    printf("============ COFRE ==========\n\n");

    do{
        system("cls");
        printf("\nDigite o %dº dígito da senha: ", i+1);
        scanf("%d", &vecKey[i]);

        if(vecRa[i] != vecKey[i]){
            printf("\nSequência Incorreta\n\n");
            printf("Tente novamente...\n\n\n");
            i = 0;
            system("pause");
        }else{
            i++;
        }
        
    }while (i<5);
    if (i == 5){
        printf("\n===========+++++++========\n");
        printf("Porta aberta\n");
        printf("===========+++++++========\n\n");
    }
}