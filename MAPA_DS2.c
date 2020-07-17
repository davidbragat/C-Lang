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
        printf("%-50s\t", cvsData[i].aluno);
        printf("%d\t", cvsData[i].anoColacao);
        printf("%s\t", cvsData[i].data);
        printf("%d\t", cvsData[i].anoIngresso);
        printf("  %d\t", cvsData[i].periodo);
        printf("%-7s\t", cvsData[i].campus);
        printf("%-25s\t", cvsData[i].curso);
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

    int size;
    int lineCounter = 0;
    int counter = 0;
    int line = 0;
    char strVec[TAM];

    FILE *csv = fopen("dados.csv", "r");

    if (!csv) {
        perror("Nao foi possivel abrir o arquivo.");
        return EXIT_FAILURE;
    }

//HEADER MENU
    printf("Deseja imprimir quantas linhas?\n");
    scanf("%d", &size);

    while (size <= 0) {
        printf("Valor inválido.");
        scanf("%d", &size);
    }


    while (fgets(strVec, TAM, csv) && line <= size) {
        counter = 0;
        lineCounter++;

        if (lineCounter <= 1) continue;

        char *field = strtok(strVec, ";");
        while (field) {
            if (counter == 0) {
                char* matricula = field;
                cvsData[line].matricula = atoi(field);
            }
            if (counter == 1) {
                strcpy(cvsData[line].aluno, field);
            }
            if (counter == 2) {
                char* anoColacao = field;
                cvsData[line].anoColacao = atoi(field);
            }
            if (counter == 3) {
                strcpy(cvsData[line].data, field);
            }
            if (counter == 4) {
                char* anoIngresso = field;
                cvsData[line].anoIngresso = atoi(field);
            }
            if (counter == 5) {
                char* periodo = field;
                cvsData[line].periodo = atoi(field);
            }
            if (counter == 6) {
                strcpy(cvsData[line].campus, field);
            }
            if (counter == 7) {
                strcpy(cvsData[line].curso, field);
            }
            if (counter == 8) {
                strcpy(cvsData[line].modalidade, field);
            }
            if (counter == 9) {
                strcpy(cvsData[line].formaIngresso, field);
            }

            field = strtok(NULL, ";");
            counter++;
        }
    line++;

    }

    selectionSort(cvsData, size);
    printf(" RA                 ALUNO                                     COLAÇÃO       DATA      INGRESSO   PER     CAMPUS         CURSO                  MODALIDADE    FORMA INGRESSO\n");
    imprimir(cvsData, size);

    fclose(csv);
    return 0;
}