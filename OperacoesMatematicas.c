#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Fun��o principal do programa
void main()
{

    //Definindo Variáveis
    setlocale(LC_ALL, "");
    int a, b;

    printf("Digite dois números inteiros \n");

    scanf("%d %d", a, b);

    //Soma
    printf("\n A soma de %d e %d = %d", a, b, a + b);
    //Subtração
    printf("\n A subtracao de %d e %d = %d", a, b, a - b);
    //Divisão
    printf("\n A divisao de %d e %d = %d", a, b, a / b);

    //Multiplicação
    printf("\n A multiplicacao de %d e %d = %d", a, b, a * b);

    //Resto da Divisão
    printf("\n O resto da divisao entre %d e %d = %d", a, b, a % b);

    //Valor Absoluto
    printf("\n O valor absoluto de -3 = %d", abs(-3));

    //Pausa o programa após executar
    system("pause");

//BUG 

}
