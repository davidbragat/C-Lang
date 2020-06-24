#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<locale.h>

//Fun��o principal do programa
void main(){

setlocale(LC_ALL,"");
/* 
    char palavra[10];

    //Instru��o
    printf("Digite uma palavra");

    //Limpa o Buffer
    setbuf(stdin, 0);

    //L� a String
    fgets(palavra, 255, stdin);

    //Limpa as casas n�o utilizadas
    palavra[strlen(palavra)-1] = '\0';

    //Imprime na tela
    printf("%s", palavra); */

char st[40] = "DAVID";
int i;
for (i=0;st[i];i++){
    st[i] = tolower(st[i]);
}

printf("DAVID, passará para minúscula ...\n", st);
printf("%s \n");


    //Pausa o programa ap�s executar
    system("pause");

}

