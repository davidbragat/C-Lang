#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maximo 10

int tam = 0;
int grafo[maximo];
int ma[maximo][maximo];

int grafo_tamanho();
void inserir_aresta();

void main(){
setlocale(LC_ALL, "Portuguese");

    grafo_tamanho();
    inserir_aresta();

}

//define the number of vertices
int grafo_tamanho(){
    printf("Quantidade de vértices do grafo: ");
    scanf("%d", &tam);
    return tam;
}

void inserir_aresta(){
    int div, conv;
    system("cls");
    printf("Escolha o vértice de origem entre 0 e %d:", tam-1);
    scanf("%d", &div);
    printf("Escolha o vértice de destino entre 0 e %d:", tam-1);
    scanf("%d", &conv);

    if(div < 0 || div > tam-1 || conv < 0 || conv > tam - 1){
        printf("Valor inserido está fora do intervalo permitido\n");
        printf("O valor deve estar entre 0 e %d", tam-1);
        system("pause");
    }
    else{
        ma[div][conv] = 1;
        ma[conv][div] = 1;
    }
}

void remover_aresta(){
    int div, conv;
    system("cls");
    printf("Escolha o vértice de origem entre 0 e %d:", tam-1);
    scanf("%d", &div);
    printf("Escolha o vértice de destino entre 0 e %d:", tam-1);
    scanf("%d", &conv);

    if(div < 0 || div > tam-1 || conv < 0 || conv > tam - 1){
        printf("Valor inserido está fora do intervalo permitido\n");
        printf("O valor deve estar entre 0 e %d", tam-1);
        system("pause");
    }
    else{
        ma[div][conv] = 0;
        ma[conv][div] = 0;
    }
}

void print_vetor(){
    for (int i = 0; i < tam; i++){
        printf("%d, ", grafo[i]);
    }
}

void print_ma(){
    printf("Matriz de adjacências\n[");
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            printf("%d", ma[i][j]);
        }
        printf("\n");
    }
    printf("]");
    
}
