#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1024

typedef struct dadosCSV {
    char matricula[10];
    char aluno[200];
    char anoColacao[6];
    char data[20];
    char anoIngresso[6];
    char periodo[3];
    char campus[30];
    char curso[30];
    char modalidade[30];
    char formaIngresso[30];
} dadosCSV;


struct dadosCSV cvsData[TAM];

void imprimir(struct dadosCSV cvsData[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d\t", cvsData[i].matricula);
        printf("%s\t", cvsData[i].aluno);
        printf("%d\t", cvsData[i].anoColacao);
        printf("%s\t", cvsData[i].data);
        printf("%s\t", cvsData[i].anoIngresso);
        printf("%s\t", cvsData[i].periodo);
        printf("%s\t", cvsData[i].campus);
        printf("%d\t", cvsData[i].curso);
        printf("%d\t", cvsData[i].modalidade);
        printf("%d\t", cvsData[i].formaIngresso);
        printf("\n");
    }
    printf("\n");
}

/* void insertionSort(struct dadosCSV *V, int N) {
    int i, j;
    struct dadosCSV aux;

    for (i = 1; i < N; i++) {
        aux = V[i];
        for (j = i; (j > 0) && (strcmp(aux.matricula, V[j - 1].matricula) < 0); j--)
            V[j] = V[j - 1];
        V[j] = aux;
    }
} */

int main() {
    setlocale(LC_ALL, "Portuguese");

    int tamanho = 117;
    int countLinhas = 0;
    int contador = 0, it = 0, linha = 0;

    char auxArquivo[TAM]; //FIXIT -> strVecTemp
    char buf[TAM]; //FIXIT -> strVec


    FILE *csv = fopen("dados.csv", "r");

    if (!csv) {
        perror("Nao foi possivel abrir o arquivo.");
        return EXIT_FAILURE;
    }

    while (fgets(buf, TAM, csv)) {
        contador = 0;
        countLinhas++;

        if (countLinhas <= 1) continue;

        char *field = strtok(buf, ";");
        while(field){
            if (contador == 0) {
                strcpy(cvsData[linha].matricula,field);
                
            }
            if (contador == 1) {
                strcpy(cvsData[linha].aluno,field);
            }
            if (contador == 2) {
                strcpy(cvsData[linha].anoColacao,field);
            }
            if (contador == 3) {
                strcpy(cvsData[linha].data,field);
            }
            if (contador == 4) {
                strcpy(cvsData[linha].anoIngresso,field);
            }
            if (contador == 5) {
                strcpy(cvsData[linha].periodo,field);
            }
            if (contador == 6) {
                strcpy(cvsData[linha].campus,field);
            }
            if (contador == 7) {
                strcpy(cvsData[linha].curso,field);
            }
            if (contador == 8) {
                strcpy(cvsData[linha].modalidade,field);
            }
            if (contador == 9) {
                strcpy(cvsData[linha].formaIngresso,field);
            }

            field = strtok(NULL,";");
            contador++;
        }
        }

        linha++; 
    
    
    fclose(csv);
    return 0;



    /* printf("Dados originais\n");
    printf("matricula   aluno   anoColacao   data   anoIngresso   periodo   campus   curso\n");
    imprimir(cvsData, tamanho);

    //insertionSort(cvsData, tamanho);

    printf("Dados ordenados\n");
    printf("matricula   aluno   anoColacao   data   anoIngresso   periodo   campus   curso\n");
    imprimir(cvsData, tamanho);
 */
}