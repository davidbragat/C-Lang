#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1024

typedef struct dadosCSV {
    int matricula;
    char aluno[100];
    int anoColacao;
    char data[10];
    int anoIngresso;
    int periodo;
    char campus[10];
    char curso[30];
    char modalidade[30];
    char formaIngresso[30];
} dadosCSV;

struct dadosCSV cvsData[TAM];

void imprimir(struct dadosCSV cvsData[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", cvsData[i].matricula);
        printf("%s-30s\t", cvsData[i].aluno);
        printf("%d\t", cvsData[i].anoColacao);
        printf("%s\t", cvsData[i].data);
        printf("%d\t", cvsData[i].anoIngresso);
        printf("%d\t", cvsData[i].periodo);
        printf("%s\t", cvsData[i].campus);
        printf("%s\t", cvsData[i].curso);
        printf("%s\t", cvsData[i].modalidade);
        printf("%s\t", cvsData[i].formaIngresso);
        printf("\n");
    }
    printf("\n");
}

//HEADER Método de Ordenação - Selectionsort
void troca(struct dadosCSV* a, struct dadosCSV* b) {
    struct dadosCSV tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int selectionSort(struct dadosCSV vec[], int tam) {
    int i, j, min, qtd = 0;
    for (i = 0; i < (tam - 1); i++) {
        min = i;
        for (j = (i + 1); j < tam; j++) {
            if (vec[j].matricula < vec[min].matricula) {
                min = j;
            }
            qtd++;
        }
        if (i != min) {
            troca(&vec[i], &vec[min]);
        }
    }
    return (qtd);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tamanho;
    int countLinhas = 0;
    int contador = 0;
    int linha = 0;
    char buf[TAM];         //FIXIT -> strVec

    FILE *csv = fopen("dados.csv", "r");

    if (!csv) {
        perror("Nao foi possivel abrir o arquivo.");
        return EXIT_FAILURE;
    }

//HEADER MENU
    printf("Deseja imprimir quantas linhas?\n");
    scanf("%d", &tamanho);

    while (tamanho <= 0) {
        printf("Valor inválido.");
        scanf("%d", &tamanho);
    }


    while (fgets(buf, TAM, csv) && linha <= tamanho) {
        contador = 0;
        countLinhas++;

        if (countLinhas <= 1) continue;

        char *field = strtok(buf, ";");
        while (field) {
            if (contador == 0) {
                char* matricula = field;
                cvsData[linha].matricula = atoi(field);
            }
            if (contador == 1) {
                strcpy(cvsData[linha].aluno, field);
            }
            if (contador == 2) {
                char* anoColacao = field;
                cvsData[linha].anoColacao = atoi(field);
            }
            if (contador == 3) {
                strcpy(cvsData[linha].data, field);
            }
            if (contador == 4) {
                char* anoIngresso = field;
                cvsData[linha].anoIngresso = atoi(field);
            }
            if (contador == 5) {
                char* periodo = field;
                cvsData[linha].periodo = atoi(field);
            }
            if (contador == 6) {
                strcpy(cvsData[linha].campus, field);
            }
            if (contador == 7) {
                strcpy(cvsData[linha].curso, field);
            }
            if (contador == 8) {
                strcpy(cvsData[linha].modalidade, field);
            }
            if (contador == 9) {
                strcpy(cvsData[linha].formaIngresso, field);
            }

            field = strtok(NULL, ";");
            contador++;
        }
    linha++;

    }

    selectionSort(cvsData, tamanho);
    imprimir(cvsData, tamanho);

    fclose(csv);
    return 0;
}