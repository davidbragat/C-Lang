#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dadosArq {
    char Tipo[60];
    char Municipio[30];
    char UF[3];
    char Operador[60];
    char Numero_de_tanques[60];
    char Capacidade_nominal_petroleo[30];
    char Capacidade_nominal_derivados_biocombustiveis[30];
    char Capacidade_nominal_GLP[30];
} dadosArq;

struct dadosArq dados[117];

void imprimir(struct dadosArq dados[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\t", dados[i].Tipo);
        printf("%s\t", dados[i].Municipio);
        printf("%s\t", dados[i].UF);
        printf("%s\t", dados[i].Operador);
        printf("%s\t", dados[i].Numero_de_tanques);
        printf("%s\t", dados[i].Capacidade_nominal_petroleo);
        printf("%s\t", dados[i].Capacidade_nominal_derivados_biocombustiveis);
        printf("%d\t", dados[i].Capacidade_nominal_GLP);
        printf("\n");
    }
    printf("\n");
}

void insertionSort(struct dadosArq *V, int N) {
    int i, j;
    struct dadosArq aux;

    for (i = 1; i < N; i++) {
        aux = V[i];
        for (j = i; (j > 0) && (strcmp(aux.Tipo, V[j - 1].Tipo) < 0); j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tamanho = 117;
    int countLinhas = 0;
    int contador = 0, it = 0, linha = 0;

    char auxArquivo[1024];
    char buf[1024];

    FILE *arq = fopen("capacidade.csv", "r");

    if (arq == NULL)
        printf("Erro ao abrir arquivo");

    while (fgets(buf, 1024, arq)) {
        contador = 0;
        countLinhas++;

        if (countLinhas <= 0) continue;

        char *campo = strtok(buf, ";");
        while (campo) {
            if (contador == 0) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Tipo, auxArquivo);
            }

            if (contador == 1) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Municipio, auxArquivo);
            }

            if (contador == 2) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].UF, auxArquivo);
            }

            if (contador == 3) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Operador, auxArquivo);
            }

            if (contador == 4) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Numero_de_tanques, auxArquivo);
            }

            if (contador == 5) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Capacidade_nominal_petroleo, auxArquivo);
            }

            if (contador == 6) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Capacidade_nominal_derivados_biocombustiveis, auxArquivo);
            }

            if (contador == 7) {
                strcpy(auxArquivo, campo);
                strcpy(dados[linha].Capacidade_nominal_GLP, auxArquivo);
            }

            campo = strtok(NULL, ";");
            contador++;
        }
        linha++;
    }

    fclose(arq);

    printf("Dados originais\n");
    printf("Tipo   Municipio   UF   Operador   Numero_de_tanques   Capacidade_nominal_petroleo   Capacidade_nominal_derivados_biocombustiveis   Capacidade_nominal_GLP\n");
    imprimir(dados, tamanho);

    insertionSort(dados, tamanho);

    printf("Dados ordenados\n");
    printf("Tipo   Municipio   UF   Operador   Numero_de_tanques   Capacidade_nominal_petroleo   Capacidade_nominal_derivados_biocombustiveis   Capacidade_nominal_GLP\n");
    imprimir(dados, tamanho);
}