#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void obterDados(char *buff);

int main(void){
    setlocale(LC_ALL, "Portuguese");

    FILE* fp = fopen("dados.csv", "r");

    if (!fp)    {
        perror("Nao foi possivel abrir o arquivo.");
        return EXIT_FAILURE;
    }


    fclose(fp);

    return 0;
}
}