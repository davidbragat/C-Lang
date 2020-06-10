//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> // Linhas 1 a 4 Inclus�o de bibliotecas necess�rias para o funcionamento do programa. 

//Constantes
#define tamanho 5 // Linhas 6 e 7 Defini��o de constante para o tamanho da pilha.

//Estrutura da Pilha Linhas 9 a 14
//Registro de estrutura para criar o �tipo pilha� contando com um vetor para armazena os dados e dois n�meros inteiros para controlar o in�cio e fim da pilha
struct tpilha {
int dados[tamanho];
int ini;
int fim;
};

//Vari�veis globais. Linhas 16 a 18 Deini��es de vari�veis
struct tpilha pilha;
int op;

//Protipa��o. Linhas 20 a 24 Prototipa��o das fun��es. Para mais detalhes sobre prototipa��o, consulte o livro de Algoritmos e L�gica de Programa��o II.
void pilha_entrar();
void pilha_sair();
void pilha_mostrar();
void menu_mostrar();
//Fun��o principal. Linhas 26 a 47 Fun��o principal (main), a primeira que ser� invocada na execu��o do programa.
int main(){
setlocale(LC_ALL, "Portuguese"); //Linha 28 Chamada de fun��o para conigurar o idioma para portugu�s, permitindo o uso de acentos (n�o funciona em todas as vers�es do Windows).
op = 1; // Linhas 29 a 31 Inicializa��o das vari�veis.
pilha.ini = 0;
pilha.fim = 0;
while (op != 0) { // Linhas 32 a 45 La�o principal, que ser� executado repetidamente at� que o usu�rio decida finalizar o programa.
system("cls"); // Linha 33 Chamada de comando no sistema operacional para limpar a tela.
pilha_mostrar(); // Linha 34 Chamada da fun��o que mostra o conte�do da Pilha na tela.
menu_mostrar(); // Linha 35 Chamada da fun��o que desenha o menu de op��es.
scanf("%d", &op); // Linha 36 L� a op��o escolhida pelo usu�rio.
switch (op) { // Linhas 37 a 44 Desvio condicional, que faz chamada de acordo com a op��o escolhida pelo usu�rio.
case 1:
pilha_entrar();
break ;
case 2:
pilha_sair();
break;
}
}
return(0);
}
//Adicionar um elemento no final da Pilha.  Linhas 49 a 60 Fun��o pilha_entrar(), que faz checagem do topo da pilha e insere novos valores no vetor dados.
void pilha_entrar(){
if (pilha.fim == tamanho) {
printf("\nA pilha est� cheia, imposs�vel empilhar!\n\n");
system("pause");
}
else {
printf("\nDigite o valor a ser empilhado: ");
scanf("%d", &pilha.dados[pilha.fim]);
pilha.fim++;
}
}

//Retirar o �ltimo elemento da Pilha
void pilha_sair() { // Linhas 62 a 72 Fun��o pilha_sair(), que veriica se existem elementos na pilha e remove o �ltimo inserido.
if (pilha.ini == pilha.fim)
 {
printf("\nA pilha est� vazia, imposs�vel desempilhar!\n\n");
system("pause");
}
else {
pilha.dados[pilha.fim-1] = 0;
pilha.fim--;
}
}

//Mostrar o conte�do da Pilha. Linhas 74 a 82 Fun��o pilha_mostrar(), que l� o conte�do e desenha o vetor dados na tela.
void pilha_mostrar() {
int i;
printf("[ ");
for (i = 0; i < tamanho; i++) {
printf("%d ", pilha.dados[i]);
}
printf("]\n\n");
}

//Mostrar o menu de op��es. Linhas 84 a 90 Fun��o menu_mostrar(), que desenha na tela as op��es permitidas para o usu�rio.
void menu_mostrar() {
	printf("1 - Empilhar\n");
printf("2 - Desempilhar\n");
printf("0 - Sair\n\n");
}
