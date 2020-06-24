#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "Portuguese");

    int f, n;

    n = 1;

    while (n >= 0)
    {
    printf("\n\n===== Cálculo de Fatorial =====\n");
    printf("Digite um número: ");
    scanf("%d", &n);

        if (n == 0)
        {
            f = 1;
        }
        else
        {
            f = n;
            for (int i=1; i < n; i++){
                f= f * (n - i);
            }
        }
    
    printf("\n\nFatorial de %d é igual a %d", n, f);
    }
}