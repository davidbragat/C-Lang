#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define maximo 10

//Variables
int tam = 0;
int grafo[maximo];
int ma[maximo][maximo];
int option;

//Prototypes
void menu();
int grafo_tamanho();
void inserir_aresta();
void remover_aresta();
void print_vetor();
void print_ma();

void main(){
setlocale(LC_ALL, "Portuguese");

    do{
        menu();
        scanf("%d", &option);
        switch (option){
        case 1:
            grafo_tamanho();
            break;

        case 2:
            inserir_aresta();
            break;
        
        case 3: 
            remover_aresta();
            break;
        
        case 4: 
            print_vetor();
            break;
        
        case 5: 
            print_ma();
            break;

        default:
            break;
        }
    } while (option != 0);

}//END MAIN FUNCTION

void menu(){
    system("cls");
    printf("Selecione uma das op��es\n");
    printf("1. Criar Grafo\n");
    printf("2. Inserir Aresta\n");
    printf("3. Remover Aresta\n");
    printf("4. Imprimir Vetor\n");
    printf("5. Imprimir Matriz\n");

    printf("0. Sair\n");

}

//define the number of vertices
int grafo_tamanho(){
    printf("Quantidade de v�rtices do grafo: ");
    scanf("%d", &tam);
    return tam;
}

void inserir_aresta(){
    int div, conv;
    system("cls");
    printf("Escolha o v�rtice de origem entre 0 e %d:", tam-1);
    scanf("%d", &div);
    printf("Escolha o v�rtice de destino entre 0 e %d:", tam-1);
    scanf("%d", &conv);

    if(div < 0 || div > tam-1 || conv < 0 || conv > tam - 1){
        printf("Valor inserido est� fora do intervalo permitido\n");
        printf("O valor deve estar entre 0 e %d\n", tam-1);
        system("pause");
        inserir_aresta();
    }
    else{
        ma[div][conv] = 1;
        ma[conv][div] = 1;
    }
}

void remover_aresta(){
    int div, conv;
    system("cls");
    printf("Escolha o v�rtice de origem entre 0 e %d:", tam-1);
    scanf("%d", &div);
    printf("Escolha o v�rtice de destino entre 0 e %d:", tam-1);
    scanf("%d", &conv);

    if(div < 0 || div > tam-1 || conv < 0 || conv > tam - 1){
        printf("Valor inserido est� fora do intervalo permitido\n");
        printf("O valor deve estar entre 0 e %d\n", tam-1);
        system("pause");
        remover_aresta();
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
    system("\npause");
}

void print_ma(){
    printf("Matriz de adjac�ncias\n");
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam; j++){
            printf("%d ", ma[i][j]);
        }
        printf("\n");
    }
    
    system("\npause");
}